#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // 向系统申请128字节的堆空间内存， 并让P 指向给内存的入口地址
    char * p = malloc(128);
    bzero(p , 128) ; //清空堆内存


    // getchar();
    for (size_t i = 0; i < 128 ; i++)
    {
        *(p+i) = getchar();
        if ( *(p+i) == '#' || *(p+i) == '\n')
        {
            *(p+i) = '\0' ;  // 手动填补上一个结束符 （把# 或回车符换成  \0 ）
            break ;
        }
    }

    char * str =  strchr (p , 'K'); // -----> 

    printf("str:%s\n" , str );

    str =  strrchr (p , 'K');  // <-------
    printf("str:%s\n" , str );

    printf("p:%s\n" , p );

    return 0 ;
}


