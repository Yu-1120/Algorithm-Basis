#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


char * StrTok(char * msg , char * delim )
{
 

    // 使用 strstr 来寻找出现的字符串
    char * str ; 
    while(str = strstr(msg , delim)) // 在原始数据中寻找 换行符  {br} . 如果找到那么 str则指向ta所在的地址
    {
        // printf("%s\n" , str);

        *str = '\n' ;  // 把 {br}  中 { 换成 '\n'

        // printf("msg:%s\n" , msg);

        // 把原始数据中后面的内容往前拷贝覆盖 br}  
        memcpy (str + 1 , str + 4, strlen(str)-3);

        // printf("msg--:%s\n" , msg);
    }

    str = strstr(msg , "\":\"") ; // 寻找协议字符串的开头部分 
    memcpy (msg  , str + 3 , strlen(str)-2); // 把源字符串往前挪 覆盖不需要的数据 
    // printf("msg--:%s\n" , msg);

    str = strstr(msg , "\"}") ; // 寻找协议字符串的末尾
    *str = '\0' ;  // 用\0来直接切断
    // printf("msg--:%s\n" , msg);

    return  msg ;
}

int main(int argc, char const *argv[])
{
    // 先申请堆空间
    char * msg = calloc(1024 ,1 );
    
    // 把数据拷贝到该堆空间中
    strcpy(msg , "{\"result\":0,\"content\":\"广州天气 ：当前温度21℃，感冒低发期，天气舒适，请注意多吃蔬菜水果，多喝水哦。{br}[04月16日] ：大雨，低温 21℃，高温 24℃，风力2级{br}[04月17日] ：小雨，低温 19℃，高温 24℃，风力2级{br}[04月18日] ：阴，低温 19℃，高温 23℃，风力2级{br}[04月19日] ：多云，低温 18℃，高温 24℃，风力1级{br}[04月20日] ：多云，低温 18℃，高温 26℃，风力2级\"}");

    printf("%s\n" , msg );


    StrTok(msg , "{br}");

    printf("Mag:%s\n" , msg );


    char buf[]  = "你";

    //                  4  包含结束符    不包括结束符 3 
    printf("%ld, %ld\n" , sizeof(buf) , strlen(buf) );

    

    return 0;
}
