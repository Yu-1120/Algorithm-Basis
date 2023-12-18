#ifndef     __TYPE_H
#define     __TYPE_H

// 结构体声明
typedef struct node
{
    char Name[32];
    int age ;
    char skill[32];
    bool udel ;  // 用于标记数据是否有效 ， 
                //如果有效该成员为 
                //真-- 数据有  
                //假 -- 数据无效 
}Std , *P_Std;

// 定义一个宏用来表示 人数
#define     PEOPLE      10
#define     DE_BUG


#endif