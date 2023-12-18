#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    int * p =  malloc(10*sizeof(int)) ;
    memset(p , 1 , 10*sizeof(int) );

    for (size_t i = 0; i < 10; i++)
    {
        printf("%d\n" , *(p+i)); // 以整型输出 结果为 16843009  
            // 原因是 内存中每一个字节都被写为 1 
    } 
    

    return 0;
}
