/*02 - 类模板参数的默认值*/
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

template <typename T1,typename T2=short,typename T3=int/*模板参数的默认值*/>
class Trib{
public:
    static void print_type()
    {
        cout<<typeid(T1).name()<<" "
            <<typeid(T2).name()<<" "
            <<typeid(T3).name()<<endl;
    }
};

template <typename T1,typename T2,typename T3=T2/*模板参数的默认值*/>
class B{
public:
    static void print_type()
    {
        cout<<typeid(T1).name()<<" "
            <<typeid(T2).name()<<" "
            <<typeid(T3).name()<<endl;
    }
};

int main()
{
    //Trib<double,char,short>::print_type();
    //Trib<double,char>::print_type();
    //Trib<double>::print_type();

    B<double,char,short>::print_type();
    B<double,char>::print_type();

    return 0;
}
