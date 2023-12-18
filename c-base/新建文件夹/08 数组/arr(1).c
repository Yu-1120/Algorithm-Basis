#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr [5]  = {1,2,3,4,5} ; // 定义并初始化数组

    printf("arr[0]:%d\n" , arr[0]);

    arr[0] = 99 ;  //  把数组的第1个元素（ 偏移量为0 ）修改为 99  

    printf("arr[0]:%d\n" , arr[0]);

    arr[5] = 250 ;
    printf("arr[5]:%d\n" , arr[5]);


    printf("sizeof(arr):%ld\n" , sizeof(arr));  
    int len = sizeof(arr) / sizeof(int) ; //  求数组元素的个数 
    
    for (size_t i = 0; i < len ; i++)
    {
        printf("arr[%ld]:%d\n" , i , arr[i]);   
    }


    // 初始化越界
    int arr1 [5]  = {1,2,3,4,5,6,7,8,9} ;
    for (size_t i = 0; i < 9 ; i++)
    {
        printf("arr1[%ld]:%d\n" , i , arr1[i]);   
    }
    

    return 0;
}
