#include <stdio.h>

// 结构体声明   -->   不占用内存空间
struct node
{
    int i ;
    char c ;
    float f ;
    struct{      // 结构体内部的成员
        float ff ;
        double d ;
    } info ;
};



int main(int argc, char const *argv[])
{
    struct node data = {
        .c = 'A',
        .i = 1024 ,
        .f = 3.489 ,
        .info.d = 665.1234,
        .info.ff = 3.444
    };

    struct node * p = &data ;


    printf("d:%lf , ff:%lf \n" , data.info.d , data.info.ff  );

    printf("d:%lf , ff:%lf \n" , p->info.d , p->info.ff  );


    return 0;
}
