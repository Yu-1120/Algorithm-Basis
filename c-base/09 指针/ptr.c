#include <stdio.h>

int main(int argc, char const *argv[])
{
    int l = 250 ;

    long *p = &l ;

    printf("*p:%ld\n" , *p );
    printf("l:%d\n" , l );


    int i ;
    int * p1 = &i;

    printf("p:%p\n" , p );
    printf("p+1:%p\n" , p+1 );



    printf("p1:%p\n" , p1 );
    printf("p1+1:%p\n" , p1+1 );




    // printf("%ld\n" , *p );


    // int * p1 = NULL ;
    // *p1 = 250 ;
    // printf("%p -- %d \n" , NULL , NULL  );

    

    return 0;
}
