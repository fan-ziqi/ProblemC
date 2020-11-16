/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：test.c
*
* 当前版本：V1.8
* 作    者：范子琦
* 完成日期：2020年10月13日09:00
******************************************************/

#include <msp430.h>
#include <pwm.h>
#include <xunji.h>

#define CPU_F                               ((double)8000000)
#define delay_us(x)                       __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x)                      __delay_cycles((long)(CPU_F*(double)x/1000.0))

//灰度测试函数
void test_huidu(void)
{
    //马达测试
    if(D1) motor10(1,1,80,80); //黑色->1
    else motor10(3,3,0,0); //白色->0
      //灯光测试
//    if(D1) P1OUT &= ~BIT0;
//    else P1OUT |= BIT0;
}

//光电测试函数
void test_gd(void)
{
    if(D4) P1OUT &= ~BIT0;
    else P1OUT |= BIT0;
}

//按键测试函数
void test_key(void)
{
    if(digtal(20)) P1OUT &= ~BIT0;//熄灭LED
    else P1OUT |= BIT0;//点亮LED
}

//电机测试函数
void test_motor(void)
{
    motor10(1,1,20,20);
    delay_ms(100);
    motor10(3,3,0,0);
    delay_ms(100);
    motor10(0,0,20,20);
    delay_ms(100);
    motor10(3,3,0,0);
    delay_ms(100);
}
