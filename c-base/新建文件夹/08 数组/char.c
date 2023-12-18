#include <stdio.h>

int main(int argc, char const *argv[])
{
    char ch1 [5] = {'H','e','l','l','o'} ; // 定义一个字符类型的数组并把'H','e','l','l','o' 一个一个存进去 
    // char ch2 [6] = {"Even"} ; // 定义一个字符型的数组， 并把 "Hello" 字符串存放到数组中 ，因此该数组为字符串数组

    // char ch3 [6] = "Hello" ;  // 与ch2 一样， 大括号可以省略

    // ch3[1] = 'E' ; // 可以， 把数组中第二个元素‘e’修改为‘E’
    //ch3 = "Even" ; //  不可以， 只有在初始化的时候才能整体赋值
  
    printf("%s\n" , ch1); 
    printf("%d\n" , ch1[5]); // 属于越界的访问， 不能确定是什么值


    // for (size_t i = 0; i < 5 ; i++)
    // {
    //     printf("ch1[%d]:%c\n" , i , ch1[i]);
    // }
    
;



    return 0;
}
