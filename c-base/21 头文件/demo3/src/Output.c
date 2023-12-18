#include "Output.h"


void show_ui(void)
{
    printf("************************************\n");
    printf("*********请输入需要的功能选项*********\n");
    printf("***********1. 添加学员***************\n");
    printf("***********2. 显示学员***************\n");
    printf("***********3. 修改学员***************\n");
    printf("***********4. 删除学员**************\n");
    printf("************************************\n");
    printf("************************************\n");

    return ;
}


void display_info( Std * ptr)
{
    // 遍历数据
    int i;
    for ( i = 0; i < PEOPLE ; i++)
    {
        if (!(ptr+i)->udel) // 判断数据是否有效， 如果有效则找下一个
        {
            continue ; // 跳过本次循环 找下一个
        }
        printf("学员%d:%s--%d--%s--%d\n" , i ,
            (ptr+i)->Name ,(ptr+i)->age ,(ptr+i)->skill , (ptr+i)->udel );  
    }
    return ;
}




int info_find(Std * ptr)
{
    if ( NULL == ptr )
    {
        return -1  ;
    }

    int age  = -1 ;
    printf("请输入学员的年轮：\n");
    scanf("%d" , &age );
    while(getchar() != '\n');


    // 遍历数据
    int i = -1 ;
    for ( i = 0; i < PEOPLE ; i++)
    {
        if (!(ptr+i)->udel) // 判断数据是否有效， 如果有效则找下一个
        {
            continue ; // 跳过本次循环 找下一个
        }
        else if ((ptr+i)->age == age)  // 如果数据有效， 则检查年龄是否匹配
        {
            return i   ;
        }
        
    }

    return -1 ;
}