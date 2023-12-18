#include <stdio.h>

int main(int argc, char const *argv[])
{
    int  arr [5] = {1,2,3,4,5} ;
    int * p1 = &arr ;
    int * p2 = arr ;


    printf("*p1:%d\n" , *(p1+1)) ;
    printf("*p2:%d\n" , *(p2+1)) ;




    

    return 0;
}
