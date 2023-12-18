#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char * p = malloc(32);
   
    //   [^\n]  表示只有 回车符才是结束标记
    scanf("%[^\n]s" , p ) ;
    while(getchar() != '\n');

   
    printf("%s\n" , p );

    *(p+3) = 'W';
    printf("%s\n" , p );


    //不再使用该堆空间时需要释放
    free(p);
    return 0;
}