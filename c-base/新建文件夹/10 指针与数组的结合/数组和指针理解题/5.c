#include <stdio.h>

int main(void)
{
    int arr[] = { 1, 3, 5, 7, 9};
    int *p = &arr[2];  // p只是一个普普通通的整型指针） , 并指向的 数据5 的地址
      //  arr[2]  是数据  5    & 则把数据5 的地址进行取出 
	
    printf("%d, %d, %d, %d, %d\n", *(p-2), *(p-1), *p, *(p+1), *(p+2) );
	
    return 0;
}