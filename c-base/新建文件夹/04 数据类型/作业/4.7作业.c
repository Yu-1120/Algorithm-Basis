//1.设计一个程序实现用户输入字符，则程序输出其对应的ASCII码值。

#include <stdio.h>

/*
int main(int argc,char const *argv[])
{  
    char a;
    scanf("%c", &a);
    printf("%d", a);

    return 0;       
}
*/



//设计一个程序实现用户输入一个ASCII值， 则程序输出其对应的字母（字符）。
/*
int main(int argc,char const *argv[])
{  
     int a;
    scanf("%d", &a);
    printf("%c", a);

    return 0;       
}*/

//编写一个程序输出26个小写字母或者大写字母【拓展】
/*
int main(int argc, char const *argv[])
{
    char c = 'a' ;

    for (size_t i = 0; i < 26 ; i++)
    {
        printf("%c\t" , c+i);
    }
    printf("\n");

    return 0;
}
*/



//编写一个程序，用户输入华氏温度F，程序输出摄氏温度C，结果保留2位小数。

int main(int argc,char const *argv[])
{   
    float c,f;
    scanf("%f", &f);
    c=5*(f-32)/9;
    printf("%9.2f", c);

    return 0;       
}