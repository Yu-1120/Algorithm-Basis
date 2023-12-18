#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i ; 
    double d ;
    float f ;
    char c ;

    printf("i的地址为：%p\n" , &i);
    printf("d的地址为：%p\n" , &d);
    printf("f的地址为：%p\n" , &f);
    printf("c的地址为：%p\n" , &c);

    int  a = 100 ;
    int * p = &a ;

    *p = 250 ;  //   *p <==>  a 

    printf("*p:%d\n" ,  *p) ;
    printf("a:%d\n" ,  a) ;



    

    return 0;
}
