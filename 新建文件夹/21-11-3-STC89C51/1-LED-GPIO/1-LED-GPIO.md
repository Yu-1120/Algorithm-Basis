# 1-LED-GPIO

## 目录

-   [GPIO概念](#GPIO概念 "GPIO概念")
    -   [P0端口](#P0端口 "P0端口")
    -   [P1端口](#P1端口 "P1端口")
    -   [P2](#P2 "P2")
    -   [P3](#P3 "P3")
-   [LED](#LED "LED")
-   [LED点亮](#LED点亮 "LED点亮")
-   [LED闪烁](#LED闪烁 "LED闪烁")
-   [LED流水灯](#LED流水灯 "LED流水灯")

# GPIO概念

GPIO（general purpose intput output）是通用输入输出端口的简称，可 以通过软件来控制其输入和输出。

（1）电源引脚   VCC GND
（2）晶振引脚  XTAL1  XTAL2
（3）复位引脚  RST
（4）下载引脚    复用的串口输入和输出  P3.0  和 P3.1
（5）GPIO引脚

## P0端口

![](image/oa8bwx7u8b_fF3rrtsTOV_NK-PXMkqz2.png)

P0是外接上拉电阻才能输出高电平(**`在PCB设计的时候最好要把他外面接一个上拉电阻给他)`**

P0口输出

![](image/l5hzx0t9ie_HHqDPQD-no_vf_F1ex4Tk.png)

P0口输入

## P1端口

![](image/43wxrqaru5_yDl-7LfVGx__OCrzeQ_bA.png)

P1口有静态锁存的口（内部默认上拉的）

## P2

![](image/v1y_73_jyu_sFQ_4LMDoV__EGp2KiiYo.png)

## P3

![](image/5k5r7a1mxv_xWkTHnqhlm_Tq2bm659Km.png)

# LED

可以通过的电流的大侠殴`3-20ma`，大概`1.7v`两端压降（导通压降），大概`5ma`就可以发光，电流太大会烧坏

led要限流电阻，阻值是经验值

![](image/mfvyaymdl5_2cYJx62b-1_ZwMmVJTscw.png)

# LED点亮

```纯文本
#include <REGX52.H>

void main()
{
    P2=0xFE;    //1111 1110
    while(1)
    {

    }
}

```

# LED闪烁

```C
#include <REGX52.H>
#include <INTRINS.H>

void Delay500ms()        //@12.000MHz
{
    unsigned char i, j, k;

    _nop_();
    i = 4;
    j = 205;
    k = 187;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

void main()
{
    while(1)
    {
        P3_6 =1;    //1111 1110
        Delay500ms();
        P3_6= 0;    //1111 1111
        Delay500ms();
    }
}

```

![](image/weleq0vl84_BQvmbkMsJ4_9aI7lQPlHL.png)

STC89C52  12Mhz晶振

# LED流水灯

![](image/08nulu3djg_PjqjqS8CPC_Uv14peJ53o.png)

```C
#include <REGX52.H>
#include <INTRINS.H>

void Delay500ms()        //@12.000MHz
{
    unsigned char i, j, k;

    _nop_();
    i = 4;
    j = 205;
    k = 187;
    do
    {
        do
        {
            while (--k);
        } while (--j);
    } while (--i);
}

void main()
{
    while(1)
    {
        P2=0xFE;//1111 1110
        Delay500ms();
        P2=0xFD;//1111 1101
        Delay500ms();
        P2=0xFB;//1111 1011
        Delay500ms();
        P2=0xF7;//1111 0111
        Delay500ms();
        P2=0xEF;//1110 1111
        Delay500ms();
        P2=0xDF;//1101 1111
        Delay500ms();
        P2=0xBF;//1011 1111
        Delay500ms();
        P2=0x7F;//0111 1111
        Delay500ms();
    }
}

```

```纯文本
#include <REGX52.H>
#include <INTRINS.H>
void Delay1ms(unsigned int xms);        //@12.000MHz

void main()
{

    P2 = 0xFE;
    while(1)
    {
        P2=_cror_(P2,1);
        Delay1ms(100);
    }
}

void Delay1ms(unsigned int xms)        //@12.000MHz
{
    unsigned char i, j;
    while(xms)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
        xms--;
    }
}

```
