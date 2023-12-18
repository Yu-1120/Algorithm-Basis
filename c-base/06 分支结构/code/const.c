#include <stdio.h>

int main(int argc, char const *argv[])
{
    int const a = 100 ; // 定义了一个不可被修改的变量a
    const int b = 200;

    a = 300 ;
    b = 250 ;

    return 0;
}
