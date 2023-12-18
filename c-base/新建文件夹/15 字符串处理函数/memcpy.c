#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    char * s1 = "Hello GZ2123" ;
    char * s2 = calloc(128 , 1 ) ; 
    memset(s2 , 'A', 128 );


    // strlen 计算的长度并不包括结束符， 因此应该+1让函数把结束符一起拷贝     
    // memcpy(s2 , s1 , strlen(s1)+1);
    char * str = memccpy(s2 , s1, 'o', strlen(s1)+1); 

    printf("s2:%s\n" , s2) ;
    printf("str:%s\n" , str) ;



    return 0;
}

asl;kdj'\0'oaasl'\0'dj'\0'alsd
