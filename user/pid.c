/*****************************************************
* Copyright(C) 2020 ����ɽ��˾��
* All rights reserved.
*
* �ļ����ƣ�pid.c
*
* ��ǰ�汾��V3.0
* ��    �ߣ�������
* ������ڣ�2020��10��13��10:00
******************************************************/

#include <msp430.h>
#include <math.h>
#include <stdlib.h>
unsigned int cap_tar,cap_first,cap_last,time,pluse,flag=0,temp1;
float speed,Uk,vis=0,temp2=0;
/*******************************************
�������ƣ���ʱ���жϷ�����
��    �ܣ����ڲ�׽�������������ź�
��    ������
����ֵ  ����
********************************************/
//#pragma vector=TIMERA0_VECTOR
//__interrupt void timerA0(void)
//{
//  if(cap_tar==0)
//  {
//    cap_first=TACCR0;
//    cap_tar++;
//  }
//  else
//  {
//    cap_last=TACCR0;
//    cap_tar++;
//    flag=1;
//  }
//}
//#pragma vector=TIMERA1_VECTOR
//__interrupt void timerA1(void)
//{
//  switch(TAIV)
//  {
//  case 2:break;
//  case 4:break;
//  case 10:
//    {
//       if(cap_last>cap_first)
//        {
//         if(cap_tar==0)
//            pluse=0;
//         else
//          {
//            pluse=cap_tar-1;
//            time=cap_last-cap_first;
//            cap_tar=0;
//          }
//        }
//      }
//    break;
//  }
//}
/*******************************************
�������ƣ�Count_speed
��    �ܣ�����ʵ��ת��
��    ������
����ֵ  ��ʵ��ת��
********************************************/
float Pid_speed()
{
    return 0;
}  
/*******************************************
�������ƣ�����ʽPID���Ƴ���
��    �ܣ���PID�����������һ������������
��    ������
����ֵ  ��UK������
********************************************/   
struct _pid{
float SetSpeed;//�����趨ֵ
float ActualSpeed;//����ʵ��ֵ
float err0,err1,err2; //����ƫ��ֵ
float Kp,Ki,Kd;//������������֡�΢��ϵ��
float Uk0,Uk1;//����ִ�����ı���
}pid;
void PID_init(){
pid.SetSpeed=0.0;
        pid.ActualSpeed=0.0;
pid.err0=0.0;
pid.err1=0.0;
        pid.err2=0.0;
pid.Uk0=0.0;
        pid.Uk1=0.0;
pid.Kp=8;
pid.Ki=3;
pid.Kd=1;      
}        
float PID_realize(float ActuaSpeed)
{
  pid.SetSpeed=3000;
  pid.ActualSpeed=ActuaSpeed;
  pid.err0 = pid.SetSpeed - pid.ActualSpeed;
  pid.Uk0 = pid.Uk1+pid.Kp*(pid.err0-pid.err1)+pid.Ki*pid.err0+pid.Kd*(pid.err0-pid.err1-pid.err1+pid.err2);
  if(pid.Uk0>1023)
  {
    pid.Uk0=1023;   
  }
  if(pid.Uk0<0)   
  {
    pid.Uk0=1;
  }
  pid.Uk1 = pid.Uk0;
  pid.err2 = pid.err1;
  pid.err1 = pid.err0;
  Uk = pid.Uk0;
  return Uk;  
}
