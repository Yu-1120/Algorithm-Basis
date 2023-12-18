#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char * p = malloc(32);
   
    //p = "Hello Even" ; // 让p指向常量区  "Hello Even" ， 把刚才的堆空间地址搞丢了

    *p = "Hello Even";
    long unsigned addr  = *((long unsigned* )p );

    printf("&Hello even :%p \n" , &"Hello Even");
    printf("p :%p \n" , addr );


    printf("%s\n" , p );

    //不再使用该堆空间时需要释放
    free(p);


    return 0;
}