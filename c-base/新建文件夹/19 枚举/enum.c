#include <stdio.h>

// 声明枚举常量列表
enum  MIC {  open , run = 5 , stop  , close } ;

int main(int argc, char const *argv[])
{
    enum  MIC stat = open ;

    switch(stat)
    {
        case open:
            printf("麦克风状态为打开：%d\n" , open);
            break;
        case run:
            printf("麦克风状态为运行中：%d\n" , run);
            break;
        case stop:
            printf("麦克风状态为暂停：%d\n" , stop);
            break;
        case close:
            printf("麦克风状态为关闭：%d\n" , close);
            break;
    }

    

    return 0;
}
