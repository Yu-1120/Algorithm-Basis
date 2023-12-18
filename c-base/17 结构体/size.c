#include <stdio.h>

typedef struct node
{
    int i ;
    char c  ;
    short s ;
    double d ;
    long double ld ;
    char kk ;
    float f ;
}Node;


int main(int argc, char const *argv[])
{
    Node data ;

    printf("addr:%p\n size:%ld\n" , &data , sizeof(data));

    printf("&i:%p\n" , &data.i) ;
    printf("&c:%p\n" , &data.c) ;
    printf("&s:%p\n" , &data.s) ;
    printf("&d:%p\n" , &data.d) ;
    printf("&f:%p\n" , &data.f) ;
    printf("&kk:%p\n" , &data.kk) ;

    printf("&ld:%p\n" , &data.ld) ;



    



    return 0;
}
