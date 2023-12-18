#include <stdio.h>
#include <stdbool.h>


// 使用函数来实现求 3个整型中最大的并返回。
static  int max( int a , int b , int c )
{
    int max = a > b ? a : b ;

    max = max > c ? max : c ;

    return max ;
    // a>b?(a>c?c:a):(b>c?b:c)
}

//使用函数来实现交换两个变量的值（指针）
static bool swap( int * a , int * b )
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



int main(int argc, char const *argv[])
{
    int x = 129 ;
    int y = 245;
    int z = 350;

    int num = max( x , y , z ) ; // x , y , z 都是实参

    printf("max:%d\n" , num );

    if( swap( &x , &y) )
    {
        printf("x:%d y:%d\n" , x , y ); 
    }
    else
    {
        printf("交换失败 ！！\n");
    }

    return 0;
}
