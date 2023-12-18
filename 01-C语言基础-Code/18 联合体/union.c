#include <stdio.h>

// 声明联合体
typedef union node
{
    int i ;
    char c ;
    short s ;
    double d ;
}Node ;


int main(int argc, char const *argv[])
{
    // 联合体变量定义
    Node data = { 100  ,'D' , 13, 3.1456789 };

    printf("size:%ld\n" , sizeof(data));
    printf("i:%p\n" , &data.i );
    printf("c:%p\n" , &data.c );
    printf("s:%p\n" , &data.s );
    printf("d:%p\n" , &data.d );

    data.i = 200 ;
    data.c = 'A' ;

    printf("i:%d\n" , data.i );
    printf("c:%c\n" , data.c );
    printf("s:%d\n" , data.s );
    printf("d:%f\n" , data.d );






    

    return 0;
}
