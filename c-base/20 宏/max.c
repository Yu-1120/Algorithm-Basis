#include <stdio.h>

#define   MAX(a,b)  (a)>(b)? \
                        (a):(b) 

int main(int argc, char const *argv[])
{
   int x = 100 ;
   int y = 200 ;
   printf("%d\n" , MAX(198,288) );

   printf("%d\n" , MAX( x, y==200 ? 988:1024 ) );
// printf("%d\n" , x>y==200 ? 988:1024? x:y==200 ? 988:1024 );

    return 0;
}
