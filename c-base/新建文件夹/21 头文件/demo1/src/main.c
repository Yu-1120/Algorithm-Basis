#include    "main.h"

int as = 1 ;

int main(int argc, char const *argv[])
{

    printf("%s--%d\n" , __FUNCTION__ , as);
    int x = 129 ;
    int y = 245;
    int z = 350;

    int num = max( x , y , z ) ; // x , y , z 都是实参

    printf("max:%d\n" , num );

    if( swap( &x , &y) )
    {
        printf("x:%d y:%d\n" , x , y ); 
    }
    else
    {
        printf("交换失败 ！！\n");
    }

    return 0;
}
