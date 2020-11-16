/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：pwm.c
*
* 当前版本：V1.8
* 作    者：范子琦
* 完成日期：2020年10月13日09:00
******************************************************/

#include <msp430.h>
#include <pwm.h>

//控制电机方向函数
void Motor_Left_Forward (void) //左边电机正转
{
    P1OUT|=BIT5;//1
    P1OUT=~BIT4;//0
}
void Motor_Left_Backward (void) //左边电机反转
{
    P1OUT|=BIT4;//1
    P1OUT=~BIT5;//0
}
void Motor_Right_Forward (void) //右边电机正转
{
     P6OUT|=BIT4;//1
     P6OUT=~BIT3;//0
}
void Motor_Right_Backward (void) //右边电机反转
{
    P6OUT|=BIT3;//1
    P6OUT=~BIT4;//0
}
//控制电机停止
void Motor_Left_Stop (void)
{
     P1OUT|=BIT4;//0
     P1OUT|=BIT5;//0P
}
void Motor_Right_Stop (void)
{
     P6OUT|=BIT3;//0
     P6OUT|=BIT4;//0
}


//电机驱动函数
//dir1->左电机状态，dir2->右电机状态，1正转，0反转，3停止
//p1->左电机速度，p2->右电机速度，速度值输入0-100，转换为0-255
void motor10 (int dir1, int dir2, int pwm1,  int pwm2)
{
    TA0CCR1 = 255-(pwm1*255)/100;
    TA0CCR2 = 255-(pwm2*255)/100;

    switch(dir1)
    {
        case 1:  Motor_Left_Forward (); break;
        case 0:  Motor_Left_Backward (); break;
        case 3:  Motor_Left_Stop (); break;
    }
    switch(dir2)
    {
        case 1:  Motor_Right_Forward (); break;
        case 0:  Motor_Right_Backward (); break;
        case 3:  Motor_Right_Stop (); break;
    }
}
