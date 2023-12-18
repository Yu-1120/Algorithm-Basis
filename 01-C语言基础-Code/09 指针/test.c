#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 250;
    int b = 350;
    int t = 0 ;

    int *p1 = &a ;
    int *p2 = &b ;
    int *p3 = &t ;

    *p3 = *p1 ; // t = a 
    *p1 = *p2 ; // a = b 
    *p2 = *p3 ; // b = t

    printf("*p1:%d *p2:%d\n" , *p1 , *p2 ); 

    *p1 = *p1 ^ *p2 ;
    *p2 = *p1 ^ *p2 ;
    *p1 = *p1 ^ *p2 ;
    printf("*p1:%d *p2:%d\n" , *p1 , *p2 ); 



    printf("================================\n");

    float  f = 3.14 ; 
    int * f_p = (int *)&f ;

    printf("%d\n" , *f_p );

    return 0;
}
