/*06-强转和函数对象练习*/
#include <iostream>
#include <cstring>

using namespace std;

class Product{
public:
    Product(double p=0.0,size_t c=0):price(p),count(c){}

    //获取个数
    operator size_t()
    {
        return this->count;
    }

    //获取单价
    operator double()
    {
        return this->price;
    }

    //函数对象 ---- 求总价
    double operator()()
    {
        return this->price*this->count;
    }


    friend ostream& operator<<(ostream &os,const Product &p);
private:
    double price;//单价
    size_t count;//个数
};

ostream& operator<<(ostream &os,const Product &p)
{
    return os<<"单价:"<<p.price<<" 数量:"<<p.count;
}

int main()
{
    Product Tesla(345623.5,10);

    cout<<"数量:"<<(size_t)Tesla<<endl;
    cout<<"单价:"<<(double)Tesla<<endl;
    cout<<"总价:"<<Tesla()<<endl;

    return 0;
}
