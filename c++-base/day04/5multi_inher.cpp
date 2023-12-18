/*05-多重继承*/
#include <iostream>

using namespace std;

//电话类
class Phone{
public:
    Phone(double p=1000):price(p)
    {
        cout<<"Phone()"<<endl;
    }

    ~Phone()
    {
        cout<<"~Phone()"<<endl;
    }

    //读私有的成员的接口
    double get_price()
    {
        return this->price;
    }

    void call()
    {
        cout<<"打电话"<<endl;
    }

private:
    double price;
};

//MP3类
class Mp3{
public:
    Mp3(double p=300):price(p)
    {
        cout<<"Mp3()"<<endl;
    }

    ~Mp3()
    {
        cout<<"~Mp3()"<<endl;
    }

    //读私有的成员的接口
    double get_price()
    {
        return this->price;
    }

    void play(string song)
    {
        cout<<"播放"<<song<<endl;
    }

private:
    double price;
};

//相机类
class Camera{
public:
    Camera(double p=500):price(p)
    {
        cout<<"Camera()"<<endl;
    }

    ~Camera()
    {
        cout<<"~Camera()"<<endl;
    }

    //读私有的成员的接口
    double get_price()
    {
        return this->price;
    }

    void capture()
    {
        cout<<"拍照"<<endl;
    }

private:
    double price;
};

//多重继承
class SmartPhone:public Phone,public Mp3,public Camera{
public:
    double get_price()
    {
        return Phone::get_price()+Mp3::get_price()+Camera::get_price()+3000;
    }

};

int main()
{
    SmartPhone iphone13;
    cout<<iphone13.get_price()<<endl;
    cout<<iphone13.Camera::get_price()<<endl;
    iphone13.play("蔡徐坤");
/*
    这段代码展示了多重继承的概念。在C++中，一个类可以继承多个基类，这里定义了三个基类：Phone、Mp3和Camera。
    然后定义了一个SmartPhone类，它继承了这三个基类。在SmartPhone类中，通过调用基类的get_price()函数来获取各个基类的价格，
    并将它们相加再加上3000得到SmartPhone的总价格。在main函数中，创建了一个SmartPhone对象iphone13，并分别输出了它的总价格、
    相机的价格以及播放歌曲的功能。

*/
    return 0;
}
