#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3;
    int *arr[3] = {&a, &b, &c};//整型指针数组
    int **parr = arr; // 第一部分 *p ， 第二部分 int * 说明类型   为指针类型   +1 则+1个指针类型 8字节（64） 
	
    //            arr[0]  --> &a   *&a --> a 
    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));
    return 0;
}