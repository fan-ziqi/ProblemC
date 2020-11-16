/*****************************************************
* Copyright(C) 2020 ����ɽ��˾��
* All rights reserved.
*
* �ļ����ƣ�xunji.c
*
* ��ǰ�汾��V1.8
* ��    �ߣ�������
* ������ڣ�2020��10��13��09:00
******************************************************/

#include <msp430.h>
#include <xunji.h>
#include <pwm.h>

#define CPU_F                               ((double)8000000)
#define delay_us(x)                       __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x)                      __delay_cycles((long)(CPU_F*(double)x/1000.0))

int white=0;

//ѭ����������ɫ����1����ɫ����0������Ϊp1������Ϊp2�� �Ҷ�˳��Ϊ12345678
//����ֱ���ٶ�v��������ʱ��

void pid_track_zhixian_0(int v)
{
    //������34��45��56��345��456��3456��������ֹͣ
    if((D2&&D3)||(D3&&D4)||(D4&&D5)||(D2&&D3&&D4)||(D3&&D4&&D5)||(D2&&D3&&D4&&D5))
    {
        if(white>100)
        {
            motor10(3,3,0,0);
            TA2CCR1 = 50;
            while(1);
        }
    }

    // ��ƫ��
    else if(D3) motor10(0,1,50,70);
    else if(D2) motor10(0,1,60,80);
    else if(D1) motor10(0,1,100,100);
//    else if(D1) motor10(0,1,100,100);

    // ��ƫ��
    else if(D4) motor10(1,0,70,50);
    else if(D5) motor10(1,0,80,60);
    else if(D6) motor10(1,0,90,90);
    else if(D7) motor10(1,0,100,100);
    else if(D7) motor10(1,0,100,100);

    // �������ֱ��
    else
    {
        motor10(1,1,v,v);
        white+=1;
    }
}

void pid_track_zhixian_up(int v)
{
    //������34��45��56��345��456��3456��������ֹͣ
    if((D3&&D4)||(D4&&D5)||(D5&&D6)||(D3&&D4&&D5)||(D4&&D5&&D6)||(D3&&D4&&D5&&D6))
    {
        if(white>100)
        {
            motor10(3,3,0,0);
            TA2CCR1 = 50;
            while(1);
//            stop=1;
        }
    }

    // ��ƫ��
    else if(D4) motor10(1,1,10,30);
    else if(D3) motor10(1,1,30,50);
    else if(D2) motor10(0,1,60,80);
    else if(D1) motor10(0,1,80,100);

    // ��ƫ��
    else if(D5) motor10(1,1,30,10);
    else if(D6) motor10(1,1,50,30);
    else if(D7) motor10(1,0,80,60);
    else if(D8) motor10(1,0,100,80);

    // �������ֱ��
    else
    {
        motor10(1,1,v,v);
        white+=1;
    }
}

//����緵�صİ�λ��������ת��0��1����if�ж�
int digtal(int channel)
{
    int value = 0;
    switch(channel)
    {
        //8·�Ҷ�
        case 1:
            if(P3IN & BIT0) value = 1;
            else value = 0;
            break;
        case 2:
            if(P3IN & BIT1) value = 1;
            else value = 0;
            break;
        case 3:
            if(P3IN & BIT2) value = 1;
            else value = 0;
            break;
        case 4:
            if(P3IN & BIT3) value = 1;
            else value = 0;
            break;
        case 5:
            if(P3IN & BIT4) value = 1;
            else value = 0;
            break;
        case 6:
            if(P3IN & BIT5) value = 1;
            else value = 0;
            break;
        case 7:
            if(P3IN & BIT6) value = 1;
            else value = 0;
            break;
        case 8:
            if(P3IN & BIT7) value = 1;
            else value = 0;
            break;
        //p1.1��p2.1���ذ���
        case 11:
            if(P1IN & BIT1) value = 1;
            else value = 0;
            break;
        case 21:
            if(P2IN & BIT1) value = 1;
            else value = 0;
            break;
        //P4.1��Ӱ���
//        case 41:
//            if(P4IN & BIT1) value = 1;
//            else value = 0;
//            break;
//        case 42:
//            if(P4IN & BIT2) value = 1;
//            else value = 0;
//            break;

        case 20:
            if(P2IN & BIT0) value = 1;
            else value = 0;
            break;
        case 22:
            if(P2IN & BIT2) value = 1;
            else value = 0;
            break;
        case 26:
            if(P2IN & BIT6) value = 1;
            else value = 0;
            break;
    }
    return value;
}
