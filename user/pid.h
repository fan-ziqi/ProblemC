/*****************************************************
* Copyright(C) 2020 ����ɽ��˾��
* All rights reserved.
*
* �ļ����ƣ�pid.h
*
* ��ǰ�汾��V1.8
* ��    �ߣ�������
* ������ڣ�2020��10��13��09:00
******************************************************/

#ifndef __PID_H__
#define __PID_H__

void PID_init();
float Pid_speed();
float PID_realize(float ActuaSpeed);


#endif
