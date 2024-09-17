/*
*********************************************************************************************************
*
*	模块名称 : PM25模块
*	文件名称 : bsp_pm25.h
*	说    明 : 
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2024-06-04	Lawrence
*
*	Copyright (C), 2014-2024, 德致伦电子
*
*********************************************************************************************************
*/

#ifndef _BSP_PM25_H_
#define _BSP_PM25_H_

///////////////////////////////////////
/* 头文件包含区 */
#include "bsp.h"
#include "sys.h"
///////////////////////////////////////
/* 宏定义区域 */
#define	PM25_TEMP_BUF_LEN	10	//定义CO2_TEMP_BUF_LEN缓冲长度为10个字节
///////////////////////////////////////
/* 外部变量申明区 */

///////////////////////////////////////
/* 函数申明区 */
uint16_t PM25_READ(void);
///////////////////////////////////////
#endif

/***************************** 德致伦电子 DeZLinc (END OF FILE) *********************************/
