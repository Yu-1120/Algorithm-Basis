#include   <stdio.h>

typedef  int  TieZhu ;



int main(int argc, char const *argv[])
{
    
    int a ;
    TieZhu b ;

    __int64_t i ;
    __int32_t i32 = 0 ;

    b = 100 ;
    a = 200;
    printf("a+b=%d\n" , a + b );

    printf("%ld , sizeof(i):%ld\n" ,  i , sizeof(i));
    printf("%ld , sizeof(i32):%ld\n" ,  i32 , sizeof(i32));


    return 0;
}
