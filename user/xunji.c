/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：xunji.c
*
* 当前版本：V1.8
* 作    者：范子琦
* 完成日期：2020年10月13日09:00
******************************************************/

#include <msp430.h>
#include <xunji.h>
#include <pwm.h>

#define CPU_F                               ((double)8000000)
#define delay_us(x)                       __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x)                      __delay_cycles((long)(CPU_F*(double)x/1000.0))

int white=0;

//循迹函数，黑色返回1，白色返回0，左轮为p1，右轮为p2。 灰度顺序为12345678
//输入直行速度v控制上坡时间

void pid_track_zhixian_0(int v)
{
    //传感器34、45、56、345、456、3456碰到黑线停止
    if((D2&&D3)||(D3&&D4)||(D4&&D5)||(D2&&D3&&D4)||(D3&&D4&&D5)||(D2&&D3&&D4&&D5))
    {
        if(white>100)
        {
            motor10(3,3,0,0);
            TA2CCR1 = 50;
            while(1);
        }
    }

    // 车偏右
    else if(D3) motor10(0,1,50,70);
    else if(D2) motor10(0,1,60,80);
    else if(D1) motor10(0,1,100,100);
//    else if(D1) motor10(0,1,100,100);

    // 车偏左
    else if(D4) motor10(1,0,70,50);
    else if(D5) motor10(1,0,80,60);
    else if(D6) motor10(1,0,90,90);
    else if(D7) motor10(1,0,100,100);
    else if(D7) motor10(1,0,100,100);

    // 其他情况直行
    else
    {
        motor10(1,1,v,v);
        white+=1;
    }
}

void pid_track_zhixian_up(int v)
{
    //传感器34、45、56、345、456、3456碰到黑线停止
    if((D3&&D4)||(D4&&D5)||(D5&&D6)||(D3&&D4&&D5)||(D4&&D5&&D6)||(D3&&D4&&D5&&D6))
    {
        if(white>100)
        {
            motor10(3,3,0,0);
            TA2CCR1 = 50;
            while(1);
//            stop=1;
        }
    }

    // 车偏右
    else if(D4) motor10(1,1,10,30);
    else if(D3) motor10(1,1,30,50);
    else if(D2) motor10(0,1,60,80);
    else if(D1) motor10(0,1,80,100);

    // 车偏左
    else if(D5) motor10(1,1,30,10);
    else if(D6) motor10(1,1,50,30);
    else if(D7) motor10(1,0,80,60);
    else if(D8) motor10(1,0,100,80);

    // 其他情况直行
    else
    {
        motor10(1,1,v,v);
        white+=1;
    }
}

//将光电返回的八位二进制数转成0和1便于if判断
int digtal(int channel)
{
    int value = 0;
    switch(channel)
    {
        //8路灰度
        case 1:
            if(P3IN & BIT0) value = 1;
            else value = 0;
            break;
        case 2:
            if(P3IN & BIT1) value = 1;
            else value = 0;
            break;
        case 3:
            if(P3IN & BIT2) value = 1;
            else value = 0;
            break;
        case 4:
            if(P3IN & BIT3) value = 1;
            else value = 0;
            break;
        case 5:
            if(P3IN & BIT4) value = 1;
            else value = 0;
            break;
        case 6:
            if(P3IN & BIT5) value = 1;
            else value = 0;
            break;
        case 7:
            if(P3IN & BIT6) value = 1;
            else value = 0;
            break;
        case 8:
            if(P3IN & BIT7) value = 1;
            else value = 0;
            break;
        //p1.1和p2.1板载按键
        case 11:
            if(P1IN & BIT1) value = 1;
            else value = 0;
            break;
        case 21:
            if(P2IN & BIT1) value = 1;
            else value = 0;
            break;
        //P4.1外接按键
//        case 41:
//            if(P4IN & BIT1) value = 1;
//            else value = 0;
//            break;
//        case 42:
//            if(P4IN & BIT2) value = 1;
//            else value = 0;
//            break;

        case 20:
            if(P2IN & BIT0) value = 1;
            else value = 0;
            break;
        case 22:
            if(P2IN & BIT2) value = 1;
            else value = 0;
            break;
        case 26:
            if(P2IN & BIT6) value = 1;
            else value = 0;
            break;
    }
    return value;
}
