#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char * s1 = "Hello Even" ;
    char * s2 = "Hello even" ;

    if( strcmp(s1 , s2) )
    {
        printf("这两个东西不一样！！\n");
    }
    else
    {
        printf("这两个东西一模一样！！\n");
    }

     if( strncmp(s1 , s2 , 5 ) )
    {
        printf("这两个东西不一样！！\n");
    }
    else
    {
        printf("这两个东西一模一样！！\n");
    }



    return 0;
}


