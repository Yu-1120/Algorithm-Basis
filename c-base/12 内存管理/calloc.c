#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //           申请10块连续的内存  ，每一块为 整型大小
    int * p = calloc( 10 , sizeof(int));

    for (size_t i = 0; i < 10; i++)
    {
        *(p+i) = i+ 998 ;
    }
    
    for (int i = 0; i < 10; i++)
    {
       printf("*(p+%d):%d\n" , i , *(p+i));
    }

    //不再使用该堆空间时需要释放
    free(p);

    return 0;
}