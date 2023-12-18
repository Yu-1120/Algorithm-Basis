#include <stdio.h>


void func( int num )
{
    if (num < 0)
    {
        return ;
    }
    
    func(num-1);

    printf("num:%d\n" , num );

    return ;
}


void string_printf(char * p )
{
    // 先判断p有没有指向结束符
    if (*p == '\0')
    {
        return ;
    }

    //    再次调用自己， 并传递的 当前字符的下一个 
    string_printf( p + 1 ) ;

    printf("%c" , *p );

    return ;
}

int mi( int a , int n )
{
    if (n == 0)
    {
        return 1 ;
    }
    else if (n == 1)
    {
        return a ;
    }
    else
    {
        return mi(  a , n - 1 ) * a ; 
    }
    
    

}


int test( int n )
{
    // 如果 n 等于 1则 阶乘 为 1 
    if (n == 1 )
    {
        return 1 ;
    }
    else
    {
        return  test( n-1 )*n;
    }
}




int main(int argc, char const *argv[])
{
    func(5);    


    string_printf("Hello GZ2123");
    printf("\n");


    printf("5的阶乘：%d\n" , test( 5 ) )  ;

    printf("2的10次幂：%d\n" , mi( 2 , 10 ));

    return 0;
}
