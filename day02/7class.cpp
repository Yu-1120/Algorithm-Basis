/*07-类(class)描述对象*/
#include <iostream>
#include <unistd.h>
#include <iomanip>

using namespace std;

//时间类
class Time{
    //属性 ----- 成员变量
private://私有成员
    int hour;//时
    int min;//分
protected://保护成员
    int sec;//秒

public://公有成员
    //构造函数
    Time(int h=23,int m=59,int s=55):hour(h),min(m),sec(s)
    {
        cout<<"Time()"<<endl;
    }

    //功能 ----- 成员函数

    //如果需要访问私有成员变量，提供对外接口
    int get_hour()
    {
        return hour;
    }

    void set_hour(int h)
    {
        hour = h;
    }

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
            <<setw(2)<<setfill('0')<<sec<<"\r";
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
    //实用类声明对象
    Time t;
    Time *pt = new Time;

    //t.hour = 14;//私有成员类外不能访问
    //t.sec = 10;//保护成员类外不能访问

    //pt->set_time();
    pt->print_time();//公有成员类外可以访问
    //    Time()
    //    Time()
    //    23:59:55
    //本身对象在生成的时候就会调用一次构造函数   --》Time()

    //在进行print_time();会再次调用构造函数，又因为构造函数本身是带参数，所以该参数会直接跑到



//    cout<<endl;   //回车
//    pt->set_hour(10);
//    cout<<pt->get_hour()<<endl;


//    Time()
//    Time()
//    23:59:55
//    10


    delete pt; //声明对象是需要销毁的，结构体对于变量赋值的不用
    return 0;
}
