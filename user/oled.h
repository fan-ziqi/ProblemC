/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：oled.h
*
* 当前版本：V1.0
* 作    者：季文茜
* 完成日期：2020年10月12日20:00
******************************************************/

#ifndef __OLED_H
#define __OLED_H
#include <msp430.h>
#include "type.h"
#define OLED_MODE 0
#define SIZE 8
#define XLevelL     0x00
#define XLevelH     0x10
#define Max_Column  128
#define Max_Row     64
#define Brightness  0xFF
#define X_WIDTH     128
#define Y_WIDTH     64

#define OLED_SCLK_Clr() P4OUT&=~BIT3  //CLK
#define OLED_SCLK_Set() P4OUT|=BIT3

#define OLED_SDIN_Clr() P4OUT&=~BIT0  //DIN
#define OLED_SDIN_Set() P4OUT|=BIT0

#define OLED_CMD  0
#define OLED_DATA 1

// Functions to control OLED are as follows
void OLED_WR_Byte(unsigned dat,unsigned cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_WORK(u32 t);
void OLED_WORK2(u32 t);
void OLED_WORK3(u32 t,u32 m);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowVI(u8 x,u8 y,u32 num,u8 size);
void OLED_ShowString(u8 x,u8 y, u8 *p,u8 Char_Size);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void Delay_1ms(unsigned int Del_1ms);
void fill_picture(unsigned char fill_Data);
void Picture();
void IIC_Start();
void IIC_Stop();
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);
void Write_IIC_Byte(unsigned char IIC_Byte);
void IIC_Wait_Ack();
#endif
