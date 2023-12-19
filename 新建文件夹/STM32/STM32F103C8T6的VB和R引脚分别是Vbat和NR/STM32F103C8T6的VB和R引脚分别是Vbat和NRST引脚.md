# STM32F103C8T6的VB和R引脚分别是Vbat和NRST引脚

## 目录

-   [STM32F103C8T6 PA10是rxd吗](#STM32F103C8T6-PA10是rxd吗 "STM32F103C8T6 PA10是rxd吗")

STM32F103C8T6的VB和R引脚分别是**Vbat**和NRST引脚。 Vbat引脚是用来连接备用电源电池的引脚，当主电源掉电时，备用电源可以为芯片提供电源供电，保持芯片的一些关键参数和信息不丢失。\*\* NRST引脚是芯片的复位引脚\*\*，当NRST引脚被拉低时，芯片会被强制复位，可以用来对芯片进行复位操作。

# STM32F103C8T6 PA10是rxd吗

系统板的TX、RX分别对应PA9、**PA10**引脚。 此时我们需要将两者的TX、RX的引脚交错相接，即USB TO TTL的RXD、TXD分别与系统板的TX、RX相接（即接入系统板的PA9、PA10引脚）。 在使用STM32F10XX时，我们一般使用系统存储器启动模式。

# STM32F103C8T6的引脚分布图

![](image/STM32F103C8T6引脚定义_5nJx0WElwo_dnIpracVU8.png)
