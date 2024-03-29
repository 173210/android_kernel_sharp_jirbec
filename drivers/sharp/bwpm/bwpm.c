/* drivers/sharp/bwpm/bwpm.c  (BT/WiFi Power Management)
 *
 * Copyright (C) 2009 SHARP CORPORATION
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <mach/vreg.h>
#include <mach/pmic.h>

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Definition

 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#define _BWPM_NAME_	"bwpm"

#define disp_err( format, args... ) \
	printk( KERN_ERR "[%s] " format, _BWPM_NAME_ , ##args )
#define disp_war( format, args... ) \
	printk( KERN_WARNING "[%s] " format, _BWPM_NAME_ , ##args )

#ifdef BWPM_DEBUG
  #define disp_inf( format, args... ) \
	printk( KERN_ERR "[%s] " format, _BWPM_NAME_ , ##args )
  #define disp_dbg( format, args... ) \
	printk( KERN_ERR "[%s] " format, _BWPM_NAME_ , ##args )
  #define disp_trc( format, args... ) \
	printk( KERN_ERR "[%s] trace:%s " format, _BWPM_NAME_ , __func__ , ##args )
#else
  #define disp_inf( format, args... ) 
  #define disp_dbg( format, args... ) 
  #define disp_trc( format, args... )
#endif /* BWPM_DEBUG */

/* private data */
typedef struct {
    int fm;                                     /* fm ON/OFF */
	int bluetooth;								/* power status of bluetooth */
	int wifi;									/* power status of WiFi */
    /* [Sharp] ShDiag WiFi High Speed Support Start */
	int wifi_shdiag_stat;                                /* WiFi Stat Flag  SHDiag Start:1 Normal Start:0 */
    /* [Sharp] ShDiag WiFi High Speed Support  End  */
	struct vreg *vreg_bt;						/* regulator handle */
	struct vreg *vreg_wl;						/* regulator handle for wlan */
} bwpm_data_t;

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Configuration

 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/* GPIO mapping for Wireless LAN device */
#define BWPM_PORT_RF_LNA_EN			105			/* RF/WLAN_IO-3.0V */
#define BWPM_PORT_WL_RESET_N		 86			/* WLAN Reset */
#ifdef SUPPORT_UARTSEL
  #define BWPM_PORT_BT_UARTSEL		131			/* UART Selector */
#endif
#define BWPM_PORT_BT_RESET_N		108			/* Bluetooth Reset */
//#define BWPM_PORT_WL_1P8V_EN		156			/* 1.8V Regurator Enable */

/* Regulator Output Voltage */
#define BWPM_VREG_L13_LEVEL			2900		/* mV */
#define BWPM_VREG_L19_LEVEL			1800		/* mV */

#define BWPM_LP_BT_PMIC_ID			PM_VREG_LP_WLAN_ID

/* Port Configuration Table */
static unsigned bwpm_gpio_config[] = {
	/*        gpio,                  func, dir,          pull,        drvstr */
	GPIO_CFG( BWPM_PORT_RF_LNA_EN,  0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_6MA),
	GPIO_CFG( BWPM_PORT_WL_RESET_N, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_6MA),
#ifdef SUPPORT_UARTSEL
	GPIO_CFG( BWPM_PORT_BT_UARTSEL, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_6MA),
#endif
	GPIO_CFG( BWPM_PORT_BT_RESET_N, 0, GPIO_CFG_OUTPUT, GPIO_CFG_NO_PULL, GPIO_CFG_6MA),
//	GPIO_CFG( BWPM_PORT_WL_1P8V_EN, 0, GPIO_OUTPUT, GPIO_NO_PULL, GPIO_2MA)
};

#ifndef BWPM_INI_BT
  #define BWPM_INI_BT 0
#endif

#ifndef BWPM_INI_WL
  #define BWPM_INI_WL 0
#endif

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Resource

 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
struct platform_device *p_bwpm_dev = NULL;

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Local

 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
static int bwpm_reset( struct device *pdev )
{
	bwpm_data_t *p_sts;
	int ret;

	if ( pdev == NULL ){
		disp_err( "device not found\n" );
		return -1;
	}

	p_sts = (bwpm_data_t *)dev_get_drvdata(pdev);
	if ( p_sts == NULL ){
		disp_err( "driver infomation not found\n" );
		return -1;
	}

	gpio_set_value( BWPM_PORT_BT_RESET_N, 0 );
	/* BC7 is always turned on */
	ret = vreg_enable( p_sts->vreg_bt );                /* Turn ON BT-3.3V */
    msleep(10);                                         /* wait for 10msec */
	gpio_set_value( BWPM_PORT_BT_RESET_N, 1 );          /* SYSRST */
    /* WLAN OFF */
	gpio_set_value( BWPM_PORT_WL_RESET_N, 0 );			/* WLAN_RST */
//	gpio_set_value( BWPM_PORT_WL_1P8V_EN, 0 );			/* WLAN_VREG_EN */
	msleep(1);                                          /* over 200 micro seconds */
    /* RF OFF -Low power mode- */
	pmic_lp_mode_control( ON_CMD, BWPM_LP_BT_PMIC_ID );  /* Low power mode */
	gpio_set_value( BWPM_PORT_RF_LNA_EN, 0 );           /* WLAN_VDD_PA_LNA_EN */

#ifdef SUPPORT_UARTSEL
	gpio_set_value( BWPM_PORT_BT_UARTSEL, 1 );
#endif

    /* init status */
	p_sts->fm          = 0;
	p_sts->bluetooth   = 0;
	p_sts->wifi        = 0;

    /* [Sharp] ShDiag WiFi High Speed Support Start */
	p_sts->wifi_shdiag_stat     = 0;       /* WiFi Stat Flag  Init */
    /* [Sharp] ShDiag WiFi High Speed Support  End  */


	return 0;
}

static int bwpm_fm_on( struct device *pdev , int on )
{
	bwpm_data_t *p_sts;
    
	if ( pdev == NULL ){
		disp_err( "device not found\n" );
		return( -1 );
	}
	p_sts = (bwpm_data_t *)dev_get_drvdata(pdev);
	if ( p_sts == NULL ){
		disp_err( "driver infomation not found\n" );
		return -1;
	}
	if ( p_sts->fm == on ){
		disp_dbg( "%s: no need to change status (%d->%d)\n" , __func__, p_sts->fm , on );
		return 0;
	}

	if ( on ){
#if 0   /* 2010/08/20 GPIO 6mA Support*/
		/* Turn ON RF/WLAN_IO-3.0V */
		if( ( p_sts->wifi <= 0 ) && ( p_sts->bluetooth <= 0 ) ){
			gpio_set_value( BWPM_PORT_RF_LNA_EN, 1 );		    /* WLAN_VDD_PA_LNA_EN */
    		disp_dbg( "%s: RF ON\n" , __func__);
			/* BC7 is always turned on */
		}
#endif
		if( p_sts->bluetooth <= 0 ){
        	pmic_lp_mode_control( OFF_CMD, BWPM_LP_BT_PMIC_ID );  /* Normal power mode */
    		disp_dbg( "%s: Normal-Power-mode\n" , __func__);
		}
	} else {
        if( p_sts->bluetooth <= 0 ){
			pmic_lp_mode_control( ON_CMD, BWPM_LP_BT_PMIC_ID ); /* Low power mode */
      	    disp_dbg( "%s: Low-Power-mode\n" , __func__);
        }
#if 0   /* 2010/08/20 GPIO 6mA Support*/
		if( ( p_sts->wifi <= 0 ) && ( p_sts->bluetooth <= 0 ) ){
			/* BC7 is always turned on */
			gpio_set_value( BWPM_PORT_RF_LNA_EN, 0 );		    /* WLAN_VDD_PA_LNA_EN */
    		disp_dbg( "%s: RF OFF\n" , __func__);
		}
#endif
	}

	if ( p_sts->fm < 0 ){
		disp_inf( "fm power on reset\n" );
	} else {
		disp_dbg( "%s: change status (%d->%d)\n" , __func__, p_sts->fm , on );
	}
    p_sts->fm = on;

    return( 0 );
}

static int bwpm_bluetooth_on( struct device *pdev , int on )
{
	bwpm_data_t *p_sts;

	if ( pdev == NULL ){
		disp_err( "device not found\n" );
		return -1;
	}

	p_sts = (bwpm_data_t *)dev_get_drvdata(pdev);
	if ( p_sts == NULL ){
		disp_err( "driver infomation not found\n" );
		return -1;
	}

	if ( p_sts->bluetooth == on ){
		disp_dbg( "%s: no need to change status (%d->%d)\n" , __func__, p_sts->bluetooth , on );
		return 0;
	}

	if ( on ){
		/* Turn ON RF/WLAN_IO-3.0V */
		if( p_sts->wifi <= 0 ){
			gpio_set_value( BWPM_PORT_RF_LNA_EN, 1 );		    /* WLAN_VDD_PA_LNA_EN */
    		disp_dbg( "%s: RF ON\n" , __func__);
			/* BC7 is always turned on */
		}
		if( p_sts->fm <= 0 ){
        	pmic_lp_mode_control( OFF_CMD, BWPM_LP_BT_PMIC_ID );  /* Normal power mode */
    		disp_dbg( "%s: Normal-Power-mode\n" , __func__);
		}
	} else {
        if( p_sts->fm <= 0 ){
			pmic_lp_mode_control( ON_CMD, BWPM_LP_BT_PMIC_ID ); /* Low power mode */
      	    disp_dbg( "%s: Low-Power-mode\n" , __func__);
        }
		if( p_sts->wifi <= 0 ){
			/* BC7 is always turned on */
			gpio_set_value( BWPM_PORT_RF_LNA_EN, 0 );		    /* WLAN_VDD_PA_LNA_EN */
    		disp_dbg( "%s: RF OFF\n" , __func__);
		}
	}

	if ( p_sts->bluetooth < 0 ){
		disp_inf( "Bluetooth power on reset\n" );
	} else {
		disp_dbg( "%s: change status (%d->%d)\n" , __func__, p_sts->bluetooth , on );
	}
	p_sts->bluetooth = on;

	return 0;
}

#if 1 /* Customize for Bluetooth */
static int bwpm_bluetooth_reset( struct device *pdev , int on )
{
	bwpm_data_t *p_sts;

	if ( pdev == NULL ){
		disp_err( "device not found\n" );
		return -1;
	}

	p_sts = (bwpm_data_t *)dev_get_drvdata(pdev);
	if ( p_sts == NULL ){
		disp_err( "driver infomation not found\n" );
		return -1;
	}

	gpio_set_value( BWPM_PORT_BT_RESET_N, 0 );

	return 0;
}
#endif /* Customize for Bluetooth */

static int bwpm_wifi_on( struct device *pdev , int on )
{
	bwpm_data_t *p_sts;
	int ret;

	if ( pdev == NULL ){
		disp_err( "device not found\n" );
		return -1;
	}

	p_sts = (bwpm_data_t *)dev_get_drvdata(pdev);
	if ( p_sts == NULL ){
		disp_err( "driver infomation not found\n" );
		return -1;
	}

	if ( p_sts->wifi == on ){
		disp_dbg( "%s: no need to change status (%d->%d)\n" , __func__, p_sts->wifi , on );
		return 0;
	}

	if ( on ){
		/* Turn ON RF/WLAN_IO-3.0V */
		if( p_sts->bluetooth <= 0 ){
			gpio_set_value( BWPM_PORT_RF_LNA_EN, 1 );		/* WLAN_VDD_PA_LNA_EN */
    		disp_dbg( "%s: RF ON\n" , __func__);
			msleep(1);                                      /* over 200 micro seconds */
		}

		/* PM8058_VREG_L19 => ON at here*/
		ret = vreg_enable( p_sts->vreg_wl );                /* Turn ON WL-1.8V */

//		gpio_set_value( BWPM_PORT_WL_1P8V_EN, 1 );			/* WLAN_VREG_EN */
		msleep(5);

		gpio_set_value( BWPM_PORT_WL_RESET_N, 1 );			/* WLAN_RST */
	} else {

		gpio_set_value( BWPM_PORT_WL_RESET_N, 0 );			/* WLAN_RST */

/* [WLAN][SHARP] 2010.12.27 mod Start */
#if 1 
		msleep(5);                                          /* over 1.5ms */
#endif
/* [WLAN][SHARP] 2010.12.27 mod End */

		/* PM8058_VREG_L19 => OFF at here */
		ret = vreg_disable( p_sts->vreg_wl );                /* Turn OFF WL-1.8V */

//		gpio_set_value( BWPM_PORT_WL_1P8V_EN, 0 );			/* WLAN_VREG_EN */

		if( p_sts->bluetooth <= 0 ){
			msleep(1);                                      /* over 200 micro seconds */
			gpio_set_value( BWPM_PORT_RF_LNA_EN, 0 );		/* WLAN_VDD_PA_LNA_EN */
    		disp_dbg( "%s: RF OFF\n" , __func__);
		}
	}

	if ( p_sts->wifi < 0 ){
		disp_inf( "WiFi power on reset\n" );
	} else {
		disp_dbg( "%s: change status (%d->%d)\n" , __func__, p_sts->wifi , on );
	}
	p_sts->wifi = on;

	return 0;
}

/* Customize for Bluetooth Power OFF sequence */
static int bwpm_power_off( struct device *pdev )
{
	bwpm_data_t *p_sts;

	if ( pdev == NULL ){
		disp_err( "device not found\n" );
		return -1;
	}
	p_sts = (bwpm_data_t *)dev_get_drvdata(pdev);
	if ( p_sts == NULL ){
		disp_err( "driver infomation not found\n" );
		return -1;
	}

	pmic_lp_mode_control( ON_CMD, BWPM_LP_BT_PMIC_ID ); /* Low power mode */
	gpio_set_value( BWPM_PORT_RF_LNA_EN, 0 );           /* WLAN_VDD_PA_LNA_EN */

#ifdef SUPPORT_UARTSEL
	gpio_set_value( BWPM_PORT_BT_UARTSEL, 0 );
#endif

	gpio_set_value( BWPM_PORT_BT_RESET_N, 1 );          /* Bluetooth Reset */
	gpio_set_value( BWPM_PORT_BT_RESET_N, 0 );

	msleep(10);                                         /* wait for 10msec */

	vreg_disable( p_sts->vreg_bt );                     /* Turn OFF BT-3.3V */

	return 0;
}
/* Customize for Bluetooth Power OFF sequence */

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Device attribute

 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
static
ssize_t show_fm_power(struct device *pdev, struct device_attribute *pattr, char *buf)
{
	bwpm_data_t *p_priv = (bwpm_data_t *)dev_get_drvdata(pdev);

	buf[0] = (char)(p_priv->fm);
	
	return( 1 );
}

static
ssize_t set_fm_power(struct device *pdev, struct device_attribute *pattr, const char *buf, size_t count)
{
	if ( (buf[0]==0) || (buf[0]==1) ){
		bwpm_fm_on( pdev, (int)buf[0] );
        return( count );
	}

	return( 0 );
}

static
ssize_t show_bluetooth_power(struct device *pdev, struct device_attribute *pattr, char *buf)
{
	bwpm_data_t *p_priv = (bwpm_data_t *)dev_get_drvdata(pdev);

	buf[0] = (char)(p_priv->bluetooth);
	
	return( 1 );
}

static
ssize_t set_bluetooth_power(struct device *pdev, struct device_attribute *pattr, const char *buf, size_t count)
{
	if ( (buf[0]==0) || (buf[0]==1) ){
		bwpm_bluetooth_on( pdev, (int)buf[0] );
        return( count );
	}
#if 1 /* Customize for Bluetooth */
    else if ( (buf[0]==9) ){
		bwpm_bluetooth_reset( pdev, (int)buf[0] );
        return( count );
    }
#endif /* Customize for Bluetooth */

	return( 0 );
}

static
ssize_t show_wifi_power(struct device *pdev, struct device_attribute *pattr, char *buf)
{
	bwpm_data_t *p_priv = (bwpm_data_t *)dev_get_drvdata(pdev);
	int status;

	status = p_priv->wifi;
	
	return snprintf( buf, PAGE_SIZE, "%d\n" , status );
}

static
ssize_t set_wifi_power(struct device *pdev, struct device_attribute *pattr, const char *buf, size_t count)
{
	int new_status;

//	sscanf( buf, "%d", &new_status );
	sscanf( buf, "%1d", &new_status );     /* secutity Countermeasure */

	if ( (new_status==0) || (new_status==1) ){
		bwpm_wifi_on( pdev, new_status );
	}

	return count;
}

/* [Sharp] ShDiag WiFi High Speed Support Start */
/* WiFi Stat Flag  Device Read */
static
ssize_t show_wifi_shdiag_stat(struct device *pdev, struct device_attribute *pattr, char *buf)
{
	bwpm_data_t *p_priv = (bwpm_data_t *)dev_get_drvdata(pdev);
	int status;

	status = p_priv->wifi_shdiag_stat;
	
	return snprintf( buf, PAGE_SIZE, "%d\n" , status );
	
}

/* WiFi Stat Flag  Device Write */
static
ssize_t set_wifi_shdiag_stat(struct device *pdev, struct device_attribute *pattr, const char *buf, size_t count)
{
	bwpm_data_t *p_priv = (bwpm_data_t *)dev_get_drvdata(pdev);
	int new_status;

//	sscanf( buf, "%d", &new_status );
	sscanf( buf, "%1d", &new_status );     /* secutity Countermeasure */

	if ( (new_status==0) || (new_status==1) ){
		p_priv->wifi_shdiag_stat = new_status;
	}

	return count;

}
/* [Sharp] ShDiag WiFi High Speed Support  End */


/* device attribute structure */
static DEVICE_ATTR(
	fm,
	S_IRUGO | S_IWUGO,
	show_fm_power,
	set_fm_power
);

static DEVICE_ATTR(
	bluetooth,
	S_IRUGO | S_IWUGO,			/* R/W user/group/other */
	show_bluetooth_power,		/* read */
	set_bluetooth_power			/* write */
);

static DEVICE_ATTR(
	wifi,
	S_IRUGO | S_IWUGO,
	show_wifi_power,
	set_wifi_power
);

/* [Sharp] ShDiag WiFi High Speed Support Start */
/* WiFi Stat Flag  Device Setting */
static DEVICE_ATTR(
	wifi_shdiag_stat,
	S_IRUGO | S_IWUGO,
	show_wifi_shdiag_stat,
	set_wifi_shdiag_stat
);
/* [Sharp] ShDiag WiFi High Speed Support  End  */


static struct attribute *bwpm_device_attributes[] = {
	&dev_attr_fm.attr,
	&dev_attr_bluetooth.attr,
	&dev_attr_wifi.attr,
/* [Sharp] ShDiag WiFi High Speed Support Start */
	&dev_attr_wifi_shdiag_stat.attr,
/* [Sharp] ShDiag WiFi High Speed Support  End  */
	NULL,
};

static struct attribute_group bwpm_device_attributes_gourp = {
	.attrs = bwpm_device_attributes,
};

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Driver Description

 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
static int __init bwpm_driver_probe( struct platform_device *pdev )
{
	int pin;
	int ret;
	struct vreg *vreg_bt;
	struct vreg *vreg_wl;
	bwpm_data_t *p_priv;

    int ini;

	/* Port Configuration */
	for (pin = 0; pin < ARRAY_SIZE(bwpm_gpio_config); pin++) {
		ret = gpio_tlmm_config( bwpm_gpio_config[pin], GPIO_CFG_ENABLE );
		if (ret) {
			disp_err( "gpio_tlmm_config(%d)<-%#x : %d\n", pin,bwpm_gpio_config[pin], ret);
			return -EIO;
		}
	}

	/* Regurator Configuration for BT */
	vreg_bt = vreg_get(NULL, "wlan");
	if (IS_ERR(vreg_bt)) {
		disp_err( "vreg get failed (%ld)\n", PTR_ERR(vreg_bt) );
		return PTR_ERR(vreg_bt);
	}
	ret = vreg_set_level( vreg_bt, BWPM_VREG_L13_LEVEL );
	if ( ret ) {
		disp_err( "vreg set level failed (%d)\n", ret) ;
		return -EIO;
	}

	/* Regurator Configration for wlan */
	vreg_wl = vreg_get(NULL, "wlan2");
	if (IS_ERR(vreg_wl)) {
		disp_err( "vreg get for wlan failed (%ld)\n", PTR_ERR(vreg_wl) );
		return PTR_ERR(vreg_wl);
	}
	ret = vreg_set_level( vreg_wl, BWPM_VREG_L19_LEVEL );
	if ( ret ) {
		disp_err( "vreg set level for wlan failed (%d)\n", ret) ;
		return -EIO;
	}

	/* Initialize private data */
	p_priv = kmalloc( sizeof(*p_priv) , GFP_KERNEL );
	if ( p_priv == NULL ){
		disp_err( "memory allocation for private data failed\n" );
		return -ENOMEM;
	}
	p_priv->vreg_bt = vreg_bt;
	p_priv->vreg_wl = vreg_wl;
	platform_set_drvdata( pdev , p_priv );

	/* power on reset */
    bwpm_reset( &(pdev->dev) );

	/* power on */
	ini = BWPM_INI_FM;
	if ( ini ){
		bwpm_fm_on( &(pdev->dev) , 1 );
	}
	ini = BWPM_INI_BT;
	if ( ini ){
		bwpm_bluetooth_on( &(pdev->dev) , 1 );
	}
	ini = BWPM_INI_WL;
	if ( ini ){
		bwpm_wifi_on( &(pdev->dev) , 1 );
	}

	/* create sysfs interface */
	ret = sysfs_create_group( &(pdev->dev.kobj), &bwpm_device_attributes_gourp);
	if ( ret ){
		disp_err( "Sysfs attribute export failed with error %d.\n" , ret );
	}

	return ret;
}

static int bwpm_driver_remove( struct platform_device *pdev )
{
	bwpm_data_t *p_priv;

	sysfs_remove_group( &(pdev->dev.kobj), &bwpm_device_attributes_gourp);
	
	p_priv = platform_get_drvdata( pdev );
	platform_set_drvdata( pdev , NULL );
	if ( p_priv != NULL ){
		kfree( p_priv );
	}
	
	return 0;
}

/* Customize for Bluetooth Power OFF sequence */
static void bwpm_driver_shutdown( struct platform_device *pdev )
{

	bwpm_power_off( &(pdev->dev) );

	return;
}
/* Customize for Bluetooth Power OFF sequence */

/* driver structure */
static struct platform_driver bwpm_driver = {
	.remove = __devexit_p(bwpm_driver_remove),
	.shutdown = __devexit_p(bwpm_driver_shutdown),
	.driver = {
		.name = _BWPM_NAME_,
		.owner = THIS_MODULE,
	},
};

static int bwpm_driver_init( void )
{
	int ret;
	
	/* regist driver */
	ret = platform_driver_probe( &bwpm_driver, bwpm_driver_probe );
	if ( ret != 0 ){
		disp_err( "driver register failed (%d)\n" , ret );
	}

	return ret;
}

static void bwpm_driver_exit( void )
{
	platform_driver_unregister( &bwpm_driver );
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Device Description

 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
static int __init bwpm_device_init( void )
{
	int ret;
	
	/* allocate device structure */
	p_bwpm_dev = platform_device_alloc( _BWPM_NAME_ , -1 );
	if ( p_bwpm_dev == NULL ){
		disp_err( "device allocation failed\n" );
		return -ENOMEM;
	}

	/* regist device */
	ret = platform_device_add( p_bwpm_dev );
	if ( ret != 0 ){
		disp_err( "device register failed (%d)\n" , ret );
	}

	return ret;
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	Module Description

 *:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
static int bwpm_module_init( void )
{
	int ret;
	
	disp_inf( "Bluetooth/Wifi Power Management\n" );

	ret = bwpm_device_init();
	if ( ret == 0 ){
		ret = bwpm_driver_init();
	}

	return ret;
}

static void bwpm_module_exit( void )
{
	bwpm_driver_exit();
}


EXPORT_SYMBOL(bwpm_bluetooth_on);
EXPORT_SYMBOL(bwpm_wifi_on);

MODULE_DESCRIPTION("Bluetooth/WiFi Power Management");
MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("SHARP CORPORATION");
MODULE_VERSION("0.10");

module_init(bwpm_module_init);
module_exit(bwpm_module_exit);

