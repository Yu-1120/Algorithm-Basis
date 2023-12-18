#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //      向系统申请 128个字节的堆空间内存， 并用p来指向该内存区的入口地址
    char  * p = calloc( 128 , sizeof(char));


    printf("请输入需要分割的字符串：");

    // getchar();
    for (size_t i = 0; i < 128 ; i++)
    {
        *(p+i) = getchar();
        if ( *(p+i) == '#' || *(p+i) == '\n')
        {
            *(p+i) = '\0' ;  // 手动填补上一个结束符 （把# 或回车符换成  \0 ）
            break ;
        }
    }

    int len = strlen(p);  // 计算刚才输入的数据的长度
    printf("%s:%d\n" , p , len) ;


    // 定义分割符的 《集合》
    char * delim = "$K/";// 定义了三个分隔符

    //      第一次调用该函数  p 必须给 
    char * str = strtok( p ,  delim);
    printf("str:%s\n" , str) ;

    char * str = strtok( p1 ,  delim);


    while(1)
    {
        // 以后的每一次调用都不需要给参数P ， 应写NULL 
        str = strtok( NULL ,  delim);
        if (str == NULL)
        {
            printf("分割已结束\n");
            break ;
        }
        
        printf("str:%s\n" , str) ;
    }


    return 0;
}



// 广州天气 ：当前温度24℃，感冒低发期，天气舒适，请注意多吃蔬菜水果，多喝水哦。
// [04月15日] ：大雨，低温 20℃，高温 27℃，风力3级
// [04月16日] ：中雨，低温 20℃，高温 23℃，风力2级
// [04月17日] ：雷阵雨，低温 19℃，高温 25℃，风力3级
// [04月18日] ：多云，低温 18℃，高温 24℃，风力2级
// [04月19日] ：多云，低温 18℃，高温 24℃，风力1级
