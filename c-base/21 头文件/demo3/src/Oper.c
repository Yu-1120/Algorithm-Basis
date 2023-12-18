#include "Oper.h"


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