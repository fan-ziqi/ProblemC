/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：pid.c
*
* 当前版本：V3.0
* 作    者：范子琦
* 完成日期：2020年10月13日10:00
******************************************************/

#include <msp430.h>
#include <math.h>
#include <stdlib.h>
unsigned int cap_tar,cap_first,cap_last,time,pluse,flag=0,temp1;
float speed,Uk,vis=0,temp2=0;
/*******************************************
函数名称：定时器中断服务函数
功    能：用于捕捉传感器的脉冲信号
参    数：无
返回值  ：无
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
函数名称：Count_speed
功    能：计算实际转速
参    数：无
返回值  ：实际转速
********************************************/
float Pid_speed()
{
    return 0;
}  
/*******************************************
函数名称：增量式PID控制程序
功    能：用PID反馈控制输出一个反馈控制量
参    数：无
返回值  ：UK控制量
********************************************/   
struct _pid{
float SetSpeed;//定义设定值
float ActualSpeed;//定义实际值
float err0,err1,err2; //定义偏差值
float Kp,Ki,Kd;//定义比例、积分、微分系数
float Uk0,Uk1;//控制执行器的变量
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
