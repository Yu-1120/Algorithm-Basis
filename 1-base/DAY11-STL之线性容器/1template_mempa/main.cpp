#include <iostream>
#include "beta.hpp"

using namespace std;

int main()
{
    //使用带有类模板成员的类模板
    //T ---> double  K--->int
    Beta<double> bt(14,44.5);
    bt.show();

    //V---int
    cout<<bt.bobo<int>(5,3.14)<<endl;
    //V---double
    cout<<bt.bobo(7.8,2.64)<<endl;

    return 0;
}
