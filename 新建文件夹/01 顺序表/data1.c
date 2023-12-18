#include <stdio.h>
#include <stdlib.h>

// 给我们需要存放的数据类型取别名， 方便以后存放不同类型的数据
typedef  int   Data_Type ;

#define     DATA_SIZE   10

// 设计一个管理结构体
typedef struct data
{
    Data_Type * Data_Enter ;    // 堆空间的入口地址
    int     Size ;              // 数据总量（可以存放的数据量） 数组最大的下标 
    int     Last ;              // 当前的使用量     数组当前使用的下标
}Data ,  * P_Data;


Data * init_data()
{
    // 在堆中申请一个管理结构体的内存空间
    P_Data ptr = calloc(1,sizeof(Data));

    // 申请堆空间来作为顺序表的存储空间
    ptr->Data_Enter = calloc( DATA_SIZE ,sizeof(Data_Type));

    ptr->Size = DATA_SIZE ; // 设置顺序表的大小为 10 
    ptr->Last = 0 ;  // 设置当前使用量为 0 

    return ptr ; // 返回管理结构体指针
}

int ins_data( Data* Ctrl , Data_Type new_data )
{
    //  判断管理结构体指针是否为空
    //  当前管理结构体中现有数据是否已满
    if(Ctrl == NULL || Ctrl->Last == Ctrl->Size )
    {
        printf("当前内存已满！！！\n");
        return 0 ; 
    }

    // 把数据存放到顺序表的内存中
    Ctrl->Data_Enter[Ctrl->Last]  = new_data ;
    // *(Ctrl->Data_Enter+Ctrl->Last) = new_data;

    // 让顺序表的当前下标往后移动
    Ctrl->Last ++ ;

    return Ctrl->Last ; // 为具体的下标值
}

int displayer_data(Data * Ctrl)
{
    //  判断管理结构体指针是否为空
    //  当前管理结构体中现有数据是否已满
    if(Ctrl == NULL || Ctrl->Last == 0 )
    {
        printf("顺序表为空！！！\n");
        return Ctrl->Last; // 下标为 size 
    }

    for (int i = 0; i < Ctrl->Last ; i++)
    {
        printf("data:%d\n" , *(Ctrl->Data_Enter+i));
    }
    
    return Ctrl->Last ;
}

int main(int argc, char const *argv[])
{
    // 初始化
    P_Data Ctrl = init_data( ); 
    
    printf("Data_Enter:%p\t Size:%d\t Last:%d\n" , 
        Ctrl->Data_Enter , Ctrl->Size , Ctrl->Last);

    for (size_t i = 0; i < 100; i++)
    {
         // 创建数
        printf("请数据需要插入的数据：\n");
        Data_Type new_data ;
        scanf("%d" , &new_data);
        while(getchar()!= '\n');

        // 插入数据
       if(!ins_data(Ctrl , new_data))
       {
           break ;
       }
    }

    // 显示数据
    displayer_data(Ctrl);
    
   

    // 释放 
    free(Ctrl->Data_Enter);
    free(Ctrl);

    return 0;
}
