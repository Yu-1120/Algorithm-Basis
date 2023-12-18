#include <stdio.h>

struct node
{
    int i __attribute__((aligned(4))) ;
    char c  __attribute__((aligned(1)));
    short s __attribute__((aligned(2)));
    double d __attribute__((aligned(4)));
    long double ld __attribute__((aligned(4))) ;
    char kk __attribute__((aligned(1))) ;
    float f  __attribute__((aligned(4)));
};


int main(int argc, char const *argv[])
{
    struct node data ;

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
