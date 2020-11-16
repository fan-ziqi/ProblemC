/*****************************************************
* Copyright(C) 2020 ����ɽ��˾��
* All rights reserved.
*
* �ļ����ƣ�pwm.c
*
* ��ǰ�汾��V1.8
* ��    �ߣ�������
* ������ڣ�2020��10��13��09:00
******************************************************/

#include <msp430.h>
#include <pwm.h>

//���Ƶ��������
void Motor_Left_Forward (void) //��ߵ����ת
{
    P1OUT|=BIT5;//1
    P1OUT=~BIT4;//0
}
void Motor_Left_Backward (void) //��ߵ����ת
{
    P1OUT|=BIT4;//1
    P1OUT=~BIT5;//0
}
void Motor_Right_Forward (void) //�ұߵ����ת
{
     P6OUT|=BIT4;//1
     P6OUT=~BIT3;//0
}
void Motor_Right_Backward (void) //�ұߵ����ת
{
    P6OUT|=BIT3;//1
    P6OUT=~BIT4;//0
}
//���Ƶ��ֹͣ
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


//�����������
//dir1->����״̬��dir2->�ҵ��״̬��1��ת��0��ת��3ֹͣ
//p1->�����ٶȣ�p2->�ҵ���ٶȣ��ٶ�ֵ����0-100��ת��Ϊ0-255
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
