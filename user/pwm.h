/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：pwm.h
*
* 当前版本：V1.8
* 作    者：范子琦
* 完成日期：2020年10月13日09:00
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
