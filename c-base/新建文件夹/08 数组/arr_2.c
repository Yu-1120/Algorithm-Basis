#include <stdio.h>

int main(void)
{
    int arr[2][3] = { {1,2,3} , { 4,5,6} };
    int arr1[2][3] = { 1,2,3,4,5,6};

    // int (*p ) [3]  = &arr ; 

    int *p = arr ; // p指向数组arr 的首元素

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("arr[%d][%d]:%d\t" ,i ,j , arr[i][j] );
        }
    }

    printf("\n");

    for (int i = 0; i < 6 ; i++)
    {           //           *arr   得到元素1 的地址  + 1 则是加一个 int 类型
        printf("*(*(arr+%d)):%d\t" , i,*(*(arr)+i) );
    }

    printf("\n");

    for (int i = 0; i < 6 ; i++)
    {       //       arr  指的是首元素的首地址  {1,2,3} 的首地址  + 1则 + 3个整型
        printf("*(*(arr+%d)):%d\t" , i,*(*(arr+i)) );
    }
    

    for (int i = 0; i < 6 ; i++)
    {   //                      p 只是一个普通的整型指针， 与二维数组没有任何的关系
        printf("*(p+%d)：%d\n" , i ,*(p+i));
    }

    // printf("**p:%d\n" , **p);

    




	
    return 0;
}