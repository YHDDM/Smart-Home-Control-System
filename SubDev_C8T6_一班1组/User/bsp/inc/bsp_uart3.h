/*
*********************************************************************************************************
*
*	模块名称 : 模块
*	文件名称 : bsp_uart3.h
*	说    明 : 
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2024-6-4
*
*	Copyright (C), 2014-2024, 德致伦电子
*
*********************************************************************************************************
*/

#ifndef _BSP_UART3_H_
#define _BSP_UART3_H_

///////////////////////////////////////
/* 头文件包含区 */
#include "bsp.h"
#include "sys.h"
///////////////////////////////////////
/* 宏定义区域 */
#define UART3_BUF_LEN 	64						//定义UART5缓冲长度为64个字节
#define EN_UART3_RX 	1						//UART5使能接收,0为不接收，1为接收
///////////////////////////////////////
/* 外部变量申明区 */
extern uint8_t UART3_RX_BUF[UART3_BUF_LEN];		//UART5的缓存数组
extern uint8_t UART3_RX_CNT;					//接收到的数据长度
///////////////////////////////////////
/* 函数申明区 */
void bsp_InitUart3(uint32_t bound);
void UART3_Send_Data(uint8_t *buf,uint8_t len);
void UART3_Receive_Data(uint8_t *buf,uint8_t *len);

#endif


/***************************** 德致伦电子 DeZLinc (END OF FILE) *********************************/
