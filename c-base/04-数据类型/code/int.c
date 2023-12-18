#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int  a = -123 ;
    printf("sizeof(short):%ld\n" ,sizeof(short) );  
    printf("sizeof(int):%ld\n" ,sizeof(int) );    
    printf("sizeof(long):%ld\n" ,sizeof(long) );  
    printf("sizeof(long long):%ld\n" ,sizeof(long long ) );  

    printf("sizeof(a):%ld\n" ,sizeof(a) );    

    
    int num = 2147483647 ;
    printf("num+1:%d\n" , num+1 );

    int num1 = -2147483648 ;
    printf("num-1:%d\n" , num1-1 );

    int c = 100;
    printf("十六进制：%#x\n"  , c );
    printf("十进制：%d\n"  , c );
    printf("八进制：%#o\n"  , c );




    return 0;
}
