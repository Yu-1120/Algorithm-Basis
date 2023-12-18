/*05 - 类模板的函数模板友元*/
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

//模板的声明
template <typename K>
void count();

template <typename N>
void report(N &n);


//类模板
template <typename T>
class FriendTp{
public:
    FriendTp(T t):t(t){};

    //友元函数模板
    //约束型 ----- 使用T类型参数
    friend void count<T>();
    friend void report</*FriendTp<T>*/>(FriendTp<T> &tt);

    //非约束型 ----- 不使用T类型
    template<typename T1,typename T2>
    friend void show(T1 &t1,T2 &t2);

private:
    T t;
};

//函数模板
template <typename K>
void count()
{
    cout<<"size = "<<sizeof(FriendTp<K>)<<endl;
}

template <typename N>
void report(N &n)
{
    cout<<n.t<<endl;
}

template<typename T1,typename T2>
void show(T1 &t1,T2 &t2)
{
    cout<<t1.t<<","<<t2.t<<endl;
}

int main()
{
    count<int>();

    FriendTp<int> ft1(10);
    report(ft1);

    FriendTp<double> ft2(22.2);
    report(ft2);

    //非约束型
    show(ft1,ft2);

    return 0;
}
