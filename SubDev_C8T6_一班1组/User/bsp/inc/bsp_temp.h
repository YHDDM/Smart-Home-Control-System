/*
*********************************************************************************************************
*
*	模块名称 : 温湿度传感器模块
*	文件名称 : bsp_temp.h
*	说    明 : 
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2024-05-31	付燕华
*
*	Copyright (C), 2014-2024, 德致伦电子
*
*********************************************************************************************************
*/

#ifndef _BSP_TEMP_H_
#define _BSP_TEMP_H_

///////////////////////////////////////
/* 头文件包含区 */
#include "sys.h"

/////////////////////////////////////////////////////////// 
//移植修改区 
//按照实际端口修改 
//较前版本更加容易移植(注意，端口仅仅适用于非JTAG/SWD引脚，如果是JTAG引脚，需要打开AFIO时钟，并失能JTAG) 


///////////////////////////////////////
/* 宏定义区域 */
#define  i2cAddWrite_8bit           0x88 
#define  i2cAddRead_8bit            0x89


/*CRC*/ 
#define POLYNOMIAL             0x131   // P(x) = x^8 + x^5 + x^4 + 1 = 100110001

//Sensor Commands

typedef enum{ 
	CMD_READ_SERIALNBR    = 0x3780, // read serial number        
	CMD_READ_STATUS       = 0xF32D, // read status register      
	CMD_CLEAR_STATUS      = 0x3041, // clear status register    ? 
	CMD_HEATER_ENABLE     = 0x306D, // enabled heater            
	CMD_HEATER_DISABLE    = 0x3066, // disable heater            
    CMD_SOFT_RESET        = 0x30A2, // soft reset               ? 
	CMD_MEAS_CLOCKSTR_H   = 0x2C06, // meas. clock stretching, high rep. 
	CMD_MEAS_CLOCKSTR_M  = 0x2C0D, // meas. clock stretching, medium rep. 
	CMD_MEAS_CLOCKSTR_L   = 0x2C10, // meas. clock stretching, low rep. 
	CMD_MEAS_POLLING_H    = 0x2400, // meas. no clock stretching, high rep. 
	CMD_MEAS_POLLING_M   = 0x240B, // meas. no clock stretching, medium rep. 
	CMD_MEAS_POLLING_L    = 0x2416, // meas. no clock stretching, low rep. 
	CMD_MEAS_PERI_05_H    = 0x2032, // meas. periodic 0.5 mps, high rep. 
	CMD_MEAS_PERI_05_M    = 0x2024, // meas. periodic 0.5 mps, medium rep. 
	CMD_MEAS_PERI_05_L    = 0x202F, // meas. periodic 0.5 mps, low rep. 
	CMD_MEAS_PERI_1_H     = 0x2130, // meas. periodic 1 mps, high rep. 
	CMD_MEAS_PERI_1_M     = 0x2126, // meas. periodic 1 mps, medium rep. 
	CMD_MEAS_PERI_1_L     = 0x212D, // meas. periodic 1 mps, low rep. 
	CMD_MEAS_PERI_2_H     = 0x2236, // meas. periodic 2 mps, high rep. 
	CMD_MEAS_PERI_2_M     = 0x2220, // meas. periodic 2 mps, medium rep. 
	CMD_MEAS_PERI_2_L     = 0x222B, // meas. periodic 2 mps, low rep. 
	CMD_MEAS_PERI_4_H     = 0x2334, // meas. periodic 4 mps, high rep. 
	CMD_MEAS_PERI_4_M     = 0x2322, // meas. periodic 4 mps, medium rep. 
	CMD_MEAS_PERI_4_L     = 0x2329, // meas. periodic 4 mps, low rep. 
	CMD_MEAS_PERI_10_H    = 0x2737, // meas. periodic 10 mps, high rep. 
	CMD_MEAS_PERI_10_M    = 0x2721, // meas. periodic 10 mps, medium rep. 
	CMD_MEAS_PERI_10_L    = 0x272A, // meas. periodic 10 mps, low rep. 
	CMD_FETCH_DATA        = 0xE000, // readout measurements for periodic mode 
	CMD_R_AL_LIM_LS       = 0xE102, // read alert limits, low set 
	CMD_R_AL_LIM_LC       = 0xE109, // read alert limits, low clear 
	CMD_R_AL_LIM_HS       = 0xE11F, // read alert limits, high set 
	CMD_R_AL_LIM_HC       = 0xE114, // read alert limits, high clear 
	CMD_W_AL_LIM_LS       = 0x6100, // write alert limits, low set 
	CMD_W_AL_LIM_LC       = 0x610B, // write alert limits, low clear 
	CMD_W_AL_LIM_HS       = 0x611D, // write alert limits, high set 
	CMD_W_AL_LIM_HC       = 0x6116, // write alert limits, high clear 
    CMD_NO_SLEEP          = 0x303E, 
}etCommands;
extern float Tem_Value; 
extern float RH_Value;  
 
//函数申明 
void bsp_InitSht3x(void); //初始化 
uint8_t SHT3X_GetValue(void); //获取换算后的温湿度值 
void SHX3X_ReadResults(uint16_t cmd,  uint8_t *p);//得到原始的温湿值 6个字节
///////////////////////////////////////
#endif

/***************************** 德致伦电子 DeZLinc (END OF FILE) *********************************/
