#include <stdio.h>

// 结构体声明   -->   不占用内存空间
struct TieZhu
{
    int num ;
    char * Book ;
    float Price ;
    char Name [32] ;
};



int main(int argc, char const *argv[])
{

    struct TieZhu * P1 = calloc(1, sizeof(struct TieZhu));

    P1->num = 1024 ;
    P1->Book = "Hello" ;
    strncpy(P1->Name , "Even" , 32 );
    P1->Price = 3.998 ;

    P1->Book = malloc(1024);


    return 0;
}
