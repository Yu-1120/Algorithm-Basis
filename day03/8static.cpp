/*07-静态成员*/
#include <iostream>
#include <cstring>

using namespace std;

class A{
public:
    int x;
    static int num;//静态成员变量

    void show()
    {
        cout<<"show()"<<endl;
    }

    //静态成员函数
    static void show1()   //只能静态成员函数去访问静态成员变量
    {
        //x = 1;
        //show();//不可以访问非静态成员
        A::num = 1;//可以访问静态成员变量

        cout<<"static show()"<<endl;
    }
};

//静态成员变量必须在类外初始化
int A::num = 11;

int main()
{
    //静态成员通过类名访问
    A::num = 100;
    cout<<A::num<<endl;
    A::show1();

    A a;
    a.show1();
    a.num = 66;

    A b;
    cout<<b.num<<endl;
    /*
        100
        static show()
        static show()
        66



    */
    return 0;
}
