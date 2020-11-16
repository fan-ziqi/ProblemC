/*****************************************************
* Copyright(C) 2020 ����ɽ��˾��
* All rights reserved.
*
* �ļ����ƣ�test.c
*
* ��ǰ�汾��V1.8
* ��    �ߣ�������
* ������ڣ�2020��10��13��09:00
******************************************************/

#include <msp430.h>
#include <pwm.h>
#include <xunji.h>

#define CPU_F                               ((double)8000000)
#define delay_us(x)                       __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x)                      __delay_cycles((long)(CPU_F*(double)x/1000.0))

//�ҶȲ��Ժ���
void test_huidu(void)
{
    //������
    if(D1) motor10(1,1,80,80); //��ɫ->1
    else motor10(3,3,0,0); //��ɫ->0
      //�ƹ����
//    if(D1) P1OUT &= ~BIT0;
//    else P1OUT |= BIT0;
}

//�����Ժ���
void test_gd(void)
{
    if(D4) P1OUT &= ~BIT0;
    else P1OUT |= BIT0;
}

//�������Ժ���
void test_key(void)
{
    if(digtal(20)) P1OUT &= ~BIT0;//Ϩ��LED
    else P1OUT |= BIT0;//����LED
}

//������Ժ���
void test_motor(void)
{
    motor10(1,1,20,20);
    delay_ms(100);
    motor10(3,3,0,0);
    delay_ms(100);
    motor10(0,0,20,20);
    delay_ms(100);
    motor10(3,3,0,0);
    delay_ms(100);
}
