/*11 - 类类型的空指针访问成员函数*/
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

class A{
public:
    void show()
    {
        cout<<"show A"<<endl;
    }

    void show_num()
    {
        cout<<"test"<<endl;
        cout<<this->num<<endl;
    }

private:
    int num;
};


int main()
{
    A *pa = NULL;

    //pa->show();
    pa->show_num();

    cout<<"exit!"<<endl;
    return 0;
}
