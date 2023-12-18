#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int i ;
    char c  __attribute__((aligned(16))) ;
    short s ;
    double d ;
    float f ;

    printf("i:%p\n s:%p\n c:%p\n d:%p\n f:%p\n" , &i ,&s, &c , &d , &f);


    return 0;
}
