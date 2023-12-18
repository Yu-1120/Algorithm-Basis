#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //      向系统申请 128个字节的堆空间内存， 并用p来指向该内存区的入口地址
    char  * p = calloc( 128 , sizeof(char));

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

    int len = strlen(p);  // 计算刚才输入的数据的长度
    printf("%s:%d\n" , p , len) ;

    if(strstr( p , "Even")) // 非零则真，如果找到则条件为真，否则条件为假
    {
        printf("找到你需要的字符串\n" );
    }    
    else
    {
        printf("找不到你需要的字符串\n" );

    }
    

    return 0;
}
