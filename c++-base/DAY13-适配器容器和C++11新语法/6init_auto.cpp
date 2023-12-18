/*06-大括号初始化,auto自动类型推断,decltype的用法*/
#include <iostream>
#include <list>
#include <typeinfo>

using namespace std;

class A{
public:
    A(int i=0,double w=0.0):id(i),weight(w){}

    void show()const
    {
        cout<<this->id<<":"<<this->weight<<endl;
    }

private:
    int id;
    double weight;
};

int add(int a,int b)
{
    return a+b;
}

template <typename T,typename K>
void func(T t,K k)
{
   decltype(t*k) tk;//tk就是t*k的类型
}

int main()
{
    /*新的大括号初始化语法*/
    int x = {5};
    short s_arr[5] {4,5,6,7,8};

    int *pa = new int[4] {1,2,3,4};

    A a1{2,3.4};
    A a2{5,6.7};

    cout<<x<<endl;
    for(int i=0;i<5;i++)
        cout<<s_arr[i]<<" ";
    cout<<endl;

    for(int i=0;i<4;i++)
        cout<<pa[i]<<" ";
    cout<<endl;

    a1.show();
    a2.show();
    cout<<"-----------------------------"<<endl;

    //auto实现类型推断，省略声明时的类型
    auto num = 10;//int
    auto pt = &num;//int *
    int add(int,int);
    auto pf = add;//函数指针类型 int(*)(int,int);

    list<int> li;
    auto it = li.begin();//迭代器类型 list<int>::iterator

    cout<<typeid(num).name()<<endl;
    cout<<typeid(pt).name()<<endl;
    cout<<typeid(pf).name()<<endl;
    cout<<typeid(it).name()<<endl;
    cout<<"-----------------------------"<<endl;

    //decltype获取表达式类型
    int n;
    double x1;

    decltype(x1*n) p;//p是double类型
    decltype(&x1) q;//q是double *类型

    cout<<typeid(p).name()<<endl;
    cout<<typeid(q).name()<<endl;

    return 0;
}
