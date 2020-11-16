/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：pid.h
*
* 当前版本：V1.8
* 作    者：范子琦
* 完成日期：2020年10月13日09:00
******************************************************/

#ifndef __PID_H__
#define __PID_H__

void PID_init();
float Pid_speed();
float PID_realize(float ActuaSpeed);


#endif
