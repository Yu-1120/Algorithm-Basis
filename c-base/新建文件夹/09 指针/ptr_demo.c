#include <stdio.h>

void  main(void)
{
    int  a = 100 ;
    int * p1 = &a ; // 那么p1就是一个一级指针
    int ** p2 = &p1 ; // 那么p2就是一个二级指针
    int *** p3 = &p2 ; // 那么p3就是一个三级指针

    printf("a:%d\n" , a );
    printf("*p1:%d\n" , *p1 );
    printf("**p2:%d\n" , **p2 );
    printf("***p3:%d\n" , ***p3 );

    printf("&a:%p\n" , &a );
    printf("&p1:%p --> p1:%p\n" , &p1 , p1 );
    printf("&p2:%p --> p2:%p\n" , &p2 , p2 );
    printf("&p3:%p --> p3:%p\n" , &p3 , p3 );

    







    return 0;
}
