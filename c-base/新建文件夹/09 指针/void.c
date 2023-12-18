#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    void * p =  malloc(4) ; // 使用malloc 来申请 4个字节的内存， 并让p来指向该内存的入口地址




    *(int *)p = 250 ; // 先使用(int*) 来强调p是一个整型地址 ，然后再解引用
    printf("*p:%d\n", *(int*)p); // 输出时也应该使用对应的类型来进行输出

    *(float*)p = 3.14 ;
    printf("*p:%f\n", *(float*)p);


    return 0;
}
