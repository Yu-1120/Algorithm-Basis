#include <stdio.h>


union demo
{
    int num ;
    char ch ;
};


int main(int argc, char const *argv[])
{
    union demo data ;

    data.num = 0x12345678 ;


    if (data.ch == 0x12)
    {
        printf("当前主机位大端序！！\n");
    }
    else if (data.ch == 0x78)
    {
        printf("当前主机为小端序！！\n");
    }
    
    return 0;
}
