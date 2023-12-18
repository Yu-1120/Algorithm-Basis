#include <stdio.h>

int main(void)
{
    int arr[] = { 1, 3, 5, 7, 9};
    int i, *p = arr, len = sizeof(arr) / sizeof(int);


    for(i=0; i<len; i++)
    {
        //   * 和 ++ 得优先级是同级的 ， 又因为当前这一级的结合性是从右往左 ， 因此先 p++  , 但是是后缀所以先预算再佳佳
        printf("%d\n", *p++ );   // 先运算得到 1  ， 然后再地址+1 
		printf("%d\n", (*p)++ );  // 先得到p得内容  3 ， 然后再对3进行自加
        for (size_t j = 0; j < len ; j++)
        {
            printf("arr[%d]:%d\t" , j , arr[j]);
        } 
        printf("\n");

    }
    printf("\n");
	

    


    return 0;
}