#include <demo.h>

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

bool updata_info(Std * ptr)
{
    if ( NULL == ptr )
    {
        return false ;
    }

    int off_set = info_find(ptr); // 通过查找函数来找到具体的数据所在的下标（偏移量）
    if (-1 == off_set )
    {
        return false ;
    }
    

    Std *new = input_std_info(); 
    memcpy( (ptr+off_set) , new , sizeof(Std)); // 把新的学员信息拷贝到数组中

    free(new) ; //释放 指针 new 的堆空间
    new =   NULL ; // new指向空

    return true   ;

}

bool del_info(Std * ptr)
{
    if ( NULL == ptr )
    {
        return false ;
    }

    int off_set = info_find(ptr); // 通过查找函数来找到具体的数据所在的下标（偏移量）
    if (-1 == off_set )
    {
        return false ;
    }


    (ptr+off_set)->udel = false ; // 把数据有效的标记设置为 false 
    

    return true ;
}


int main(int argc, char const *argv[])
{

    // 初始化
    P_Std ptr = (P_Std)calloc(PEOPLE , sizeof(Std)); // 申请了10个结构体大小的堆空间
    if (ptr == NULL)
    {
        perror("申请空间失败"); // 直接输出错误并打印错误的原因
        return -1 ; // 退出进程
    }
    

    while(1)
    {
        show_ui();

        int cmd = get_usr_input();

        switch(cmd)
        {
            case 1:
                printf("有新同学报道！！\n");
                add_stu(ptr); // 调用添加的函数， 并传递堆空间地址
                break ;
            case 2:
                printf("显示学员信息\n");
                display_info(ptr);
                break ;
            case 3:
                printf("修改学员信息\n");
                updata_info(ptr);
                break ;
            case 4:
                printf("删除学员信息\n");
                del_info(ptr);
                break ;
            default:
                printf("不讲武德， 小伙子耗子为止\n");
                break ;
        }
    }

    return 0;
}

