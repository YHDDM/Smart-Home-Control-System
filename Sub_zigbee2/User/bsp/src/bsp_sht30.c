/*
*********************************************************************************************************
*
*	模块名称 : 温湿度传感器驱动模块
*	文件名称 : bsp_sht30.c
*	版    本 : V1.x0
*	说    明 : 
*
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2024-06-03	Lawrence  正式发布
*
*	Copyright (C), 2014-2024, 德致伦电子
*
*********************************************************************************************************
*/

///////////////////////////////////////
/* 头文件包含区 */
#include "bsp.h"
#include "sys.h"
///////////////////////////////////////
/* 变量定义区 */
float Tem_Value = 0.0;//温度值
float RH_Value = 0.0;//湿度值
///////////////////////////////////////
/* 外部变量申明区 */

///////////////////////////////////////
/* 函数申明区 */

///////////////////////////////////////
/* 函数实体区 */
/*
*********************************************************************************************************
*	函 数 名: SHT3X_WriteCMD
*	功能说明: SHT3X写命令
*	形    参：cmd 命令
*	返 回 值: 无
*********************************************************************************************************
*/
void SHT3X_WriteCMD(uint16_t cmd)
{
	IIC_Start();
	IIC_Send_Byte(i2cAddWrite_8bit);//发送写地址
	IIC_Wait_Ack();//等待ack
	IIC_Send_Byte(cmd>>8);//发送命令 高8位
	IIC_Wait_Ack();//等待ack
	IIC_Send_Byte(cmd);//发送命令	低8位
	IIC_Wait_Ack();//等待应答
	IIC_Stop();
	delay_ms(10);
}
/*
*********************************************************************************************************
*	函 数 名: SHT3X_SetPeriodicMeasurement
*	功能说明: 设置SHT3X的周期读取方式
*	形    参：cmd 命令
*	返 回 值: 无
*********************************************************************************************************
*/
void SHT3X_SetPeriodicMeasurement(void)
{
	SHT3X_WriteCMD(CMD_MEAS_PERI_2_H);//高重现性，每秒读两次数据
}

/*
*********************************************************************************************************
*	函 数 名: SHX3X_ReadResults
*	功能说明: 读取数据
*	形    参：uint16_t cmd为读取方式，uint8_t *p存放数组的指针
*	返 回 值: 无
*********************************************************************************************************
*/
void SHX3X_ReadResults(uint16_t cmd,uint8_t *p)
{
	u8 i = 0;
	u8 ack = 0;
	IIC_Start();
	IIC_Send_Byte(cmd);
	IIC_Wait_Ack();
	IIC_Send_Byte(cmd>>8);
	IIC_Wait_Ack();
	IIC_Send_Byte(cmd);
	IIC_Wait_Ack();
	IIC_Stop();

	delay_ms(100);
	IIC_Start();
	IIC_Send_Byte(i2cAddRead_8bit);//发送读地址
	IIC_Wait_Ack();
	
	for(i=0;i<6;i++)
	{
		if(i<5)
		{
			ack = 1;
		}
		else
		{
			ack = 0;
		}
		p[i] = IIC_Read_Byte(ack);
	}
	IIC_Stop();
	delay_ms(100);
}
/*
*********************************************************************************************************
*	函 数 名: bsp_InitSht3x
*	功能说明: 初始化SHT3x
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_InitSht3x(void)
{
	delay_ms(100);//必须加入延时
	SHT3X_SetPeriodicMeasurement();//设置SHT3X的周期读取方式
	delay_ms(100);//必须加入延时
}

/*
*********************************************************************************************************
*	函 数 名: SHT3X_GetValue
*	功能说明: SHT3X获取数值
*	形    参：无
*	返 回 值: 1错误，0正确
*********************************************************************************************************
*/
uint8_t SHT3X_GetValue(void)
{
	uint8_t p[6];
	float cTemp,humidity;//摄氏度和湿度
	SHX3X_ReadResults(CMD_MEAS_CLOCKSTR_H,p);
	cTemp=((((p[0]*256.0)+p[1])*175)/65535.0)-45;//摄氏度
	humidity=((((p[3]*256.0)+p[4])*100)/65535.0);//湿度
	Tem_Value = cTemp;
	RH_Value = humidity;
	
	if(Tem_Value > 129)//错误发生，初始化，法昂县错误时，温度为130度，湿度为100
	{
		return 1;
	}
	return 0;
}
///////////////////////////////////////

/***************************** 德致伦电子 DeZLinc (END OF FILE) *********************************/
