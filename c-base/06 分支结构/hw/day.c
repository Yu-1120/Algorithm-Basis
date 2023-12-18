#include <stdio.h>


int main(void)
{
    int num = 0 ;
    printf("请输入天数：\n");
    scanf("%d" , &num);
    while(getchar() != '\n'); // 清空标准输入缓冲区


    printf("%d星期零%d天\n" , num/7 , num%7);

	return 0;
}