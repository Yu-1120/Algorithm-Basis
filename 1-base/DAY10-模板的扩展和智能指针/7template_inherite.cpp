/*07 - 类模板的继承*/
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

/*
template <typename T>
class BaseA{
public:
    BaseA(T t):data(t){}

    void show()const
    {
        cout<<this->data<<endl;
    }

private:
    T data;
};

//1.类继承类模板
class Derived:public BaseA<int>{
public:
    Derived(int i=0):BaseA<int>(i){}
};


class BaseA{
public:
    BaseA(int t):data(t){}

    void show()const
    {
        cout<<this->data<<endl;
    }

private:
    int data;
};

//2.类模板继承类
template <typename T>
class Derived:public BaseA{
public:
    Derived(int i,T t):BaseA(i),data2(t){}

    void show()const
    {
        this->BaseA::show();//父类数据
        cout<<this->data2<<endl;
    }

private:
    T data2;
};


template <typename T>
class BaseA{
public:
    BaseA(T t):data(t){}

    void show()const
    {
        cout<<this->data<<endl;
    }

private:
    T data;
};

//3.类模板继承类模板
template <typename N>
class Derived:public BaseA<N>{
public:
    Derived(N n1,N n2):BaseA<N>(n1),data2(n2){}

    void show()const
    {
        this->BaseA<N>::show();//父类数据
        cout<<this->data2<<endl;
    }

private:
    N data2;
};
*/

class BaseA{
public:
    BaseA(){cout<<"BaseA()"<<endl;}
};

class BaseB{
public:
    BaseB(){cout<<"BaseB()"<<endl;}
};

template <typename K,K n>
class BaseC{
public:
    BaseC():data(n){cout<<"BaseC()"<<endl;}

private:
    K data;
};

//4.继承模板参数
template <typename T>
class Derived:public T{
public:
    Derived():T(){cout<<"Derived()"<<endl;}
};


int main()
{
    //Derived d1(100);
    //d1.show();

    //Derived<double> d2(100,22.2);
    //d2.show();

    //Derived<double> d3(11.1,33.3);
    //d3.show();

    //Derived<BaseA> d4;
    Derived<BaseC<int,10>> d4;

    return 0;
}
