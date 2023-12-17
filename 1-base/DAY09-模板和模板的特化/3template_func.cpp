/*03 - 函数模板*/
#include <iostream>

using namespace std;

class Float{
public:
    Float(float f=0.0f):f(f){}

    //重载>运算符
    bool operator>(const Float &ff)
    {
        return this->f>ff.f;
    }

    //重载<<
    friend ostream& operator<<(ostream &os,const Float &ff)
    {
        return os<<ff.f;
    }

private:
    float f;
};

//声明函数模板
template<typename T/*类型参数*/,typename K>
T mymax(T a,T b)
{
    K x;

    T max = a>b?a:b;

    return max;
}


int main()
{
    //函数模板的使用---理解就是说把函数传进去求解
    //cout<<mymax<int>(10,20)<<endl;
    //cout<<mymax<double>(76.5,23.1)<<endl;
    //cout<<mymax<Float>(Float(12.3f),Float(34.1f))<<endl;

    //函数模板的类型推断
    //cout<<mymax(10,20)<<endl;
    //cout<<mymax(76.5,23.1)<<endl;

    //cout<<mymax(10,20)<<endl;//有类型参数未出现在形参中，无法推断
    cout<<mymax<int,char>(10,20)<<endl;

    return 0;
}
