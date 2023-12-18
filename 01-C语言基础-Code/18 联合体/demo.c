#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 声明结构体
typedef struct demo
{
    char Nmae[32];
    char Type ;  // S 学生  T  老师  F  打饭阿姨  Q  清洁工
    union 
    {
        float num ; // 成绩
        int i ; // 手抖值
        char c ; // 清洁能力
    }stat;
}Node ;




int main(int argc, char const *argv[])
{
    Node data [3] ;

    
    // 把"Even" 拷贝到 结构体数据则第0 位， 希望拷贝32 字节
    strncpy(data[0].Nmae , "Even" , 32 );
    data[0].Type = 'Q' ;
    data[0].stat.c = 'A';

    // 学生
    strncpy((data+1)->Nmae , "Jacy" , 32 );
    (data+1)->Type = 'S' ;
    (data+1)->stat.num = 13.86 ;

    // 阿姨
    strncpy((data+2)->Nmae , "CuiHua" , 32 );
    (data+2)->Type = 'F' ;
    (data+2)->stat.i = 13 ;

    for (size_t i = 0; i < 3 ; i++)
    {
        switch((data+i)->Type)
        {
            case 'Q':
                printf("当前输出为清洁工：\n 名字：%s\t人猿类型:%c\t清洁能力：%c\n",
                    (data+i)->Nmae ,(data+i)->Type , (data+i)->stat.c );
                break ;
            case 'S':
                printf("当前输出为学生：\n 名字：%s\t人猿类型:%c\t学习能力：%f\n",
                    (data+i)->Nmae ,(data+i)->Type , (data+i)->stat.num );
                break ;
            case 'F':
                printf("当前输出为打饭阿姨：\n 名字：%s\t人猿类型:%c\t抖肉能力：%d\n",
                    (data+i)->Nmae ,(data+i)->Type , (data+i)->stat.i );
                break ;
        }
    }
    
    
    printf("%s,%s,%d\n" , __FILE__ , __FUNCTION__ , __LINE__);

#line   998  "Hello.c"
    printf("%s,%s,%d\n" , __FILE__ , __FUNCTION__ , __LINE__);


    return 0;
}
