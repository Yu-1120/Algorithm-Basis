#include <stdio.h>


int main(int argc, char const *argv[])
{

    int num = 0 ;
Even:
    printf("请你来几拳！！！\n");
    scanf("%d" , &num);
    while(getchar() != '\n'); // 清空标准输入缓冲区

    

    for (int i = 0 ; i < num  ; ++i )
    {
        while(1)  // 在 循环体内部可以嵌套其它的循环
        {
            printf("你打我呀！！\n");
            break; // 跳出while这一层循环， 并不影响外面的for 
        }
       
        if (i == 5)
        {
            continue ; // 跳过当前这一次循环， 导致后面的代码在当次循环中不执行
        }
        printf("i:%d\n" , i );

        goto Even;
        
    }



    printf("这里是标签的位置!!!\n");



    return 0;
}
