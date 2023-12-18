#include <stdio.h>

int main(int argc, char const *argv[])
{
    char arr [] = "Hello" ;
    char msg [] = "Even" ; 
    char * const p = arr ;

    // p = msg ; // p 被const 所修改， 
            //说明P是一个常量 ，他的内容（所指向的地址）无法修改
    *(p + 1 ) = 'E' ; // p所指向的内容是可以通过p 来修改 （只要保持P所指向的地址不变即可）
    printf("%s\n" , p );


    const char * p1 = arr ; 
    p1 = msg ; 
    // *(p1+1) = 'V' ; // 常目标指针， 不允许通过该指针来它所指向的内容

    *(msg+1) = 'V' ;

    printf("%s\n" , p1 );




    return 0;
}
