#include <stdio.h>

int main(void)
{

    int a[5] = {1,2,3,4,5};
    int b[3][4] = { {250,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    printf("&a: %p\n",&a);       
    printf("&a+1:   %p\n",&a+1);     
    printf("a:  %p\n",a);            
    printf("a+1:    %p\n",a+1);      

    printf("\n");
    printf("&b: %p\n",&b);       
    printf("&b+1:   %p\n",&b+1);     
    printf("\n");
    printf("b:  %p\n",b);      
    printf("b+1:    %p\n",b+1);    
    printf("\n");
    printf("*b: %p\n",*b);       
    printf("*b+1:   %p\n",*b+1);     
    printf("\n");
    printf("**b:    %d\n",**b);      
    printf("**b+1:  %d\n",**b+1);   


    printf("**(b+1):%d\n",**(b+2));    

    printf("*(*(b+2)+2):%d\n",*(*(b+2)+2));  


    // 使用指针来访问二维数组的每一个元素
    for (size_t i = 0; i < 12; i++)
    {
        printf("%d\t" ,*((*b)+i) );
    }
    
    // 使用数组来访问二维数组
    for (size_t i = 0; i < 3 ; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            printf("b[%d][%d]:%d\t" , i , j , b[i][j] );
        }
        
    }
    

    // *((*b)+i)





    return 0;
}
