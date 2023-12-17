/*09-字符串类的静态函数*/
#include <iostream>
#include <cstring>

using namespace std;
/*


*/
class A{
public:
    int x;
      int z;
protected:
    int y;
//private:


    //友元函数的声明
    friend void setA(A &a);
    //友元类的声明
    friend class B;
};
/*


*/
class B{
public:
    void show()
    {
        cout<<a.x<<":"<<a.y<<":"<<a.z<<endl;
    }

private:
    A a;
};


void setA(A &a)
{
    a.x = 10;
    a.y = 20;
    a.z = 30;
}
/*
    这段代码展示了一个名为A的类，其中包含了三个私有成员变量x、y和z。

    它还声明了两个友元函数setA()和B类的show()函数。

    在主函数中，首先创建了一个A类的对象a，然后调用了友元函数setA()来设置a的成员变量的值。

    接下来，创建了一个B类的对象b，并调用了它的show()函数来输出a对象的成员变量的值。

    根据代码的逻辑，a对象的x、y和z成员变量的值分别被设置为10、20和30。

    最后，b对象的show()函数输出了a对象的成员变量的值，

*/
int main()
{
    A a;
    setA(a);
    B b;
    b.show();
/*
输出有点奇怪

*/
    return 0;
}
