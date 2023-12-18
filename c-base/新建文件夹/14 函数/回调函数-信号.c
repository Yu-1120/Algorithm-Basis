#include <stdio.h>
#include <signal.h>



void func(int num )
{
    printf("当前收到  3 号信号 ， 军师让我蹲下 !!\n");
}


int main(int argc, char const *argv[])
{
    void (*p)(int); // 定义一个函数指针
    p = func ; // 让指针p 指向函数  func 

    // 设置进程捕获信号 ，如果信号值 为 3的时候 ， 会自行调用 p 所指向的函数 （代码/指令）
    signal( 3 , p );

    while(1);     
    

    return 0;
}
