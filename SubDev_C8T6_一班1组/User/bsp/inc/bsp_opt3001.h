/*
*********************************************************************************************************
*
*	模块名称 : 光照传感器模块
*	文件名称 : opt3001.h
*	说    明 : 
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2024-05-31	付燕华
*
*	Copyright (C), 2014-2024, 德致伦电子
*
*********************************************************************************************************
*/

#ifndef _OPT3001_H_
#define _OPT3001_H_

///////////////////////////////////////
/* 头文件包含区 */
#include "sys.h"
///////////////////////////////////////
/* 宏定义区域 */
#define		OPT3001_ADDR		0x8A

/**********CMD命令开始**************/
#define		OPT3001_MANUFACTURER_ID		0x7E
#define		OPT3001_DEVICE_ID			0x7F
#define		OPT3001_RESULT				0x00
#define		OPT3001_CONFIGURATION		0x01
/**********CMD命令结束**************/
#define		OPT3001_ManufacturerID		0x5449
#define		OPT3001_DeviceID			0x3001



///////////////////////////////////////
/* 外部变量申明区 */

///////////////////////////////////////
/* 函数申明区 */
uint8_t	bsp_InitOpt3001(void);//初始化IIC
void OPT3001Config(void);

uint32_t GetLuxValue(void);
///////////////////////////////////////
#endif

/***************************** 德致伦电子 DeZLinc (END OF FILE) *********************************/
