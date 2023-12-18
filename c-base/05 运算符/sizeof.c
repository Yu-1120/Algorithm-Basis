#include <stdio.h>

struct node
{
    int a ; //4
    char b ; // 1 
    double c ; // 8 
};


int main(int argc, char const *argv[])
{

    printf("sizeof(double):%ld\n" ,sizeof(double) );

    printf("sizeof(struct node):%ld\n" ,sizeof(struct node) );
    
    int a = 10 ;
    int c = 250 ;
    //       11     261= 11+250  261
    int b = (a++ , a = a + c , a , 300 );

    printf("b:%d\n" , b );
    printf("a:%d\n" , a );



    return 0;
}
