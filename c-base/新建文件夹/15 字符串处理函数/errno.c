#include <stdio.h>
#include <string.h>
#include <errno.h>


int main(int argc, char const *argv[])
{
    
    for (size_t i = 0; i < 134; i++)
    {
        printf("errno:%d:msg:%s\n" , i , strerror(i));
    }
        
    errno = 3 ;
    perror("左勾拳失败");


    return 0;
}
