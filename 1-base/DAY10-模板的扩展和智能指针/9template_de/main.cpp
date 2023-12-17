#include <iostream>
#include "comparetor.h"

using namespace std;

int main()
{
    Comparetor<int> c1(100,200);
    cout<<c1.max()<<endl;

    Comparetor<const char *> c2("byebye","hello");
    cout<<c2.max()<<endl;

    return 0;
}
