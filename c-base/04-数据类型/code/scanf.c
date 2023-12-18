#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 0;
    char c = '0';
    // & 取地址符号 ， 获得 内存 num 的地址
    int ret_val =  scanf("%d", &num );
    while(getchar() != '\n');  // 清空 由 scanf 所留在缓冲区的内容 
    //   如果不清空有可能会导致下一次使用标准输入缓冲区异常（有上一次的数据没有被读取）

    printf("返回值：%d , 获取的数据为：%d\n" , ret_val , num );
    
    ret_val = scanf("%c", &c );
    while(getchar() != '\n'); // 清空 由 scanf 所留在缓冲区的内容
    printf("返回值：%d , 获取的数据为：%c\n" , ret_val , c );

    printf("EOF:%d\n" , EOF ); //EOF 实际上是一个值为-1 的宏

    return 0;
}
