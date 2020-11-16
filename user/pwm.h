/*****************************************************
* Copyright(C) 2020 ����ɽ��˾��
* All rights reserved.
*
* �ļ����ƣ�pwm.h
*
* ��ǰ�汾��V1.8
* ��    �ߣ�������
* ������ڣ�2020��10��13��09:00
******************************************************/

#ifndef __PWM_H__
#define __PWM_H__

void motor10 (int dir1, int dir2, int pwm1,  int pwm2);
void Motor_Left_Forward (void);
void Motor_Left_Backward (void);
void Motor_Right_Forward (void);
void Motor_Right_Backward (void);
void Motor_Left_Stop (void);
void Motor_Right_Stop (void);

#endif
