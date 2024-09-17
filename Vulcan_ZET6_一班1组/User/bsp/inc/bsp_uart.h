/*
*********************************************************************************************************
*
*	模块名称 : uart模块
*	文件名称 : bsp_uart.h
*	说    明 : 
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2024-03-20  付燕华
*
*	Copyright (C), 2014-2024, 德致伦电子
*
*********************************************************************************************************
*/

#ifndef _BSP_UART_H_
#define _BSP_UART_H_

///////////////////////////////////////
/* 头文件包含区 */
#include "bsp.h"
///////////////////////////////////////
/* 宏定义区域 */
#define USART_REC_LEN	1024	//接收缓存长度
#define	EN_USART1_RX	1		//1使能接收，0步使能
///////////////////////////////////////
/* 外部变量申明区 */
extern uint8_t 	USART_RX_BUF[USART_REC_LEN];	//串口1 的接收缓存数组
extern uint8_t 	ReceiveState;				//接收状态，是否是一帧
extern uint16_t	RxCounter;					//接收长度
///////////////////////////////////////
/* 函数申明区 */
void bsp_InitUart(uint32_t baud);
void Uart0_STA_Clr(void);
void USART1_Send_Data(uint8_t *buf,uint8_t len);
void usart1_cmd_receive(void);
///////////////////////////////////////
#endif


/***************************** 德致伦电子 DeZLinc (END OF FILE) *********************************/

