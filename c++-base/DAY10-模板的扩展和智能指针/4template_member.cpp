/*04 - 类模板的模板成员*/
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

template <typename T>
class Beta{
public:
    Beta(int i,T t):t1(i),t2(t){}

    void show()const
    {
        t1.show();
        t2.show();
    }

    //函数模板成员
    template <typename V>
    V bobo(V v,T t)
    {
        return t1.get_value()+t2.get_value()+v/t;
    }

private:
    //类模板成员
    template <typename K>
    class Test{
    public:
        Test(K k):value(k){}

        void show()const
        {
            cout<<this->value<<endl;
        }

        K get_value()const
        {
            return this->value;
        }

    private:
        K value;
    };

    //使用类模板成员
    Test<int> t1;
    Test<T> t2;
};


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
