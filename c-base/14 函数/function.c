#include <stdio.h>

// 函数声明
static inline int add ( int , int ); // 函数声明中可以把形参的名字省略


int main(int argc, char const *argv[])
{
    int x = 100 ;
    int y = 250 ;

    int tmp = 0 ;

    // 调用add函数， 把 x 和 y 的值 传递过去，
    //  x , y 是实参， 作为形参 a , b 初始值  
    //   a = x  , b = y ;
    // 使用 tmp 来接受 add函数的返回值 
    tmp = add(x,y);

    printf("x + y = %d \n" , tmp );

    return 0;
}


// 设计一个函数 ，接收 两个整型参数， 并返回 它们的和
static inline int    add ( int a , int b )
{
    int tmp = a + b ;

    return tmp ;
}