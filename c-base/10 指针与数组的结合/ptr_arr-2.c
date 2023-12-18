#include <stdio.h>

int main(int argc, char const *argv[])
{
    int  arr [5] = {1,2,3,4,5} ;

    int * p2 = &arr[2] ;

    printf("*p2-1:%d\n" , *(p2-1)) ;
    printf("*p2:%d\n" , *p2) ;
    printf("*p2+1:%d\n" , *(p2+1)) ;





    

    return 0;
}
