/*06 - 类模板的类模板友元*/
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

//类模板的声明
template <typename N>
class B;

//类模板
template <typename T>
class A{
public:
    A(T t):t(t){}

    //友元类模板
    //约束型
    friend class B<T>;

    //非约束型
    template <typename K>
    friend class C;

private:
    T t;
};

template <typename N>
class B{
public:
    void func(N n)
    {
        A<int> a(100);
        cout<<a.t<<","<<n<<endl;
    }
};

template <typename K>
class C{
public:
    void func(K k)
    {
        A<int> a(100);
        cout<<a.t<<","<<k<<endl;
    }
};

int main()
{
    B<int> b;
    b.func(11);

    C<double> c;
    c.func(11.1);

    return 0;
}
