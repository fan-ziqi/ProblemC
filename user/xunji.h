/*****************************************************
* Copyright(C) 2020 ����ɽ��˾��
* All rights reserved.
*
* �ļ����ƣ�xunji.h
*
* ��ǰ�汾��V1.8
* ��    �ߣ�������
* ������ڣ�2020��10��13��09:00
******************************************************/

#ifndef __XUNJI_H__
#define __XUNJI_H__

#define D1 digtal(1)
#define D2 digtal(2)
#define D3 digtal(3)
#define D4 digtal(4)
#define D5 digtal(5)
#define D6 digtal(6)
#define D7 digtal(7)
#define D8 digtal(8)

////ֱ���жϰ�λ�����Ʒ���ֵ��������&�жϣ������ú���ת��
//#define D1 P3IN&BIT0
//#define D2 P3IN&BIT1
//#define D3 P3IN&BIT2
//#define D4 P3IN&BIT3
//#define D5 P3IN&BIT4
//#define D6 P3IN&BIT5
//#define D7 P3IN&BIT6
//#define D8 P3IN&BIT7

void pid_track_zhixian(int v);
void pid_track_zhixian_0(int v);
void pid_track_zhixian_up(int v);
void test_huidu();
int digtal(int channel);

#endif
