#include <stdio.h>
#include <stdbool.h>



// 使用函数来实现求 3个整型中最大的并返回。
int max( int a , int b , int c )
{
    int max = a > b ? a : b ;

    max = max > c ? max : c ;

    return max ;
    // a>b?(a>c?c:a):(b>c?b:c)
}