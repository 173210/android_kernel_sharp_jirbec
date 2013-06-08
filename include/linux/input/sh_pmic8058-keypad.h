/* include/linux/input/sh_pmic8058-keypad.h
 *
 * Copyright (C) 2011 SHARP CORPORATION
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

#ifndef __SH_PMIC8058_KEYPAD_H__
#define __SH_PMIC8058_KEYPAD_H__

#include <linux/input.h>

/*
 * NOTE: keymaps & param. of PMIC8058 chip.
 */
#ifdef CONFIG_KEYBOARD_SCKEY
#if defined(CONFIG_TENKEY_KEYPAD)

/* TENKEY key map */
#define KEY_ROW1_COL1	KEY_RESERVED
#define KEY_ROW1_COL2	KEY_SEND
#define KEY_ROW1_COL3	KEY_POUND
#define KEY_ROW1_COL4	KEY_RSK
#define KEY_ROW1_COL5	KEY_6
#define KEY_ROW1_COL6	KEY_RESERVED
#define KEY_ROW1_COL7	KEY_8
#define KEY_ROW1_COL8	KEY_4

#define KEY_ROW2_COL1	KEY_RESERVED
#define KEY_ROW2_COL2	KEY_HOME
#define KEY_ROW2_COL3	KEY_7
#define KEY_ROW2_COL4	KEY_9
#define KEY_ROW2_COL5	KEY_BACKSPACE
#define KEY_ROW2_COL6	KEY_SEARCH
#define KEY_ROW2_COL7	KEY_UP
#define KEY_ROW2_COL8	KEY_LEFT

#define KEY_ROW3_COL1	KEY_MENU
#define KEY_ROW3_COL2	KEY_3
#define KEY_ROW3_COL3	KEY_SAVE
#define KEY_ROW3_COL4	KEY_VOLUMEUP
#define KEY_ROW3_COL5	KEY_VOLUMEDOWN
#define KEY_ROW3_COL6	KEY_RESERVED
#define KEY_ROW3_COL7	KEY_FOCUS
#define KEY_ROW3_COL8	KEY_CAMERA

#define KEY_ROW4_COL1	KEY_RESERVED
#define KEY_ROW4_COL2	KEY_RESERVED
#define KEY_ROW4_COL3	KEY_5
#define KEY_ROW4_COL4	KEY_1
#define KEY_ROW4_COL5	KEY_0
#define KEY_ROW4_COL6	KEY_RESERVED
#define KEY_ROW4_COL7	KEY_DOWN
#define KEY_ROW4_COL8	KEY_RIGHT

#define KEY_ROW5_COL1	KEY_RESERVED
#define KEY_ROW5_COL2	KEY_ENTER
#define KEY_ROW5_COL3	KEY_BACK
#define KEY_ROW5_COL4	KEY_APP1
#define KEY_ROW5_COL5	KEY_LSK
#define KEY_ROW5_COL6	KEY_RESERVED
#define KEY_ROW5_COL7	KEY_STAR
#define KEY_ROW5_COL8	KEY_2

#define KEY_ROW6_COL1	KEY_RESERVED
#define KEY_ROW6_COL2	KEY_RESERVED
#define KEY_ROW6_COL3	KEY_RESERVED
#define KEY_ROW6_COL4	KEY_RESERVED
#define KEY_ROW6_COL5	KEY_RESERVED
#define KEY_ROW6_COL6	KEY_RESERVED
#define KEY_ROW6_COL7	KEY_RESERVED
#define KEY_ROW6_COL8	KEY_RESERVED

#define KEY_ROW7_COL1	KEY_RESERVED
#define KEY_ROW7_COL2	KEY_RESERVED
#define KEY_ROW7_COL3	KEY_RESERVED
#define KEY_ROW7_COL4	KEY_RESERVED
#define KEY_ROW7_COL5	KEY_RESERVED
#define KEY_ROW7_COL6	KEY_RESERVED
#define KEY_ROW7_COL7	KEY_RESERVED
#define KEY_ROW7_COL8	KEY_RESERVED

#define KEY_ROW8_COL1	KEY_RESERVED
#define KEY_ROW8_COL2	KEY_RESERVED
#define KEY_ROW8_COL3	KEY_RESERVED
#define KEY_ROW8_COL4	KEY_RESERVED
#define KEY_ROW8_COL5	KEY_RESERVED
#define KEY_ROW8_COL6	KEY_RESERVED
#define KEY_ROW8_COL7	KEY_RESERVED
#define KEY_ROW8_COL8	KEY_RESERVED

#define KEY_ROW9_COL1	KEY_RESERVED
#define KEY_ROW9_COL2	KEY_RESERVED
#define KEY_ROW9_COL3	KEY_RESERVED
#define KEY_ROW9_COL4	KEY_RESERVED
#define KEY_ROW9_COL5	KEY_RESERVED
#define KEY_ROW9_COL6	KEY_RESERVED
#define KEY_ROW9_COL7	KEY_RESERVED
#define KEY_ROW9_COL8	KEY_RESERVED

#define KEY_ROW10_COL1	KEY_RESERVED
#define KEY_ROW10_COL2	KEY_RESERVED
#define KEY_ROW10_COL3	KEY_RESERVED
#define KEY_ROW10_COL4	KEY_RESERVED
#define KEY_ROW10_COL5	KEY_RESERVED
#define KEY_ROW10_COL6	KEY_RESERVED
#define KEY_ROW10_COL7	KEY_RESERVED
#define KEY_ROW10_COL8	KEY_RESERVED

#define KEY_ROW11_COL1	KEY_RESERVED
#define KEY_ROW11_COL2	KEY_RESERVED
#define KEY_ROW11_COL3	KEY_RESERVED
#define KEY_ROW11_COL4	KEY_RESERVED
#define KEY_ROW11_COL5	KEY_RESERVED
#define KEY_ROW11_COL6	KEY_RESERVED
#define KEY_ROW11_COL7	KEY_RESERVED
#define KEY_ROW11_COL8	KEY_RESERVED

#define KEY_ROW12_COL1	KEY_RESERVED
#define KEY_ROW12_COL2	KEY_RESERVED
#define KEY_ROW12_COL3	KEY_RESERVED
#define KEY_ROW12_COL4	KEY_RESERVED
#define KEY_ROW12_COL5	KEY_RESERVED
#define KEY_ROW12_COL6	KEY_RESERVED
#define KEY_ROW12_COL7	KEY_RESERVED
#define KEY_ROW12_COL8	KEY_RESERVED

/* PM8058 chip param. */
#define SH_INPUT_NAME			"SH_tenkey-keypad"
#define SH_INPUT_PHYS_DEVICE	"SH_tenkey-keypad/input0"
#define SH_NUM_ROWS				6
#define SH_NUM_COLS				8
#define SH_ROWS_GPIO_START		8
#define SH_COLS_GPIO_START		0
#define SH_DEBOUNCE_MS0			8
#define SH_DEBOUNCE_MS1			10
#define SH_SCAN_DELAY_MS		32
#define SH_HOLD_NS				91500

#elif defined(CONFIG_TENKEY2_KEYPAD)

/* TENKEY2 key map */
#define KEY_ROW1_COL1	KEY_RESERVED
#define KEY_ROW1_COL2	KEY_SEND
#define KEY_ROW1_COL3	KEY_POUND
#define KEY_ROW1_COL4	KEY_RSK
#define KEY_ROW1_COL5	KEY_6
#define KEY_ROW1_COL6	KEY_RESERVED
#define KEY_ROW1_COL7	KEY_8
#define KEY_ROW1_COL8	KEY_4

#define KEY_ROW2_COL1	KEY_RESERVED
#define KEY_ROW2_COL2	KEY_HOME
#define KEY_ROW2_COL3	KEY_7
#define KEY_ROW2_COL4	KEY_9
#define KEY_ROW2_COL5	KEY_BACKSPACE
#define KEY_ROW2_COL6	KEY_SEARCH
#define KEY_ROW2_COL7	KEY_UP
#define KEY_ROW2_COL8	KEY_LEFT

#define KEY_ROW3_COL1	KEY_MENU
#define KEY_ROW3_COL2	KEY_3
#define KEY_ROW3_COL3	KEY_SAVE
#define KEY_ROW3_COL4	KEY_VOLUMEUP
#define KEY_ROW3_COL5	KEY_VOLUMEDOWN
#define KEY_ROW3_COL6	KEY_RESERVED
#define KEY_ROW3_COL7	KEY_FOCUS
#define KEY_ROW3_COL8	KEY_CAMERA

#define KEY_ROW4_COL1	KEY_RESERVED
#define KEY_ROW4_COL2	KEY_RESERVED
#define KEY_ROW4_COL3	KEY_5
#define KEY_ROW4_COL4	KEY_1
#define KEY_ROW4_COL5	KEY_0
#define KEY_ROW4_COL6	KEY_RESERVED
#define KEY_ROW4_COL7	KEY_DOWN
#define KEY_ROW4_COL8	KEY_RIGHT

#define KEY_ROW5_COL1	KEY_RESERVED
#define KEY_ROW5_COL2	KEY_ENTER
#define KEY_ROW5_COL3	KEY_BACK
#define KEY_ROW5_COL4	KEY_APP1
#define KEY_ROW5_COL5	KEY_LSK
#define KEY_ROW5_COL6	KEY_RESERVED
#define KEY_ROW5_COL7	KEY_STAR
#define KEY_ROW5_COL8	KEY_2

#define KEY_ROW6_COL1	KEY_RESERVED
/* #define KEY_ROW6_COL1	KEY_LEFTUP */
#define KEY_ROW6_COL2	KEY_RESERVED
/* #define KEY_ROW6_COL2	KEY_RIGHTUP */
#define KEY_ROW6_COL3	KEY_RESERVED
/* #define KEY_ROW6_COL3	KEY_RIGHTDOWN */
#define KEY_ROW6_COL4	KEY_RESERVED
/* #define KEY_ROW6_COL4	KEY_LEFTDOWN */
#define KEY_ROW6_COL5	KEY_RESERVED
#define KEY_ROW6_COL6	KEY_RESERVED
#define KEY_ROW6_COL7	KEY_RESERVED
#define KEY_ROW6_COL8	KEY_RESERVED

#define KEY_ROW7_COL1	KEY_RESERVED
#define KEY_ROW7_COL2	KEY_RESERVED
#define KEY_ROW7_COL3	KEY_RESERVED
#define KEY_ROW7_COL4	KEY_RESERVED
#define KEY_ROW7_COL5	KEY_RESERVED
#define KEY_ROW7_COL6	KEY_RESERVED
#define KEY_ROW7_COL7	KEY_RESERVED
#define KEY_ROW7_COL8	KEY_RESERVED

#define KEY_ROW8_COL1	KEY_RESERVED
#define KEY_ROW8_COL2	KEY_RESERVED
#define KEY_ROW8_COL3	KEY_RESERVED
#define KEY_ROW8_COL4	KEY_RESERVED
#define KEY_ROW8_COL5	KEY_RESERVED
#define KEY_ROW8_COL6	KEY_RESERVED
#define KEY_ROW8_COL7	KEY_RESERVED
#define KEY_ROW8_COL8	KEY_RESERVED

#define KEY_ROW9_COL1	KEY_RESERVED
#define KEY_ROW9_COL2	KEY_RESERVED
#define KEY_ROW9_COL3	KEY_RESERVED
#define KEY_ROW9_COL4	KEY_RESERVED
#define KEY_ROW9_COL5	KEY_RESERVED
#define KEY_ROW9_COL6	KEY_RESERVED
#define KEY_ROW9_COL7	KEY_RESERVED
#define KEY_ROW9_COL8	KEY_RESERVED

#define KEY_ROW10_COL1	KEY_RESERVED
#define KEY_ROW10_COL2	KEY_RESERVED
#define KEY_ROW10_COL3	KEY_RESERVED
#define KEY_ROW10_COL4	KEY_RESERVED
#define KEY_ROW10_COL5	KEY_RESERVED
#define KEY_ROW10_COL6	KEY_RESERVED
#define KEY_ROW10_COL7	KEY_RESERVED
#define KEY_ROW10_COL8	KEY_RESERVED

#define KEY_ROW11_COL1	KEY_RESERVED
#define KEY_ROW11_COL2	KEY_RESERVED
#define KEY_ROW11_COL3	KEY_RESERVED
#define KEY_ROW11_COL4	KEY_RESERVED
#define KEY_ROW11_COL5	KEY_RESERVED
#define KEY_ROW11_COL6	KEY_RESERVED
#define KEY_ROW11_COL7	KEY_RESERVED
#define KEY_ROW11_COL8	KEY_RESERVED

#define KEY_ROW12_COL1	KEY_RESERVED
#define KEY_ROW12_COL2	KEY_RESERVED
#define KEY_ROW12_COL3	KEY_RESERVED
#define KEY_ROW12_COL4	KEY_RESERVED
#define KEY_ROW12_COL5	KEY_RESERVED
#define KEY_ROW12_COL6	KEY_RESERVED
#define KEY_ROW12_COL7	KEY_RESERVED
#define KEY_ROW12_COL8	KEY_RESERVED

/* PM8058 chip param. */
#define SH_INPUT_NAME			"SH_tenkey2-keypad"
#define SH_INPUT_PHYS_DEVICE	"SH_tenkey2-keypad/input0"
#define SH_NUM_ROWS				6
#define SH_NUM_COLS				8
#define SH_ROWS_GPIO_START		8
#define SH_COLS_GPIO_START		0
#define SH_DEBOUNCE_MS0			8
#define SH_DEBOUNCE_MS1			10
#define SH_SCAN_DELAY_MS		32
#define SH_HOLD_NS				91500


#elif defined(CONFIG_TENKEY3_KEYPAD)

/* TENKEY3 key map */
#define KEY_ROW1_COL1	KEY_RESERVED
#define KEY_ROW1_COL2	KEY_SEND
#define KEY_ROW1_COL3	KEY_POUND
#define KEY_ROW1_COL4	KEY_RSK
#define KEY_ROW1_COL5	KEY_6
#define KEY_ROW1_COL6	KEY_RESERVED
#define KEY_ROW1_COL7	KEY_8
#define KEY_ROW1_COL8	KEY_4

#define KEY_ROW2_COL1	KEY_RESERVED
#define KEY_ROW2_COL2	KEY_HOME
#define KEY_ROW2_COL3	KEY_7
#define KEY_ROW2_COL4	KEY_9
#define KEY_ROW2_COL5	KEY_BACKSPACE
#define KEY_ROW2_COL6	KEY_SEARCH
#define KEY_ROW2_COL7	KEY_UP
#define KEY_ROW2_COL8	KEY_LEFT

#define KEY_ROW3_COL1	KEY_MENU
#define KEY_ROW3_COL2	KEY_3
#define KEY_ROW3_COL3	KEY_SAVE
#define KEY_ROW3_COL4	KEY_VOLUMEUP
#define KEY_ROW3_COL5	KEY_VOLUMEDOWN
#define KEY_ROW3_COL6	KEY_RESERVED
#define KEY_ROW3_COL7	KEY_FOCUS
#define KEY_ROW3_COL8	KEY_CAMERA

#define KEY_ROW4_COL1	KEY_RESERVED
#define KEY_ROW4_COL2	KEY_RESERVED
#define KEY_ROW4_COL3	KEY_5
#define KEY_ROW4_COL4	KEY_1
#define KEY_ROW4_COL5	KEY_0
#define KEY_ROW4_COL6	KEY_RESERVED
#define KEY_ROW4_COL7	KEY_DOWN
#define KEY_ROW4_COL8	KEY_RIGHT

#define KEY_ROW5_COL1	KEY_RESERVED
#define KEY_ROW5_COL2	KEY_ENTER
#define KEY_ROW5_COL3	KEY_BACK
#define KEY_ROW5_COL4	KEY_APP1
#define KEY_ROW5_COL5	KEY_LSK
#define KEY_ROW5_COL6	KEY_RESERVED
#define KEY_ROW5_COL7	KEY_STAR
#define KEY_ROW5_COL8	KEY_2

#define KEY_ROW6_COL1	KEY_RESERVED
#define KEY_ROW6_COL2	KEY_RESERVED
#define KEY_ROW6_COL3	KEY_RESERVED
#define KEY_ROW6_COL4	KEY_RESERVED
#define KEY_ROW6_COL5	KEY_RESERVED
#define KEY_ROW6_COL6	KEY_RESERVED
#define KEY_ROW6_COL7	KEY_RESERVED
#define KEY_ROW6_COL8	KEY_RESERVED

#define KEY_ROW7_COL1	KEY_RESERVED
#define KEY_ROW7_COL2	KEY_RESERVED
#define KEY_ROW7_COL3	KEY_RESERVED
#define KEY_ROW7_COL4	KEY_RESERVED
#define KEY_ROW7_COL5	KEY_RESERVED
#define KEY_ROW7_COL6	KEY_RESERVED
#define KEY_ROW7_COL7	KEY_RESERVED
#define KEY_ROW7_COL8	KEY_RESERVED

#define KEY_ROW8_COL1	KEY_RESERVED
#define KEY_ROW8_COL2	KEY_RESERVED
#define KEY_ROW8_COL3	KEY_RESERVED
#define KEY_ROW8_COL4	KEY_RESERVED
#define KEY_ROW8_COL5	KEY_RESERVED
#define KEY_ROW8_COL6	KEY_RESERVED
#define KEY_ROW8_COL7	KEY_RESERVED
#define KEY_ROW8_COL8	KEY_RESERVED

#define KEY_ROW9_COL1	KEY_RESERVED
#define KEY_ROW9_COL2	KEY_RESERVED
#define KEY_ROW9_COL3	KEY_RESERVED
#define KEY_ROW9_COL4	KEY_RESERVED
#define KEY_ROW9_COL5	KEY_RESERVED
#define KEY_ROW9_COL6	KEY_RESERVED
#define KEY_ROW9_COL7	KEY_RESERVED
#define KEY_ROW9_COL8	KEY_RESERVED

#define KEY_ROW10_COL1	KEY_RESERVED
#define KEY_ROW10_COL2	KEY_RESERVED
#define KEY_ROW10_COL3	KEY_RESERVED
#define KEY_ROW10_COL4	KEY_RESERVED
#define KEY_ROW10_COL5	KEY_RESERVED
#define KEY_ROW10_COL6	KEY_RESERVED
#define KEY_ROW10_COL7	KEY_RESERVED
#define KEY_ROW10_COL8	KEY_RESERVED

#define KEY_ROW11_COL1	KEY_RESERVED
#define KEY_ROW11_COL2	KEY_RESERVED
#define KEY_ROW11_COL3	KEY_RESERVED
#define KEY_ROW11_COL4	KEY_RESERVED
#define KEY_ROW11_COL5	KEY_RESERVED
#define KEY_ROW11_COL6	KEY_RESERVED
#define KEY_ROW11_COL7	KEY_RESERVED
#define KEY_ROW11_COL8	KEY_RESERVED

#define KEY_ROW12_COL1	KEY_RESERVED
#define KEY_ROW12_COL2	KEY_RESERVED
#define KEY_ROW12_COL3	KEY_RESERVED
#define KEY_ROW12_COL4	KEY_RESERVED
#define KEY_ROW12_COL5	KEY_RESERVED
#define KEY_ROW12_COL6	KEY_RESERVED
#define KEY_ROW12_COL7	KEY_RESERVED
#define KEY_ROW12_COL8	KEY_RESERVED

/* PM8058 chip param. */
#define SH_INPUT_NAME			"SH_tenkey3-keypad"
#define SH_INPUT_PHYS_DEVICE	"SH_tenkey3-keypad/input0"
#define SH_NUM_ROWS				6
#define SH_NUM_COLS				8
#define SH_ROWS_GPIO_START		8
#define SH_COLS_GPIO_START		0
#define SH_DEBOUNCE_MS0			8
#define SH_DEBOUNCE_MS1			10
#define SH_SCAN_DELAY_MS		32
#define SH_HOLD_NS				91500


#elif defined (CONFIG_MATRIX_KEYPAD)

/* MATRIX key map */
#define	KEY_ROW1_COL1	KEY_MENU
#define	KEY_ROW1_COL2	KEY_HOME
#define	KEY_ROW1_COL3	KEY_BACK
#define	KEY_ROW1_COL4	KEY_VOLUMEUP
#define	KEY_ROW1_COL5	KEY_VOLUMEDOWN
#define	KEY_ROW1_COL6	KEY_SEARCH
#define	KEY_ROW1_COL7	KEY_FOCUS
#define	KEY_ROW1_COL8	KEY_CAMERA

#define	KEY_ROW2_COL1	KEY_RESERVED
#define	KEY_ROW2_COL2	KEY_RESERVED
#define	KEY_ROW2_COL3	KEY_RESERVED
#define	KEY_ROW2_COL4	KEY_RESERVED
#define	KEY_ROW2_COL5	KEY_RESERVED
#define	KEY_ROW2_COL6	KEY_RESERVED
#define	KEY_ROW2_COL7	KEY_RESERVED
#define	KEY_ROW2_COL8	KEY_RESERVED

#define	KEY_ROW3_COL1	KEY_RESERVED
#define	KEY_ROW3_COL2	KEY_RESERVED
#define	KEY_ROW3_COL3	KEY_RESERVED
#define	KEY_ROW3_COL4	KEY_RESERVED
#define	KEY_ROW3_COL5	KEY_RESERVED
#define	KEY_ROW3_COL6	KEY_RESERVED
#define	KEY_ROW3_COL7	KEY_RESERVED
#define	KEY_ROW3_COL8	KEY_RESERVED

#define	KEY_ROW4_COL1	KEY_RESERVED
#define	KEY_ROW4_COL2	KEY_RESERVED
#define	KEY_ROW4_COL3	KEY_RESERVED
#define	KEY_ROW4_COL4	KEY_RESERVED
#define	KEY_ROW4_COL5	KEY_RESERVED
#define	KEY_ROW4_COL6	KEY_RESERVED
#define	KEY_ROW4_COL7	KEY_RESERVED
#define	KEY_ROW4_COL8	KEY_RESERVED

#define	KEY_ROW5_COL1	KEY_RESERVED
#define	KEY_ROW5_COL2	KEY_RESERVED
#define	KEY_ROW5_COL3	KEY_RESERVED
#define	KEY_ROW5_COL4	KEY_RESERVED
#define	KEY_ROW5_COL5	KEY_RESERVED
#define	KEY_ROW5_COL6	KEY_RESERVED
#define	KEY_ROW5_COL7	KEY_RESERVED
#define	KEY_ROW5_COL8	KEY_RESERVED

#define	KEY_ROW6_COL1	KEY_RESERVED
#define	KEY_ROW6_COL2	KEY_RESERVED
#define	KEY_ROW6_COL3	KEY_RESERVED
#define	KEY_ROW6_COL4	KEY_RESERVED
#define	KEY_ROW6_COL5	KEY_RESERVED
#define	KEY_ROW6_COL6	KEY_RESERVED
#define	KEY_ROW6_COL7	KEY_RESERVED
#define	KEY_ROW6_COL8	KEY_RESERVED

#define	KEY_ROW7_COL1	KEY_RESERVED
#define	KEY_ROW7_COL2	KEY_RESERVED
#define	KEY_ROW7_COL3	KEY_RESERVED
#define	KEY_ROW7_COL4	KEY_RESERVED
#define	KEY_ROW7_COL5	KEY_RESERVED
#define	KEY_ROW7_COL6	KEY_RESERVED
#define	KEY_ROW7_COL7	KEY_RESERVED
#define	KEY_ROW7_COL8	KEY_RESERVED

#define	KEY_ROW8_COL1	KEY_RESERVED
#define	KEY_ROW8_COL2	KEY_RESERVED
#define	KEY_ROW8_COL3	KEY_RESERVED
#define	KEY_ROW8_COL4	KEY_RESERVED
#define	KEY_ROW8_COL5	KEY_RESERVED
#define	KEY_ROW8_COL6	KEY_RESERVED
#define	KEY_ROW8_COL7	KEY_RESERVED
#define	KEY_ROW8_COL8	KEY_RESERVED

#define	KEY_ROW9_COL1	KEY_RESERVED
#define	KEY_ROW9_COL2	KEY_RESERVED
#define	KEY_ROW9_COL3	KEY_RESERVED
#define	KEY_ROW9_COL4	KEY_RESERVED
#define	KEY_ROW9_COL5	KEY_RESERVED
#define	KEY_ROW9_COL6	KEY_RESERVED
#define	KEY_ROW9_COL7	KEY_RESERVED
#define	KEY_ROW9_COL8	KEY_RESERVED

#define	KEY_ROW10_COL1	KEY_RESERVED
#define	KEY_ROW10_COL2	KEY_RESERVED
#define	KEY_ROW10_COL3	KEY_RESERVED
#define	KEY_ROW10_COL4	KEY_RESERVED
#define	KEY_ROW10_COL5	KEY_RESERVED
#define	KEY_ROW10_COL6	KEY_RESERVED
#define	KEY_ROW10_COL7	KEY_RESERVED
#define	KEY_ROW10_COL8	KEY_RESERVED

#define	KEY_ROW11_COL1	KEY_RESERVED
#define	KEY_ROW11_COL2	KEY_RESERVED
#define	KEY_ROW11_COL3	KEY_RESERVED
#define	KEY_ROW11_COL4	KEY_RESERVED
#define	KEY_ROW11_COL5	KEY_RESERVED
#define	KEY_ROW11_COL6	KEY_RESERVED
#define	KEY_ROW11_COL7	KEY_RESERVED
#define	KEY_ROW11_COL8	KEY_RESERVED

#define	KEY_ROW12_COL1	KEY_RESERVED
#define	KEY_ROW12_COL2	KEY_RESERVED
#define	KEY_ROW12_COL3	KEY_RESERVED
#define	KEY_ROW12_COL4	KEY_RESERVED
#define	KEY_ROW12_COL5	KEY_RESERVED
#define	KEY_ROW12_COL6	KEY_RESERVED
#define	KEY_ROW12_COL7	KEY_RESERVED
#define	KEY_ROW12_COL8	KEY_RESERVED

/* PM8058 chip param. */
#define SH_INPUT_NAME			"SH_matrix-keypad"
#define SH_INPUT_PHYS_DEVICE	"SH_matrix-keypad/input0"
#define SH_NUM_ROWS				5
#define SH_NUM_COLS				8
#define SH_ROWS_GPIO_START		8
#define SH_COLS_GPIO_START		0
#define SH_DEBOUNCE_MS0			8
#define SH_DEBOUNCE_MS1			10
#define SH_SCAN_DELAY_MS		32
#define SH_HOLD_NS				91500

#elif defined (CONFIG_MATRIX2_KEYPAD)

/* MATRIX2 key map */
#define	KEY_ROW1_COL1	KEY_MENU
#define	KEY_ROW1_COL2	KEY_HOME
#define	KEY_ROW1_COL3	KEY_BACK
#define	KEY_ROW1_COL4	KEY_VOLUMEUP
#define	KEY_ROW1_COL5	KEY_VOLUMEDOWN
#define	KEY_ROW1_COL6	KEY_SEARCH
#define	KEY_ROW1_COL7	KEY_FOCUS
#define	KEY_ROW1_COL8	KEY_CAMERA

#define	KEY_ROW2_COL1	KEY_RESERVED
#define	KEY_ROW2_COL2	KEY_RESERVED
#define	KEY_ROW2_COL3	KEY_RESERVED
#define	KEY_ROW2_COL4	KEY_RESERVED
#define	KEY_ROW2_COL5	KEY_RESERVED
#define	KEY_ROW2_COL6	KEY_RESERVED
#define	KEY_ROW2_COL7	KEY_RESERVED
#define	KEY_ROW2_COL8	KEY_RESERVED

#define	KEY_ROW3_COL1	KEY_RESERVED
#define	KEY_ROW3_COL2	KEY_RESERVED
#define	KEY_ROW3_COL3	KEY_RESERVED
#define	KEY_ROW3_COL4	KEY_RESERVED
#define	KEY_ROW3_COL5	KEY_RESERVED
#define	KEY_ROW3_COL6	KEY_RESERVED
#define	KEY_ROW3_COL7	KEY_RESERVED
#define	KEY_ROW3_COL8	KEY_RESERVED

#define	KEY_ROW4_COL1	KEY_RESERVED
#define	KEY_ROW4_COL2	KEY_RESERVED
#define	KEY_ROW4_COL3	KEY_RESERVED
#define	KEY_ROW4_COL4	KEY_RESERVED
#define	KEY_ROW4_COL5	KEY_RESERVED
#define	KEY_ROW4_COL6	KEY_RESERVED
#define	KEY_ROW4_COL7	KEY_RESERVED
#define	KEY_ROW4_COL8	KEY_RESERVED

#define	KEY_ROW5_COL1	KEY_RESERVED
#define	KEY_ROW5_COL2	KEY_RESERVED
#define	KEY_ROW5_COL3	KEY_RESERVED
#define	KEY_ROW5_COL4	KEY_RESERVED
#define	KEY_ROW5_COL5	KEY_RESERVED
#define	KEY_ROW5_COL6	KEY_RESERVED
#define	KEY_ROW5_COL7	KEY_RESERVED
#define	KEY_ROW5_COL8	KEY_RESERVED

#define	KEY_ROW6_COL1	KEY_RESERVED
#define	KEY_ROW6_COL2	KEY_RESERVED
#define	KEY_ROW6_COL3	KEY_RESERVED
#define	KEY_ROW6_COL4	KEY_RESERVED
#define	KEY_ROW6_COL5	KEY_RESERVED
#define	KEY_ROW6_COL6	KEY_RESERVED
#define	KEY_ROW6_COL7	KEY_RESERVED
#define	KEY_ROW6_COL8	KEY_RESERVED

#define	KEY_ROW7_COL1	KEY_RESERVED
#define	KEY_ROW7_COL2	KEY_RESERVED
#define	KEY_ROW7_COL3	KEY_RESERVED
#define	KEY_ROW7_COL4	KEY_RESERVED
#define	KEY_ROW7_COL5	KEY_RESERVED
#define	KEY_ROW7_COL6	KEY_RESERVED
#define	KEY_ROW7_COL7	KEY_RESERVED
#define	KEY_ROW7_COL8	KEY_RESERVED

#define	KEY_ROW8_COL1	KEY_RESERVED
#define	KEY_ROW8_COL2	KEY_RESERVED
#define	KEY_ROW8_COL3	KEY_RESERVED
#define	KEY_ROW8_COL4	KEY_RESERVED
#define	KEY_ROW8_COL5	KEY_RESERVED
#define	KEY_ROW8_COL6	KEY_RESERVED
#define	KEY_ROW8_COL7	KEY_RESERVED
#define	KEY_ROW8_COL8	KEY_RESERVED

#define	KEY_ROW9_COL1	KEY_RESERVED
#define	KEY_ROW9_COL2	KEY_RESERVED
#define	KEY_ROW9_COL3	KEY_RESERVED
#define	KEY_ROW9_COL4	KEY_RESERVED
#define	KEY_ROW9_COL5	KEY_RESERVED
#define	KEY_ROW9_COL6	KEY_RESERVED
#define	KEY_ROW9_COL7	KEY_RESERVED
#define	KEY_ROW9_COL8	KEY_RESERVED

#define	KEY_ROW10_COL1	KEY_RESERVED
#define	KEY_ROW10_COL2	KEY_RESERVED
#define	KEY_ROW10_COL3	KEY_RESERVED
#define	KEY_ROW10_COL4	KEY_RESERVED
#define	KEY_ROW10_COL5	KEY_RESERVED
#define	KEY_ROW10_COL6	KEY_RESERVED
#define	KEY_ROW10_COL7	KEY_RESERVED
#define	KEY_ROW10_COL8	KEY_RESERVED

#define	KEY_ROW11_COL1	KEY_RESERVED
#define	KEY_ROW11_COL2	KEY_RESERVED
#define	KEY_ROW11_COL3	KEY_RESERVED
#define	KEY_ROW11_COL4	KEY_RESERVED
#define	KEY_ROW11_COL5	KEY_RESERVED
#define	KEY_ROW11_COL6	KEY_RESERVED
#define	KEY_ROW11_COL7	KEY_RESERVED
#define	KEY_ROW11_COL8	KEY_RESERVED

#define	KEY_ROW12_COL1	KEY_RESERVED
#define	KEY_ROW12_COL2	KEY_RESERVED
#define	KEY_ROW12_COL3	KEY_RESERVED
#define	KEY_ROW12_COL4	KEY_RESERVED
#define	KEY_ROW12_COL5	KEY_RESERVED
#define	KEY_ROW12_COL6	KEY_RESERVED
#define	KEY_ROW12_COL7	KEY_RESERVED
#define	KEY_ROW12_COL8	KEY_RESERVED

/* PM8058 chip param. */
#define SH_INPUT_NAME			"SH_matrix-keypad"
#define SH_INPUT_PHYS_DEVICE	"SH_matrix-keypad/input0"
#define SH_NUM_ROWS				5
#define SH_NUM_COLS				8
#define SH_ROWS_GPIO_START		8
#define SH_COLS_GPIO_START		0
#define SH_DEBOUNCE_MS0			8
#define SH_DEBOUNCE_MS1			10
#define SH_SCAN_DELAY_MS		32
#define SH_HOLD_NS				91500


#elif defined (CONFIG_MATRIX3_KEYPAD)

/* MATRIX3 key map */
#define	KEY_ROW1_COL1	KEY_MENU
#define	KEY_ROW1_COL2	KEY_HOME
#define	KEY_ROW1_COL3	KEY_BACK
#define	KEY_ROW1_COL4	KEY_VOLUMEUP
#define	KEY_ROW1_COL5	KEY_VOLUMEDOWN
#define	KEY_ROW1_COL6	KEY_SEARCH
#define	KEY_ROW1_COL7	KEY_RESERVED
#define	KEY_ROW1_COL8	KEY_RESERVED

#define	KEY_ROW2_COL1	KEY_RESERVED
#define	KEY_ROW2_COL2	KEY_RESERVED
#define	KEY_ROW2_COL3	KEY_RESERVED
#define	KEY_ROW2_COL4	KEY_RESERVED
#define	KEY_ROW2_COL5	KEY_RESERVED
#define	KEY_ROW2_COL6	KEY_RESERVED
#define	KEY_ROW2_COL7	KEY_RESERVED
#define	KEY_ROW2_COL8	KEY_RESERVED

#define	KEY_ROW3_COL1	KEY_RESERVED
#define	KEY_ROW3_COL2	KEY_RESERVED
#define	KEY_ROW3_COL3	KEY_RESERVED
#define	KEY_ROW3_COL4	KEY_RESERVED
#define	KEY_ROW3_COL5	KEY_RESERVED
#define	KEY_ROW3_COL6	KEY_RESERVED
#define	KEY_ROW3_COL7	KEY_RESERVED
#define	KEY_ROW3_COL8	KEY_RESERVED

#define	KEY_ROW4_COL1	KEY_RESERVED
#define	KEY_ROW4_COL2	KEY_RESERVED
#define	KEY_ROW4_COL3	KEY_RESERVED
#define	KEY_ROW4_COL4	KEY_RESERVED
#define	KEY_ROW4_COL5	KEY_RESERVED
#define	KEY_ROW4_COL6	KEY_RESERVED
#define	KEY_ROW4_COL7	KEY_RESERVED
#define	KEY_ROW4_COL8	KEY_RESERVED

#define	KEY_ROW5_COL1	KEY_RESERVED
#define	KEY_ROW5_COL2	KEY_RESERVED
#define	KEY_ROW5_COL3	KEY_RESERVED
#define	KEY_ROW5_COL4	KEY_RESERVED
#define	KEY_ROW5_COL5	KEY_RESERVED
#define	KEY_ROW5_COL6	KEY_RESERVED
#define	KEY_ROW5_COL7	KEY_RESERVED
#define	KEY_ROW5_COL8	KEY_RESERVED

#define	KEY_ROW6_COL1	KEY_RESERVED
#define	KEY_ROW6_COL2	KEY_RESERVED
#define	KEY_ROW6_COL3	KEY_RESERVED
#define	KEY_ROW6_COL4	KEY_RESERVED
#define	KEY_ROW6_COL5	KEY_RESERVED
#define	KEY_ROW6_COL6	KEY_RESERVED
#define	KEY_ROW6_COL7	KEY_RESERVED
#define	KEY_ROW6_COL8	KEY_RESERVED

#define	KEY_ROW7_COL1	KEY_RESERVED
#define	KEY_ROW7_COL2	KEY_RESERVED
#define	KEY_ROW7_COL3	KEY_RESERVED
#define	KEY_ROW7_COL4	KEY_RESERVED
#define	KEY_ROW7_COL5	KEY_RESERVED
#define	KEY_ROW7_COL6	KEY_RESERVED
#define	KEY_ROW7_COL7	KEY_RESERVED
#define	KEY_ROW7_COL8	KEY_RESERVED

#define	KEY_ROW8_COL1	KEY_RESERVED
#define	KEY_ROW8_COL2	KEY_RESERVED
#define	KEY_ROW8_COL3	KEY_RESERVED
#define	KEY_ROW8_COL4	KEY_RESERVED
#define	KEY_ROW8_COL5	KEY_RESERVED
#define	KEY_ROW8_COL6	KEY_RESERVED
#define	KEY_ROW8_COL7	KEY_RESERVED
#define	KEY_ROW8_COL8	KEY_RESERVED

#define	KEY_ROW9_COL1	KEY_RESERVED
#define	KEY_ROW9_COL2	KEY_RESERVED
#define	KEY_ROW9_COL3	KEY_RESERVED
#define	KEY_ROW9_COL4	KEY_RESERVED
#define	KEY_ROW9_COL5	KEY_RESERVED
#define	KEY_ROW9_COL6	KEY_RESERVED
#define	KEY_ROW9_COL7	KEY_RESERVED
#define	KEY_ROW9_COL8	KEY_RESERVED

#define	KEY_ROW10_COL1	KEY_RESERVED
#define	KEY_ROW10_COL2	KEY_RESERVED
#define	KEY_ROW10_COL3	KEY_RESERVED
#define	KEY_ROW10_COL4	KEY_RESERVED
#define	KEY_ROW10_COL5	KEY_RESERVED
#define	KEY_ROW10_COL6	KEY_RESERVED
#define	KEY_ROW10_COL7	KEY_RESERVED
#define	KEY_ROW10_COL8	KEY_RESERVED

#define	KEY_ROW11_COL1	KEY_RESERVED
#define	KEY_ROW11_COL2	KEY_RESERVED
#define	KEY_ROW11_COL3	KEY_RESERVED
#define	KEY_ROW11_COL4	KEY_RESERVED
#define	KEY_ROW11_COL5	KEY_RESERVED
#define	KEY_ROW11_COL6	KEY_RESERVED
#define	KEY_ROW11_COL7	KEY_RESERVED
#define	KEY_ROW11_COL8	KEY_RESERVED

#define	KEY_ROW12_COL1	KEY_RESERVED
#define	KEY_ROW12_COL2	KEY_RESERVED
#define	KEY_ROW12_COL3	KEY_RESERVED
#define	KEY_ROW12_COL4	KEY_RESERVED
#define	KEY_ROW12_COL5	KEY_RESERVED
#define	KEY_ROW12_COL6	KEY_RESERVED
#define	KEY_ROW12_COL7	KEY_RESERVED
#define	KEY_ROW12_COL8	KEY_RESERVED

/* PM8058 chip param. */
#define SH_INPUT_NAME			"SH_matrix-keypad"
#define SH_INPUT_PHYS_DEVICE	"SH_matrix-keypad/input0"
#define SH_NUM_ROWS				5
#define SH_NUM_COLS				6
#define SH_ROWS_GPIO_START		8
#define SH_COLS_GPIO_START		0
#define SH_DEBOUNCE_MS0			8
#define SH_DEBOUNCE_MS1			10
#define SH_SCAN_DELAY_MS		32
#define SH_HOLD_NS				91500


#elif defined(CONFIG_QWERTY2_KEYPAD)

/* QWERTY2 key map */
#define KEY_ROW1_COL1	KEY_BACK
#define KEY_ROW1_COL2	KEY_HOME
#define KEY_ROW1_COL3	KEY_ENTER
#define KEY_ROW1_COL4	KEY_RESERVED
#define KEY_ROW1_COL5	KEY_RESERVED
#define KEY_ROW1_COL6	KEY_DOT
#define KEY_ROW1_COL7	KEY_RESERVED
#define KEY_ROW1_COL8	KEY_SPACE

#define KEY_ROW2_COL1	KEY_Q
#define KEY_ROW2_COL2	KEY_UP
#define KEY_ROW2_COL3	KEY_I
#define KEY_ROW2_COL4	KEY_RESERVED
#define KEY_ROW2_COL5	KEY_Y
#define KEY_ROW2_COL6	KEY_RESERVED
#define KEY_ROW2_COL7	KEY_RESERVED
#define KEY_ROW2_COL8	KEY_RESERVED

#define KEY_ROW3_COL1	KEY_LEFT
#define KEY_ROW3_COL2	KEY_R
#define KEY_ROW3_COL3	KEY_RIGHT
#define KEY_ROW3_COL4	KEY_RESERVED
#define KEY_ROW3_COL5	KEY_RESERVED
#define KEY_ROW3_COL6	KEY_RESERVED
#define KEY_ROW3_COL7	KEY_KIGOU
#define KEY_ROW3_COL8	KEY_VOLUMEUP

#define KEY_ROW4_COL1	KEY_E
#define KEY_ROW4_COL2	KEY_DOWN
#define KEY_ROW4_COL3	KEY_P
#define KEY_ROW4_COL4	KEY_T
#define KEY_ROW4_COL5	KEY_RESERVED
#define KEY_ROW4_COL6	KEY_RESERVED
#define KEY_ROW4_COL7	KEY_RESERVED
#define KEY_ROW4_COL8	KEY_RESERVED

#define KEY_ROW5_COL1	KEY_O
#define KEY_ROW5_COL2	KEY_U
#define KEY_ROW5_COL3	KEY_W
#define KEY_ROW5_COL4	KEY_FUNC
#define KEY_ROW5_COL5	KEY_COMMA
#define KEY_ROW5_COL6	KEY_RESERVED
#define KEY_ROW5_COL7	KEY_FOCUS
#define KEY_ROW5_COL8	KEY_CAMERA

#define KEY_ROW6_COL1	KEY_PICTURE
#define KEY_ROW6_COL2	KEY_A
#define KEY_ROW6_COL3	KEY_X
#define KEY_ROW6_COL4	KEY_J
#define KEY_ROW6_COL5	KEY_B
#define KEY_ROW6_COL6	KEY_F
#define KEY_ROW6_COL7	KEY_MINUS
#define KEY_ROW6_COL8	KEY_RESERVED

#define KEY_ROW7_COL1	KEY_C
#define KEY_ROW7_COL2	KEY_N
#define KEY_ROW7_COL3	KEY_G
#define KEY_ROW7_COL4	KEY_S
#define KEY_ROW7_COL5	KEY_VOLUMEDOWN
#define KEY_ROW7_COL6	KEY_K
#define KEY_ROW7_COL7	KEY_BACKSPACE
#define KEY_ROW7_COL8	KEY_RESERVED

#define KEY_ROW8_COL1	KEY_Z
#define KEY_ROW8_COL2	KEY_V
#define KEY_ROW8_COL3	KEY_M
#define KEY_ROW8_COL4	KEY_L
#define KEY_ROW8_COL5	KEY_D
#define KEY_ROW8_COL6	KEY_H
#define KEY_ROW8_COL7	KEY_CHARACTER
#define KEY_ROW8_COL8	KEY_RESERVED

#define KEY_ROW9_COL1	KEY_RESERVED
#define KEY_ROW9_COL2	KEY_RESERVED
#define KEY_ROW9_COL3	KEY_LEFTSHIFT
#define KEY_ROW9_COL4	KEY_VOLUMEUP
#define KEY_ROW9_COL5	KEY_SEARCH
#define KEY_ROW9_COL6	KEY_SEARCH
#define KEY_ROW9_COL7	KEY_RIGHTSHIFT
#define KEY_ROW9_COL8	KEY_CAMERA

#define KEY_ROW10_COL1	KEY_MENU
#define KEY_ROW10_COL2	KEY_HOME
#define KEY_ROW10_COL3	KEY_BACK
#define KEY_ROW10_COL4	KEY_LEFTFN
#define KEY_ROW10_COL5	KEY_VOLUMEDOWN
#define KEY_ROW10_COL6	KEY_MENU
#define KEY_ROW10_COL7	KEY_FOCUS
#define KEY_ROW10_COL8	KEY_RIGHTFN

#define KEY_ROW11_COL1	KEY_RESERVED
#define KEY_ROW11_COL2	KEY_RESERVED
#define KEY_ROW11_COL3	KEY_RESERVED
#define KEY_ROW11_COL4	KEY_RESERVED
#define KEY_ROW11_COL5	KEY_RESERVED
#define KEY_ROW11_COL6	KEY_RESERVED
#define KEY_ROW11_COL7	KEY_RESERVED
#define KEY_ROW11_COL8	KEY_RESERVED

#define KEY_ROW12_COL1	KEY_RESERVED
#define KEY_ROW12_COL2	KEY_RESERVED
#define KEY_ROW12_COL3	KEY_RESERVED
#define KEY_ROW12_COL4	KEY_RESERVED
#define KEY_ROW12_COL5	KEY_RESERVED
#define KEY_ROW12_COL6	KEY_RESERVED
#define KEY_ROW12_COL7	KEY_RESERVED
#define KEY_ROW12_COL8	KEY_RESERVED

/* PM8058 chip param. */
#define SH_INPUT_NAME			"SH_qwerty2-keypad"
#define SH_INPUT_PHYS_DEVICE	"SH_qwerty2-keypad/input0"
#define SH_NUM_ROWS				10
#define SH_NUM_COLS				8
#define SH_ROWS_GPIO_START		8
#define SH_COLS_GPIO_START		0
#define SH_DEBOUNCE_MS0			8
#define SH_DEBOUNCE_MS1			10
#define SH_SCAN_DELAY_MS		32
#define SH_HOLD_NS				91500

#else

#define	KEY_ROW1_COL1	KEY_MENU
#define	KEY_ROW1_COL2	KEY_HOME
#define	KEY_ROW1_COL3	KEY_BACK
#define	KEY_ROW1_COL4	KEY_VOLUMEUP
#define	KEY_ROW1_COL5	KEY_VOLUMEDOWN
#define	KEY_ROW1_COL6	KEY_SEARCH
#define	KEY_ROW1_COL7	KEY_FOCUS
#define	KEY_ROW1_COL8	KEY_CAMERA

#define	KEY_ROW2_COL1	KEY_RESERVED
#define	KEY_ROW2_COL2	KEY_RESERVED
#define	KEY_ROW2_COL3	KEY_RESERVED
#define	KEY_ROW2_COL4	KEY_RESERVED
#define	KEY_ROW2_COL5	KEY_RESERVED
#define	KEY_ROW2_COL6	KEY_RESERVED
#define	KEY_ROW2_COL7	KEY_RESERVED
#define	KEY_ROW2_COL8	KEY_RESERVED

#define	KEY_ROW3_COL1	KEY_RESERVED
#define	KEY_ROW3_COL2	KEY_RESERVED
#define	KEY_ROW3_COL3	KEY_RESERVED
#define	KEY_ROW3_COL4	KEY_RESERVED
#define	KEY_ROW3_COL5	KEY_RESERVED
#define	KEY_ROW3_COL6	KEY_RESERVED
#define	KEY_ROW3_COL7	KEY_RESERVED
#define	KEY_ROW3_COL8	KEY_RESERVED

#define	KEY_ROW4_COL1	KEY_RESERVED
#define	KEY_ROW4_COL2	KEY_RESERVED
#define	KEY_ROW4_COL3	KEY_RESERVED
#define	KEY_ROW4_COL4	KEY_RESERVED
#define	KEY_ROW4_COL5	KEY_RESERVED
#define	KEY_ROW4_COL6	KEY_RESERVED
#define	KEY_ROW4_COL7	KEY_RESERVED
#define	KEY_ROW4_COL8	KEY_RESERVED

#define	KEY_ROW5_COL1	KEY_RESERVED
#define	KEY_ROW5_COL2	KEY_RESERVED
#define	KEY_ROW5_COL3	KEY_RESERVED
#define	KEY_ROW5_COL4	KEY_RESERVED
#define	KEY_ROW5_COL5	KEY_RESERVED
#define	KEY_ROW5_COL6	KEY_RESERVED
#define	KEY_ROW5_COL7	KEY_RESERVED
#define	KEY_ROW5_COL8	KEY_RESERVED

#define	KEY_ROW6_COL1	KEY_RESERVED
#define	KEY_ROW6_COL2	KEY_RESERVED
#define	KEY_ROW6_COL3	KEY_RESERVED
#define	KEY_ROW6_COL4	KEY_RESERVED
#define	KEY_ROW6_COL5	KEY_RESERVED
#define	KEY_ROW6_COL6	KEY_RESERVED
#define	KEY_ROW6_COL7	KEY_RESERVED
#define	KEY_ROW6_COL8	KEY_RESERVED

#define	KEY_ROW7_COL1	KEY_RESERVED
#define	KEY_ROW7_COL2	KEY_RESERVED
#define	KEY_ROW7_COL3	KEY_RESERVED
#define	KEY_ROW7_COL4	KEY_RESERVED
#define	KEY_ROW7_COL5	KEY_RESERVED
#define	KEY_ROW7_COL6	KEY_RESERVED
#define	KEY_ROW7_COL7	KEY_RESERVED
#define	KEY_ROW7_COL8	KEY_RESERVED

#define	KEY_ROW8_COL1	KEY_RESERVED
#define	KEY_ROW8_COL2	KEY_RESERVED
#define	KEY_ROW8_COL3	KEY_RESERVED
#define	KEY_ROW8_COL4	KEY_RESERVED
#define	KEY_ROW8_COL5	KEY_RESERVED
#define	KEY_ROW8_COL6	KEY_RESERVED
#define	KEY_ROW8_COL7	KEY_RESERVED
#define	KEY_ROW8_COL8	KEY_RESERVED

#define	KEY_ROW9_COL1	KEY_RESERVED
#define	KEY_ROW9_COL2	KEY_RESERVED
#define	KEY_ROW9_COL3	KEY_RESERVED
#define	KEY_ROW9_COL4	KEY_RESERVED
#define	KEY_ROW9_COL5	KEY_RESERVED
#define	KEY_ROW9_COL6	KEY_RESERVED
#define	KEY_ROW9_COL7	KEY_RESERVED
#define	KEY_ROW9_COL8	KEY_RESERVED

#define	KEY_ROW10_COL1	KEY_RESERVED
#define	KEY_ROW10_COL2	KEY_RESERVED
#define	KEY_ROW10_COL3	KEY_RESERVED
#define	KEY_ROW10_COL4	KEY_RESERVED
#define	KEY_ROW10_COL5	KEY_RESERVED
#define	KEY_ROW10_COL6	KEY_RESERVED
#define	KEY_ROW10_COL7	KEY_RESERVED
#define	KEY_ROW10_COL8	KEY_RESERVED

#define	KEY_ROW11_COL1	KEY_RESERVED
#define	KEY_ROW11_COL2	KEY_RESERVED
#define	KEY_ROW11_COL3	KEY_RESERVED
#define	KEY_ROW11_COL4	KEY_RESERVED
#define	KEY_ROW11_COL5	KEY_RESERVED
#define	KEY_ROW11_COL6	KEY_RESERVED
#define	KEY_ROW11_COL7	KEY_RESERVED
#define	KEY_ROW11_COL8	KEY_RESERVED

#define	KEY_ROW12_COL1	KEY_RESERVED
#define	KEY_ROW12_COL2	KEY_RESERVED
#define	KEY_ROW12_COL3	KEY_RESERVED
#define	KEY_ROW12_COL4	KEY_RESERVED
#define	KEY_ROW12_COL5	KEY_RESERVED
#define	KEY_ROW12_COL6	KEY_RESERVED
#define	KEY_ROW12_COL7	KEY_RESERVED
#define	KEY_ROW12_COL8	KEY_RESERVED

/* PM8058 chip param. */
#define SH_INPUT_NAME			"SH_matrix-keypad"
#define SH_INPUT_PHYS_DEVICE	"SH_matrix-keypad/input0"
#define SH_NUM_ROWS				5
#define SH_NUM_COLS				8
#define SH_ROWS_GPIO_START		8
#define SH_COLS_GPIO_START		0
#define SH_DEBOUNCE_MS0			8
#define SH_DEBOUNCE_MS1			10
#define SH_SCAN_DELAY_MS		32
#define SH_HOLD_NS				91500

#endif	/* defined(CONFIG_TENKEY_KEYPAD) */
#endif	/* CONFIG_KEYBOARD_SCKEY */

#endif	/* __SH_PMIC8058_KEYPAD_H__ */
