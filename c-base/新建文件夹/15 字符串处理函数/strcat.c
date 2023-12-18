#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char s1[128] = "Hello Even" ;  // 可读写的内存区 
    char * s2 = "Hello even" ; // 数据段 只读的

    //strcat(s1,s2);  // 总大小 - 已经使用  = 可以使用的
    strncat(s1,s2 , sizeof(s1) - strlen(s1)  );
    

    printf("s1:%s\n" , s1);

    return 0;
}


