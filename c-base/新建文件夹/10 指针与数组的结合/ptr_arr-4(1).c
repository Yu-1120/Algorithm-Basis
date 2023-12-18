#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 100 ;
    int b = 250 ;
    int c = 550 ;
    int d = 256 ;
    int e = 998 ;

    int  * p [5] = {&a, &b , &c , &d , &e} ; // 定义一个名字为 p的数组， 并且确定该数组中用来存放int * 整型地址


    for (size_t i = 0; i < 5; i++)
    {
        printf("*p[%d]:%d \n" , i , *(p[i])  ); // p[0]  --》 &a
    }

    

    return 0;
}

