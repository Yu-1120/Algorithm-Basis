#include    "swap.h"



//使用函数来实现交换两个变量的值（指针）
bool swap( int * a , int * b )
{

    if ( a == NULL || b == NULL )
    {
        printf("参数有误， 大意了！！\n");
        return false ;
    }
    

    printf("a:%d b:%d\n" , *a , *b ); 

    *a^=*b;
    *b^=*a;
    *a^=*b;

    printf("a:%d b:%d\n" , *a , *b ); 

    return true ;
}