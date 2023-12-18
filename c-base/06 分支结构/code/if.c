#include <stdio.h>

int main(int argc, char const *argv[])
{
    int  a = 99 ;

    // if ( a > 100 )//判断条件
    // {
    //     /* 如果满足则执行该代码块 */
    //     printf("耗子尾汁！！\n");
    // }
    

    // if (a < 99 )
    // {
    //     printf("大意了！！\n");
    // }
    // else if (a > 99 )
    // {
    //     printf("没有闪！！！\n");
    // }else
    // {
    //     printf("不讲武德！！！\n");
    // }
 
    if (a > 1)
        printf("Hello\n"); 
    else
        printf("Jacy\n");
        printf("Even\n");  //  注意此行代码已经不在else的管辖范围内
    

    return 0;
}
