/*09 - 右值引用*/
#include <iostream>
#include <vector>
#include <typeinfo>
#include <cmath>

using namespace std;


int main()
{
    int x = 10;
    int y = 33;

    //右值引用
    int &&r1 = 11;
    int &&r2 = x+y;
    double &&r3 = sqrt(3.0);

    x = 1;
    y = 2;

    cout<<r1<<":"<<&r1<<endl;
    cout<<r2<<":"<<&r2<<endl;
    cout<<r3<<":"<<&r3<<endl;

    return 0;
}
