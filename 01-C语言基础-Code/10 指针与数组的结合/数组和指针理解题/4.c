#include <stdio.h>

int main(void)
{
    int arr[] = { 1, 3, 5, 7, 9};
    int i, *p = arr; // p 指向的是首元素的首地址 （p只是一个普普通通的整型指针）
	int len = sizeof(arr) / sizeof(int);
	
    for(i=0; i<len; i++)
    {
        printf("*(p+%d) = %d\n",i, *(p+i));  
    }
    printf("\n");
	
    return 0;
}