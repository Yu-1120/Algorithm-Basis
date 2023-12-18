#include <stdio.h>
#include <signal.h>



void func(int num )
{
    printf("当前收到  3 号信号 ， 军师让我蹲下 !!\n");
}


int test( int num  ,  void (*p)(int)  )
{

    for (size_t i = 0; i < num ; i++)
    {
        printf("num:%d\n" , num-- );
        if (num == 50 )
        {
            p(100);
        }
        
        
    }
    
    return 0 ;
}

int main(int argc, char const *argv[])
{
    void (*p)(int); // 定义一个函数指针
    p = func ; // 让指针p 指向函数  func 


    test( 100 , p  );
    

    return 0;
}
