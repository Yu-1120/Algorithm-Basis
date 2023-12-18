#include <stdio.h>

int main(int argc, char const *argv[])
{
    int  arr [5] = {1,2,3,4,5} ;

    int (*p) [5] = arr ;

    printf("arr:%p\n" , &arr );


    printf("%p---%d\n" ,p , (*p)[2] ); // 3 

    printf("%p---%d\n" , p+1 , (*(p+1))[2] );









    

    return 0;
}
