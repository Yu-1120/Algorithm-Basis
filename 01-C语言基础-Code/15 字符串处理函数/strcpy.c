#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //      向系统申请 128个字节的堆空间内存， 并用p来指向该内存区的入口地址
    char  * p = calloc( 128 , sizeof(char));


    printf("请输入需要分割的字符串：");

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


    char buf [ len+1 ] ; // 变长数组  strlen 不包括结束符 因此需要  + 1来存放结束符

    // strcpy( buf, p );

    strncpy(buf , p , len+1 );

    printf("buf:%s\n" , buf);
 


    return 0;
}


