#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int * p = (int *)malloc( 100 * sizeof(int) );  // 申请一个可以存放10个整型的 堆空间 

    // for (int i = 0; i < 10 ; i++)
    // {
    //     *(p+i) = i;
    // }

    for (int i = 0; i < 100 ; i++)
    {
        printf("*(p+%d):%d\n" ,i,  *(p+i));
    }

    //   &p 打印的是栈空间地址     p中所存放的地址为堆空间地址
    printf("&p:%p--->%p\n" , &p , p );
    


    //不再使用该堆空间时需要释放
    free(p);


    return 0;
}