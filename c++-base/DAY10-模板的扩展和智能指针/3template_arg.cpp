/*03 - 类模板的非类型参数和模板参数*/
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

template <typename T1,int T2=10/*非类型参数*/>
class A{
public:
    static void print_type()
    {
        cout<<typeid(T1).name()<<" "
            <<T2<<endl;
    }
};

//类模板 ----- 必须可以用T类型构造，必须带有show成员函数
template <typename T>
class King{
public:
    King(T t):t(t){}

    void show()const
    {
        cout<<this->t<<endl;
    }

private:
    T t;
};

//模板型模板参数
template <template <typename T> class Thing=King/*模板参数*/,typename K=int>
class Crab{
public:
    //Thing模板可以使用T类型构造
    Crab(int i=0,double d=0.0):t1(i),t2(d){}

    //Thing必须要有show成员函数
    void show()const
    {
        t1.show();
        t2.show();
    }

private:
    Thing<int> t1;
    Thing<double> t2;
    K k;
};


int main()
{
    /*
    const int num = 99;

    A<int,100>::print_type();
    A<int,num>::print_type();
    A<int>::print_type();
    */

    Crab<King> cb(14,31.4);
    cb.show();

    return 0;
}
