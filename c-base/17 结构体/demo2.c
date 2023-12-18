#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 结构体声明   -->   不占用内存空间
struct TieZhu
{
    char * Book ;
    float Price ;
    char Name [32] ;
};



int main(int argc, char const *argv[])
{
    // 申请一个堆空间用来存放结构体类型
    struct TieZhu *p = calloc(1, sizeof(struct TieZhu));

    p->Book = "葵花点穴手" ;  // Book 是一个指针， 它指向常量区
    p->Price = 998.34 ;
   // p->Name = "马某人" ; // 错误写法， 因为成员Name是一个数组，不允许如此赋值
    strncpy(p->Name , "马某人" , 32 ); // 使用字符串拷贝函数来给数组赋值

    // 如何引用
    printf("Book:%s \nPrice:%f  \nName:%s\n" , 
            p->Book,  p->Price , p->Name);


    return 0;
}
