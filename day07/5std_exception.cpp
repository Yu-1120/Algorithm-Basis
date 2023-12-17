/*05-系统预定义异常*/
#include <iostream>
#include <stdexcept>//系统预定义异常头文件

using namespace std;

int main()
{
    try {
        //int *pi = new int[0x1fffffff];//空间过大,抛出内存分配异常

        string str("hello");
        char ch = str.at(10);//越界，抛出越界异常
        cout<<ch<<endl;
    }/* catch (bad_alloc &e) {//内存分配异常
        cout<<"捕获到了bad_alloc的异常"<<endl;
        cout<<e.what()<<endl;//异常原因
    } catch(out_of_range &e){//越界异常
        cout<<"捕获到了out_of_range的异常"<<endl;
        cout<<e.what()<<endl;//异常原因
    }*/catch(exception &e){//可以捕获所有预定义的异常
        cout<<"捕获到了exception的异常"<<endl;
        cout<<e.what()<<endl;//异常原因
    }

    return 0;
}
