/*04-多层异常的抛出和捕获*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
   int a[7] = { 1,2,3,4,5,6,7};
    int *ptr= (int* )(&a+1);
    printf("%d %d\n ",a[0],ptr); //1是值,6422000是地址 6422028是最后的那位的值的地址
    printf("%d %d\n",a+1,ptr);  
    
    //是a[2]的地址   a[6]的地址
     printf("%d %d\n ",*(a+1),*(ptr-1));  //2 ,7  必须减一才能拿到值 

    // printf("%d %d ",*(a+1),*(ptr));  //2 ,0  必须减一才能拿到值，溢出了    

    return 0;
}
