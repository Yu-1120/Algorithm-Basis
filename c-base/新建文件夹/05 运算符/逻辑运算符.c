#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 100 ;
    int b = 200;

    if (a < 50 && (b = b + 300)); // 如果左边为假， 则右边不被执行
    printf("a=%d , b=%d\n" , a , b );   // a = 100 ,  b  = 200 

    if (a < 50 || (b = b + 300)); //如果左边为真 ，则右边不被执行
    printf("a=%d , b=%d\n" , a , b );   // a = 100 ,  b  = 200 

    

    return 0;
}
