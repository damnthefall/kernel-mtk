/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef __SWTP_H__
#define __SWTP_H__

/* modify MAX_PIN_NUM/DTS to support more gpio,
 * need to follow SOP for customization.
 */

#ifdef SAIPAN_SWTP_CONFIG
#define MAX_PIN_NUM 4
#endif
#ifdef AUSTIN_SWTP_CONFIG
#define MAX_PIN_NUM 3
#endif
#ifdef KYOTO_SWTP_CUST
#define MAX_PIN_NUM 4
#endif

#define SWTP_COMPATIBLE_DEVICE_ID "mediatek, swtp-eint"
#define SWTP1_COMPATIBLE_DEVICE_ID "mediatek, swtp1-eint"
/*ExtB EKSAIPAN-82 yangchanghui.wt 20210129 modify for swtp start*/
#define SWTP2_COMPATIBLE_DEVICE_ID "mediatek, swtp2-eint"
#define SWTP3_COMPATIBLE_DEVICE_ID "mediatek, swtp3-eint"
/*ExtB EKSAIPAN-82 yangchanghui.wt 20210129 modify for swtp end*/

#define SWTP_EINT_PIN_PLUG_IN	(1)
#define SWTP_EINT_PIN_PLUG_OUT	(0)

#define SWTP_DO_TX_POWER	(0)
#define SWTP_NO_TX_POWER	(1)

struct swtp_t {
	unsigned int	md_id;
	unsigned int	curr_mode;
	unsigned int	irq[MAX_PIN_NUM];
	unsigned int	gpiopin[MAX_PIN_NUM];
	unsigned int	setdebounce[MAX_PIN_NUM];
	unsigned int	eint_type[MAX_PIN_NUM];
	unsigned int	gpio_state[MAX_PIN_NUM];
	int	tx_power_mode;
	spinlock_t		spinlock;
	struct delayed_work delayed_work;
	struct delayed_work init_delayed_work;
};
/*****************************************************************************/
/* External API Region called by ccci_swtp object */
/*****************************************************************************/
extern void inject_pin_status_event(int pin_value, const char pin_name[]);
extern int swtp_init(int md_id);
extern void inject_pin_status_event(int pin_value, const char pin_name[]);
#endif				/* __SWTP_H__ */
