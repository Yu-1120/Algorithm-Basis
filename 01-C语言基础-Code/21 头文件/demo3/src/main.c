#include "Main.h"


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

