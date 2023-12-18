#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 结构体声明   -->   不占用内存空间
typedef  struct TieZhu
{
    char * Book ;
    float Price ;
    char Name [32] ;
}Tz , *P_Tz ;



int main(int argc, char const *argv[])
{

    Tz b = {
        .Book = "Hello" ,
        .Name = "Even",
        .Price = 3.14 
    }; 

    P_Tz p = &b ;

    printf("Name : %s \n" , b.Name );
    printf("Name : %s \n" , p->Name );



   
    return 0;
}
