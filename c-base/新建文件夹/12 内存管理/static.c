#include <stdio.h>


void func(void)
{

    int a  = 250  ;
    static int b = 100 ;

    printf("a:%d , b:%d \n " , ++a , ++b );

}


int main(void)
{

    func();
    func();
    func();
   
    return 0;
}