/*
 * Copyright (C) 2019 MediaTek Inc.
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
#ifndef __IMGSENSOR_PLATFORM_H__
#define __IMGSENSOR_PLATFORM_H__

#ifdef CONFIG_CAMERA_DVDD_SWITCH
#else
#define MIPI_SWITCH
#endif
enum IMGSENSOR_HW_ID {
	IMGSENSOR_HW_ID_MCLK,
	IMGSENSOR_HW_ID_REGULATOR,
	IMGSENSOR_HW_ID_GPIO,
#ifdef CONFIG_MOT_WL2868
	IMGSENSOR_HW_ID_WL2868,
#endif
	IMGSENSOR_HW_ID_MAX_NUM,
	IMGSENSOR_HW_ID_NONE = -1
};
#endif
