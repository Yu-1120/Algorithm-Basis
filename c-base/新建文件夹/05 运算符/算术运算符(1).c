#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 5 ;
    int c = 3 ;

    printf("5/3 = %d , 5%%3 = %d \n " ,a/c  , a%c);  

    printf("a++:%d\n", a++); // 5 
    printf("++a:%d\n", ++a);  // 7 

    
    return 0;
}
