#include <stdio.h>
#include <stdlib.h>

typedef  int   Data_Type ;

#define     DATA_SIZE   10

// 设计一个管理结构体
typedef struct data
{
    Data_Type * Data_Enter ;    // 堆空间的入口地址
    int     Size ;              // 数据总量（可以存放的数据量） 数组最大的下标 
    int     Last ;              // 当前的使用量     数组当前使用的下标
}Data ,  * P_Data;


void init_data(Data ** ptr)
{

    // 申请堆空间来作为顺序表的存储空间
    (*ptr)->Data_Enter = calloc( DATA_SIZE ,sizeof(Data_Type));

    (*ptr)->Size = DATA_SIZE ; // 设置顺序表的大小为 10 
    (*ptr)->Last = 0 ;  // 设置当前使用量为 0 

    return ;
}


int main(int argc, char const *argv[])
{
    P_Data Ctrl =NULL  ; // 定义一个结构体指针 大小为 8字节 （64位系统）
    Data abc ;  // 定义一个结构体变量
    Ctrl = &abc; // 让结构体指针指向该结构体变量
    init_data(&Ctrl); // 传递的参数为指针的地址
    
    printf("Data_Enter:%p\t Size:%d\t Last:%d\n" , 
        Ctrl->Data_Enter , Ctrl->Size , Ctrl->Last);



    return 0;
}
