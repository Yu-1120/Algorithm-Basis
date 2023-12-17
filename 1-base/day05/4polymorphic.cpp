/*04-多态练习*/
#include <iostream>

using namespace std;

class Phone{
public:
    Phone(double p=0.0):price(p)
    {

    }

    virtual void show()
    {
        cout<<"Phone show "<<this->get_price()<<endl;
    }

    virtual void func()
    {
        cout<<"Phone:打电话"<<endl;
    }

    double get_price()
    {
        return this->price;
    }

private:
    double price;
};

class SmartPhone:public Phone{
public:
    SmartPhone(double p=0.0):Phone(p)
    {

    }

    //重写虚函数
    virtual void show()
    {
        cout<<"SmartPhone show "<<this->get_price()<<endl;
    }

    virtual void func()
    {
        cout<<"SmartPhone:打电话,听音乐,玩游戏"<<endl;
    }
};

class IPhone:public SmartPhone{
public:
    IPhone(double p=0.0):SmartPhone(p)
    {

    }

    //重写虚函数
    virtual void show()
    {
        cout<<"IPhone show "<<this->get_price()<<endl;
    }

    virtual void func()
    {
        cout<<"IPhone:打电话,听音乐,玩游戏,Apple Pay,隔空投送,IMessage"<<endl;
    }
};

//多态
void Use_Phone(Phone &p)
{
    p.show();
    p.func();
}

int main()
{
    Phone nokia(300);
    SmartPhone xiaomi(2000);
    IPhone iphone13(6000);

    Use_Phone(nokia);
    Use_Phone(xiaomi);
    Use_Phone(iphone13);

    return 0;
}
