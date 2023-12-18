#ifndef     __DEMO_H
#define     __DEMO_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


// 定义一个宏用来表示 人数
#define     PEOPLE      10
#define     DE_BUG

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


void show_ui(void);

int get_usr_input( void );

P_Std input_std_info();

int add_stu( Std * ptr );

void display_info( Std * ptr);

int info_find(Std * ptr);

bool updata_info(Std * ptr);

bool del_info(Std * ptr);



#endif