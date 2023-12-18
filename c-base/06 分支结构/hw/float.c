#include <stdio.h>

int main(void)
{
    double f = 0.001 ;

    if (f >= -0.000001 && f <= 0.000001 )
    {
        printf("浮点数为零！！\n");
    }
    else
    {
        printf("浮点数不为零！！\n");
    }
    

	return 0;
}