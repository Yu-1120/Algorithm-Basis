#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


char * StrCat(char const * s1  ,char const * s2)
{
    if (s1 == NULL  || s2 == NULL)
    {
        return NULL ;
    }



        //                 字符串1 长度  +   字符串2 长度  + 1个结束符
    char * str1 =  calloc(1, strlen(s1) + strlen(s2) + 2);
    
    
    sprintf(str1, "%s %s" , s1 ,s2);



    return str1 ;
}




//       参数的个数           参数具体值
int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("小伙子不讲武德 ！！\n");
        return -1 ;
    }
    
    // 可以用于调试段错误
    printf("%s__%d\n" , __FUNCTION__ , __LINE__);



    printf("argc:%d\n" , argc);
    for (size_t i = 0; i < argc ; i++)
    {
        printf("argv[%ld]:%s\n" , i , argv[i]);

    }



    

    printf("%s\n" , StrCat(argv[1] , argv[2]) );

    

    return 0;
}
