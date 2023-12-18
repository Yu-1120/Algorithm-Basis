#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char s1[128] = "Hello Even" ;  // 可读写的内存区 
    char * s2 = "Hello even" ; // 数据段 只读的

    float f = 3.1415926;
    long  l = 17620828909;

    printf("%s-%s-%f-%ld\n" , s1 , s2 , f , l );

    char * p = calloc(1 , 128 );
    sprintf(p , "%s-%s-%f-%ld\n" , s1 , s2 , f , l );

    printf("p:%s\n" , p );


    // file_1.mp3
    // file_2.mp3
    // file_3.mp3
    // file_4.mp3
    for (size_t i = 0; i < 100; i++)
    {
        sprintf(p , "file_%ld.mp3" , i );
        printf("%s\n" , p );
    }





    return 0;
}


