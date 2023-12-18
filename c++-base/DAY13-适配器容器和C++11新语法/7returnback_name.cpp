/*07 - 返回值类型后置,using起别名*/
#include <iostream>
#include <array>
#include <typeinfo>

using namespace std;

auto add(double a,int b) -> double//返回double
{
    return a+b;
}

//模板中使用
template <typename T,typename K>
auto func(T t,K k) -> decltype(t*k)
{
    return t*k;
}

//使用using给模板起别名
template <typename T>
using arr12 = array<T,12>;

int main()
{
    cout<<add(1.1,3)<<endl;
    cout<<func(1.1,3)<<endl;

    array<int,10> ac = {1,2,3,4,5,6,7,8,9,20};
    //using给类型起别名
    using IT = array<int,10>::iterator;
    IT it = ac.begin();
    cout<<*it<<endl;

    arr12<double> ad;//array<double,12>
    arr12<string> as;//array<string,12>

    return 0;
}
