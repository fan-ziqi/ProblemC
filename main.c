/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：main.c
*
* 当前版本：V3.0
* 作    者：范子琦
* 完成日期：2020年10月13日10:00
******************************************************/

#include <msp430.h>
#include <oled.h>
#include <type.h>
#include <xunji.h>
#include <pwm.h>
#include <config.h>
#include <test.h>
#include <pid.h>

#define CPU_F                               ((double)8000000)
#define delay_us(x)                       __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x)                      __delay_cycles((long)(CPU_F*(double)x/1000.0))

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; //关闭看门狗
    unsigned char time=10;  //时间选择-单位s
    unsigned char degree=0; //角度选择-单位°
    int mode=1; //模式选择
    int start=1; //start标志
    int p=10; //p值按键控制
    All_Config(); //所有的初始化函数

    while(1)
    {
      //start==1，小车静止，可以通过按键改变degree和time
      if(start==1)
      {
        Motor_Left_Stop();
        Motor_Right_Stop();
        if(digtal(26)==0)
        {
            delay_ms(30);
            if(digtal(21)==1) start*=-1; //2.6,start
        }
        if(digtal(21)==0)
        {
            delay_ms(30);
            if(digtal(21)==1) mode*=-1; //左面按键按下
        }
        if(digtal(11)==0)
        {
            delay_ms(30);
            if(digtal(11)==1) p+=1;//按键1.1按下，p+1
        }
        if(p>=100) p=100;
        if(p<=0) p=0;
        if(digtal(20)==0)
        {
            delay_ms(30);
            if(digtal(20)==1)
            {
                if (time<21) time+=1;
                else time=10;
            }
        }
        if(digtal(22)==0)
        {
            delay_ms(30);
            if(digtal(22)==1)
            {
               if (degree<40) degree+=1;
               else degree=0;
             }
        }
        OLED_WORK(time);
        OLED_WORK2(degree);
        OLED_WORK3(p,mode);
      }
      //start==-1，小车开始循迹
      else
      {
          if(mode==1) pid_track_zhixian_0(p); //1，0-15角度
          else pid_track_zhixian_up(p); //-1，15-30角度
      }
      Pid_speed();
    }
}
