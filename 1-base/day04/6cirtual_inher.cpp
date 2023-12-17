/*06-多重继承的优化 ----- 虚继承*/
#include <iostream>

using namespace std;

//产品类
class Product{
public:
    Product(int p=0):price(p)
    {

    }

    double get_price()
    {
        return this->price;
    }

private:
    double price;
};

//电话类 --- 虚继承
class Phone:virtual public Product{
public:
    Phone(double p=1000):Product(p)
    {
        cout<<"Phone()"<<endl;
    }

    ~Phone()
    {
        cout<<"~Phone()"<<endl;
    }

    void call()
    {
        cout<<"打电话"<<endl;
    }

};

//MP3类
class Mp3:virtual public Product{
public:
    Mp3(double p=300):Product(p)
    {
        cout<<"Mp3()"<<endl;
    }

    ~Mp3()
    {
        cout<<"~Mp3()"<<endl;
    }

    void play(string song)
    {
        cout<<"播放"<<song<<endl;
    }
};

//相机类
class Camera:virtual public Product{
public:
    Camera(double p=500):Product(p)
    {
        cout<<"Camera()"<<endl;
    }

    ~Camera()
    {
        cout<<"~Camera()"<<endl;
    }

    void capture()
    {
        cout<<"拍照"<<endl;
    }
};

//多重继承
class SmartPhone:public Phone,public Mp3,public Camera{
public:
    SmartPhone(double a=0,double b=0,double c=0):Product(a+b+c+3000)
    {

    }

};

int main()
{
    SmartPhone iphone13(1200,500,800);
    cout<<iphone13.get_price()<<endl;
    iphone13.play("蔡徐坤");




    iphone13.capture();

    /*
        Phone()
        Mp3()
        Camera()
        5500
        播放蔡徐坤
        拍照
        ~Camera()
        ~Mp3()
        ~Phone()

    */



    return 0;
}
