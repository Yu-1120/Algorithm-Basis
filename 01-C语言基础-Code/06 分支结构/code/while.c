#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 0 ;
    printf("请你来几拳！！！\n");
    scanf("%d" , &num);
    while(getchar() != '\n'); // 清空标准输入缓冲区


    // while(num)  // 非零则真 （布尔值）
    // {
    //     printf("num:%d\n" , num-- );
    // }


    do
    {
        printf("num:%d\n" , num-- );
    } while (num);
    


    return 0;
}
