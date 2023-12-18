#include <stdio.h>


int main(int argc, char const *argv[])
{
    int num = 0 ;
    printf("请你来几拳！！！\n");
    scanf("%d" , &num);
    while(getchar() != '\n'); // 清空标准输入缓冲区
    int i = 0 ;
    for (;  ;)
    {
        printf("i:%ld\n" , i );
    }
    



    return 0;
}
