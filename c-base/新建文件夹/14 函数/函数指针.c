#include <stdio.h>
#include <stdbool.h>

int Printf( int a , float f )
{


    printf("a:%d , f:%f\n" , a , f );

    return 0 ;
}

int main(int argc, char const *argv[])
{
    int  (*p) (int , float ) ;
    p = Printf ;  //  函数名其实也是这个函数的入口地址

    Printf(10 , 3.14);

    p(56 ,9.8888);

    printf("%p\n" , &p);

    printf("%p,%p\n" , p , &Printf );

    return 0;
}


// 易语言