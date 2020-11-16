/*****************************************************
* Copyright(C) 2020 秋名山老司机
* All rights reserved.
*
* 文件名称：config.c
*
* 当前版本：V1.8
* 作    者：范子琦
* 完成日期：2020年10月13日09:00
******************************************************/

#include <msp430.h>
#include <oled.h>
#include <pid.h>

#define CPU_F                               ((double)8000000)
#define delay_us(x)                       __delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define delay_ms(x)                      __delay_cycles((long)(CPU_F*(double)x/1000.0))

//GPIO初始化函数
void GPIO_Config(void)
{
    //1-8 灰度
    P3DIR &=~BIT0;
    P3DIR &=~BIT1;
    P3DIR &=~BIT2;
    P3DIR &=~BIT3;
    P3DIR &=~BIT4;
    P3DIR &=~BIT5;
    P3DIR &=~BIT6;
    P3DIR &=~BIT7;

    //key1.1
    P1DIR &=~BIT1;
    P1REN |= BIT1;
    P1OUT |= BIT1;
    P1IES = BIT1;
    P1IE=BIT1;
    P1IFG=0;

    //key2.1
    P2DIR &=~BIT1;
    P2REN |= BIT1;
    P2OUT |= BIT1;
    P2IES = BIT1;
    P2IE=BIT1;
    P2IFG=0;

    //key2.0
    P2DIR &=~BIT0;
    P2REN |= BIT0;
    P2OUT |= BIT0;
    P2IES = BIT0;
    P2IE=BIT0;
    P2IFG=0;

    //key2.2
    P2DIR &=~BIT2;
    P2REN |= BIT2;
    P2OUT |= BIT2;
    P2IES = BIT2;
    P2IE=BIT2;
    P2IFG=0;

    //key1.6
    P1DIR &=~BIT6;
    P1REN |= BIT6;
    P1OUT |= BIT6;
    P1IES = BIT6;
    P1IE=BIT6;
    P1IFG=0;

    //key2.6
    P2DIR &=~BIT6;
    P2REN |= BIT6;
    P2OUT |= BIT6;
    P2IES = BIT6;
    P2IE=BIT6;
    P2IFG=0;

//    //key4.1
//    P4DIR &=~BIT1;
//    P4OUT|=BIT1;
//
//    //key4.2
//    P4DIR &=~BIT2;
//    P4OUT|=BIT2;

    P6DIR|=BIT3+BIT4; ////P6.3 P6.4 输出 左轮方向
    P1DIR|=BIT4+BIT5; ////P1.4 P6.5 输出 右轮方向
    P2DIR|=BIT4;//beep

    //led1.0，测试用
    P1DIR|=BIT0;
    P1OUT &= ~BIT0;
}

void Motor_Config(void)
{
    //左轮p初始化 P1.2
    /*设置时钟源为SMCLK*/
    TA0CTL |= TASSEL1;
    /*设置工作模式为Up&Down*/
    TA0CTL |= MC0|MC1;
    /*设置TA0CCR0为0x00FF*/
    TA0CCR0 = 0x00FF;
    /*设置TA0CCR1为0x00FF*/
    TA0CCR1 = 0x00FF;//占空比(TACCR0 - TACCR2) / TACCR0,频率=SMCLK/(TACCR0+1)/2   2
    /*设置为比较模式*/
    TA0CCTL0 &= ~CAP;
    TA0CCTL1 &= ~CAP;
    /*设置比较输出模式*/
    TA0CCTL1 |= OUTMOD_6;
    /*设置IO复用*/
    P1SEL |= BIT2;
    P1DIR |= BIT2;

    //右轮p初始化 P1.3
    /*设置时钟源为SMCLK*/
    TA0CTL |= TASSEL1;
    /*设置工作模式为Up&Down*/
    TA0CTL |= MC0|MC1;
    /*设置TA0CCR0为0x00FF*/
    TA0CCR0 = 0x00FF;
    /*设置TA0CCR1为0x00FF*/
    TA0CCR2 = 0x00FF;//占空比(TACCR0 - TACCR2) / TACCR0,频率=SMCLK/(TACCR0+1)/2   2
    /*设置为比较模式*/
    TA0CCTL0 &= ~CAP;
    TA0CCTL0 &= ~CAP;
    /*设置比较输出模式*/
    TA0CCTL2 |= OUTMOD_6;
    /*设置IO复用*/
    P1SEL |= BIT3;
    P1DIR |= BIT3;

    //左轮p初始化 P2.4
    /*设置时钟源为SMCLK*/
    TA2CTL |= TASSEL1;
    /*设置工作模式为Up&Down*/
    TA2CTL |= MC0|MC1;
    /*设置TA0CCR0为0x00FF*/
    TA2CCR0 = 0x00FF;
    /*设置TA0CCR1为0x00FF*/
    TA2CCR1 = 0x00FF;//占空比(TACCR0 - TACCR2) / TACCR0,频率=SMCLK/(TACCR0+1)/2   2
    /*设置为比较模式*/
    TA2CCTL0 &= ~CAP;
    TA2CCTL1 &= ~CAP;
    /*设置比较输出模式*/
    TA2CCTL1 |= OUTMOD_6;
    /*设置IO复用*/
    P2SEL |= BIT4;
    P2DIR |= BIT4;
}

void All_Config(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
    TA2CCR1 = 255;
    GPIO_Config();
    Motor_Config();
    OLED_Init();
    OLED_Clear();
    PID_init();
}
