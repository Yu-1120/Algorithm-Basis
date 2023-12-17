/*05-纯虚函数和抽象类*/
#include <iostream>

using namespace std;

//(纯)抽象类
class Animal{
public:
    //纯虚函数
    virtual void show()=0;
    virtual void run()=0;
    virtual void eat()=0;
};

class Dog:public Animal{
public:
    //实现父类中所有的纯虚函数
    virtual void show()
    {
        cout<<"Dog show"<<endl;
    }

    virtual void run()
    {
        cout<<"Dog Run"<<endl;
    }

    virtual void eat()
    {
        cout<<"Dog eat meat"<<endl;
    }
};

int main()
{
    //抽象类不能构造对象
    //Animal an;
    Dog dg;
    dg.show();
    dg.run();
    dg.eat();

    return 0;
}
