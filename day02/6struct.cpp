/*06-结构体描述对象*/
#include <iostream>
#include <unistd.h>
#include <iomanip>

using namespace std;

//时间结构体
struct Time{
    //属性 ----- 成员变量
    int hour;//时
    int min;//分
    int sec;//秒

    //功能 ----- 成员函数
    //设置时间
    void set_time(int h=23,int m=59,int s=55)
    {
        hour = h;
        min = m;
        sec = s;
    }

    //打印时间
    void print_time()
    {
        cout<<setw(2)<<setfill('0')<<hour<<":"
            <<setw(2)<<setfill('0')<<min<<":"
            <<setw(2)<<setfill('0')<<sec<<"\r\n";
    }

    //走秒
    void run()
    {
        sec++;
        if(sec==60){
            sec = 0;
            min++;
            if(min==60){
                min = 0;
                hour++;
                if(hour==24){
                    hour = 0;
                }
            }
        }
    }
};

int main()
{
    //使用结构体类型构造对象，不需要加struct
    Time t;
      Time t1;
    //访问成员变量
    t1.hour = 14;
    t1.min = 11;
    t1.sec = 30;

    //访问成员函数
    t1.print_time();  //访问不到
    while(1){
        t.set_time();
        t.print_time();
        sleep(1);
        t.run();
    }

    return 0;
}
