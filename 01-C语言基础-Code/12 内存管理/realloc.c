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


    printf("重新分配前p:%p\n" , p );

    // 如果重新申请内存需要另找宝地 ， 那么 原本的地址会被释放掉
    int * p1 = realloc( p , 128);
    p = NULL ;// 让p不要称为野指针， 需要让它指向NULL 
     
    printf("重新分配后p1:%p\n" , p1 );
    
    //realloc 会帮我们把原有的数进行搬运 
    for (int i = 0; i < 10; i++)
    {
       printf("*(p1+%d):%d\n" , i , *(p1+i));
    }


    //不再使用该堆空间时需要释放
    free(p1);

    return 0;
}