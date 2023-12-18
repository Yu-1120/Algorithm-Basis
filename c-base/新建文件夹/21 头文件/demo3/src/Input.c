#include   "Input.h"

int get_usr_input( void )
{
    int num ;
    while(1)
    {
        int ret_val = scanf("%d" , &num ); // 如果获取正常那么 scanf 会返回1 
        if ( ret_val != 1 || num < 1 || num > 4 )
        {
            printf("小伙子不讲武德， 请输入正确的选项！！\n");
            while(getchar() != '\n'); // 先清空缓冲区
        }else
        {
            break ;
        }
    }

    return num ;
}


P_Std input_std_info()
{
    Std * new = calloc(1, sizeof(Std));
    if (new == NULL)
    {
        perror("新学员申请空间失败"); // 直接输出错误并打印错误的原因
        return NULL ; // 退出进程
    }

    new->udel = true ; // 先标记数据为有效数据

    printf("请输入学员法号：\n");
    scanf("%s" , new->Name );
    while(getchar() != '\n');

    printf("请输入学员年轮：\n");
    scanf("%d" , &new->age );
    while(getchar() != '\n');

    printf("请输入学期望技能：\n");
    scanf("%s" , new->skill );
    while(getchar() != '\n');

#ifndef  DE_BUG
    printf("new:%s--%d--%s--%d\n" , 
    new->Name ,new->age ,new->skill , new->udel );
#endif

    return new ;
}



int add_stu( Std * ptr )
{
    if ( NULL == ptr )
    {
        return -1 ;
    }

    //寻找一个空位
    int i;
    for ( i = 0; i < PEOPLE ; i++)
    {
        if ((ptr+i)->udel) // 判断数据是否有效， 如果有效则找下一个
        {
            continue ; // 跳过本次循环 找下一个
        }
        break ;
    }

    // 获取用户输入学员信息
    Std * new = input_std_info();

    memcpy( (ptr+i) , new , sizeof(Std)); // 把新的学员信息拷贝到数组中

    free(new) ; //释放 指针 new 的堆空间
    new =   NULL ; // new指向空
    
#ifdef  DE_BUG
    printf("ptr:%s--%d--%s--%d\n" , 
    (ptr+i)->Name ,(ptr+i)->age ,(ptr+i)->skill , (ptr+i)->udel );   
#endif

    return 0 ;
}


