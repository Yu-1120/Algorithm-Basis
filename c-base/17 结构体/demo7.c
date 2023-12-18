#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 结构体声明   -->   不占用内存空间
typedef  struct TieZhu
{
    char * Pc ;
    float f ;
    int i ;
    char c ;
    double d ;
    long double k ;
}Tz , *P_Tz ;



int main(int argc, char const *argv[])
{
    Tz data ;

    printf("Pc:%p\n" , &data.Pc);
    printf("f:%p\n" , &data.f);
    printf("i:%p\n" , &data.i);
    printf("c:%p\n" , &data.c);
    printf("d:%p\n" , &data.d);
    printf("k:%p\n" , &data.k);


    printf("%ld\n" , sizeof(long double));



  
   
    return 0;
}
