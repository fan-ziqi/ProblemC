/*****************************************************
* Copyright(C) 2020 ����ɽ��˾��
* All rights reserved.
*
* �ļ����ƣ�main.c
*
* ��ǰ�汾��V3.0
* ��    �ߣ�������
* ������ڣ�2020��10��13��10:00
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
    WDTCTL = WDTPW + WDTHOLD; //�رտ��Ź�
    unsigned char time=10;  //ʱ��ѡ��-��λs
    unsigned char degree=0; //�Ƕ�ѡ��-��λ��
    int mode=1; //ģʽѡ��
    int start=1; //start��־
    int p=10; //pֵ��������
    All_Config(); //���еĳ�ʼ������

    while(1)
    {
      //start==1��С����ֹ������ͨ�������ı�degree��time
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
            if(digtal(21)==1) mode*=-1; //���水������
        }
        if(digtal(11)==0)
        {
            delay_ms(30);
            if(digtal(11)==1) p+=1;//����1.1���£�p+1
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
      //start==-1��С����ʼѭ��
      else
      {
          if(mode==1) pid_track_zhixian_0(p); //1��0-15�Ƕ�
          else pid_track_zhixian_up(p); //-1��15-30�Ƕ�
      }
      Pid_speed();
    }
}
