#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr [5] = {1}; // 定义并没有初始化数组

    for (size_t i = 0; i < 5 ; i++)
    {
        printf("ar1[%ld]:%d\n" , i , arr[i]);   
    }

    char  buf [5] = {1,2,3,4,5};
    for (size_t i = 0; i < 5 ; i++)
    {
        printf("buf[%ld]:%d\n" , i , buf[i]);   
        printf("buf[%ld]:%c\n" , i , buf[i]);   
    }


    arr[3] = 339 ;
    printf("arr[3]:%d\n" , arr[3]);
    printf("3[arr]:%d\n" , 3[arr]);
    

    char  * msg2 = "Hello Even" ;// "Hello Even" 字符串常量首元素的首地址
    char  * msg1 = "Hello Even"+1 ;

    printf("msg2:%s\n" , msg2 );
    printf("msg1:%s\n" , msg1 );



    return 0;
}
