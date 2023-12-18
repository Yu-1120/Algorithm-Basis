#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c = '1' ;

    printf("字符：%c\n",c);
    printf("整型ASCII值：%d\n",c);

    char k = 'H' ;
    printf("%c\n" , k + 1 );
    printf("%c\n" , k - 1 );

    char s1[] = "Hello";
    char *s2  = "Even";

    printf("%s %s\n" , s1 , s2  );


    return 0;
}
