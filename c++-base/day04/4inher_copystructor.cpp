/*04-继承中的拷贝构造和名字隐藏*/
#include <iostream>
#include <cstring>

using namespace std;
/*
    这段代码展示了C++中继承中的拷贝构造函数和名字隐藏。

    首先定义了一个基类A，包含一个私有成员变量pdata（字符指针类型）和三个公有成员函数：默认构造函数、拷贝构造函数和析构函数。

    接着定义了一个派生类B，继承自基类A，包含一个私有成员变量abc（字符指针类型）和三个公有成员函数：

    默认构造函数、拷贝构造函数和析构函数。在main函数中，创建了两个B类的对象b1和b2，通过拷贝构造函数初始化b2。

    最后，访问了子类B的成员函数show()和父类A的隐藏成员函数show()。

*/
class A{
public:
    A()
    {
        cout<<"A()"<<endl;
        this->pdata = new char[10];
        memset(this->pdata, 0, 10);
    }

    //拷贝构造
    A(const A &a)
    {
        cout<<"A(const A &a)"<<endl;
        this->pdata = new char[10];
        memcpy(this->pdata,a.pdata,10);
    }

    ~A()
    {
        cout<<"~A()"<<endl;
        delete[] this->pdata;
    }

    void show()
    {
        cout<<"show A"<<endl;
    }

private:
    char *pdata;
};

class B:public A{
public:
    B()
    {
        cout<<"B()"<<endl;
        this->abc = new char[10];
        memset(this->abc, 0, 10);
    }

    //子类拷贝构造 --- 通过初始化参数列表调用父类的拷贝构造
    B(const B &b):A(b)
    {
        cout<<"B(const B &b)"<<endl;
        this->abc = new char[10];
        memcpy(this->abc,b.abc,10);
    }

    ~B()
    {
        cout<<"~B()"<<endl;
        delete[] this->abc;
    }

    void show()
    {
        cout<<"show B"<<endl;
        //this->A::show();
    }

private:
    char *abc;
};

int main()
{
    B b1;
    B b2 = b1;

    //父类同名成员被隐藏，默认访问子类的同名成员
//    b2.show();
//    A()
//    B()
//    A(const A &a)
//    B(const B &b)
//    show B  ！！！
//    ~B()
//    ~A()
//    ~B()
//    ~A()


    //访问父类的隐藏成员
//    b2.A::show();
//    A()
//    B()
//    A(const A &a)
//    B(const B &b)
//    show A  !!!!
//    ~B()
//    ~A()
//    ~B()
//    ~A()




    /*
        A()
        B()
        A(const A &a)
        B(const B &b)
        show B
        show A
        ~B()
        ~A()
        ~B()
        ~A()

    */
    return 0;
}
