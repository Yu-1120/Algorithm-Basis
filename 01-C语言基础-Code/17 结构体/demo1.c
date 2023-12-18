#include <stdio.h>

// 结构体声明   -->   不占用内存空间
struct TieZhu
{
    char * Book ;
    float Price ;
    char Name [32] ;
};



int main(int argc, char const *argv[])
{
    // 定义  与 初始化   实际为结构体分配内存空间  栈
    struct TieZhu  c = { "Guide of Programming in the Linux Envirnment" ,
                        3.59 , "林世霖" } ; 


    // 如何引用
    printf("Book:%s \nPrice:%f  \nName:%s\n" , 
            c.Book,  c.Price , c.Name);


    return 0;
}
