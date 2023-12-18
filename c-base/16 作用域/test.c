#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 1 ;

    {
        printf("1a:%d\n" , a);// 输出 为 1  ， 使用的是外面大的作用域

        int a = 250 ; // 从这里开始 a 的值被临时覆盖为 250 外面的1临时失效
        printf("2a:%d\n" , a);// 输出 为 250  ， 使用的是内部的小的作用域
    }

    printf("3a:%d\n" , a); // 离开小的作用域后 ，a 恢复为  1 
    

    return 0;
}
