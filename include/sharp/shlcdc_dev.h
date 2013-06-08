#ifndef __SHLCDC_DEV_
#define __SHLCDC_DEV_

#define SH_SUBLCD_DEVNAME "shlcdc_sub"
struct shlcdc_platform_data {
	int (*setup)(struct device *);
	void (*teardown)(struct device *);
	int gpio_rst;
};


#endif /* ifndef __SHDISP_TEST__*/
