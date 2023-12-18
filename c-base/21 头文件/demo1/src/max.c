#include    "max.h"

// 声明外部变量  as   并不是定义， 因此不会另外申请内存空间
extern  int as ;

// 使用函数来实现求 3个整型中最大的并返回。
int max( int a , int b , int c )
{
    printf("%s--%d\n" , __FUNCTION__ , as);

    int max = a > b ? a : b ;

    max = max > c ? max : c ;

    return max ;
    // a>b?(a>c?c:a):(b>c?b:c)
}