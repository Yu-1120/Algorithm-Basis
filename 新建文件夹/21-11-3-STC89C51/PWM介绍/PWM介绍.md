# PWM介绍

## 目录

-   [产生PWM方法](#产生PWM方法 "产生PWM方法")
-   [代码](#代码 "代码")

\<!---->

-   PWM（Pulse?Width?Modulation）即脉冲宽度调制，在具有惯性的 系统中，可以通过对一系列脉冲的宽度进行调制，来等效地获得所 需要的模拟参量，常应用于电机控速、开关电源等领域 • PWM重要参数： 频率 =1/ Ts

占空比=Ton/Ts

精度=占空比变化步距

![](image/eme6s2tsjn_y38Rqc689l_5Os8S9WNa6.png)

# 产生PWM方法

![](image/w2iujhot1i_j7aeEQQlIa_rH0TjbvAu2.png)

# 代码

通过延时的时间来调节PWN的占空比

![](image/87ne3ngs4n_1Dr7Y9J2rS_hvXNv-Xttt.png)

```纯文本
#include <REGX52.H>

sbit LED=P2^0;

void Delay(unsigned int t)
{
    while(t--);
}

void main()
{
    unsigned char Time,i;
    while(1)
    {
        for(Time=0;Time<100;Time++)     //改变亮灭时间，由暗到亮
        {
            for(i=0;i<20;i++)           //计次延时
            {
                LED=0;                  //LED亮
                Delay(Time);            //延时Time
                LED=1;                  //LED灭
                Delay(100-Time);        //延时100-Time
            }
        }
        for(Time=100;Time>0;Time--)     //改变亮灭时间，由亮到暗
        {
            for(i=0;i<20;i++)           //计次延时
            {
                LED=0;                  //LED亮
                Delay(Time);            //延时Time
                LED=1;                  //LED灭
                Delay(100-Time);        //延时100-Time
            }
        }
    }
}
```

没用AD的话是通过亮灭来实现的呼吸灯，用AD是通过不同的占空比输出不同电压实现的呼吸灯
