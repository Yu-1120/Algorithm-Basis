/*02-继承*/
#include <iostream>
#include <cstring>

using namespace std;

class Animal{
public:
    Animal(string name="小飞飞", int age=5):name(name),age(age)
    {

    }

    void show()
    {
        cout<<this->name<<":"<<this->age<<endl;
    }

protected:
    string name;//可以在子类和类内访问
private:
    int age;
};

//Dog继承Animal
class Dog:public Animal{
public:
    Dog(string name="妞妞",int age=5,double weight=23.4):
        Animal(name,age),weight(weight)
    {

    }

    void dogfunc()
    {
        this->show();
        cout<<this->weight<<" 看门!"<<endl;
    }

private:
    double weight;
};

//Cat公有继承Animal ----- 得到Animal的所有内容
class Cat:public Animal{
public:
    Cat(string name="汤圆",int age=3,string color="yellow"):Animal(name,age),color(color)
    {

    }

    //新增的功能
    void catfunc()
    {
        this->show();
        cout<<this->color<<"抓老鼠!"<<endl;
    }

private:
    //新增属性
    string color;
};

//LiHuaCat继承Cat
class LiHuaCat:public Cat{
public:
    LiHuaCat(string name="西红柿",int age=3,string color="豹纹",string country="中国"):
        Cat(name,age,color),country(country)
    {

    }

    void LiHuafunc()
    {
        this->catfunc();
        cout<<"产地:"<<this->country<<" 吃鱼"<<endl;
    }

private:
    string country;
};

int main()
{
    //Cat ct("端午",7,"白色");
    //ct.catfunc();
    //继承父类的成员函数
    //ct.show();

    Dog dg("阿黄",2,32.1);
    dg.dogfunc();
    cout<<endl;

    LiHuaCat lhc("桂兰",7,"黑色","美国");
    lhc.LiHuafunc();
    /*
        阿黄:2
        32.1 看门!

        桂兰:7
        黑色抓老鼠!
        产地:美国 吃鱼

    */

    /*
    C++中的继承机制。首先定义了一个基类Animal，包含一个受保护的成员变量name（动物的名字）和一个受保护的成员变量age（动物的年龄）。然后定义了三个派生类：Dog、Cat和LiHuaCat，它们分别继承了Animal类。

    Dog类有一个额外的成员变量weight（体重），并重写了基类的show()函数，输出动物的名字和年龄，以及体重。dogfunc()函数调用了基类的show()函数和自身的weight属性。

    Cat类也有一个额外的成员变量color（颜色），并重写了基类的show()函数，输出动物的名字和年龄，以及颜色。catfunc()函数调用了基类的show()函数和自身的color属性。

    LiHuaCat类继承了Cat类，并添加了一个额外的成员变量country（国家），重写了基类的show()函数，输出动物的名字、年龄和颜色。LiHuafunc()函数调用了基类的show()函数、自身的catfunc()函数和country属性。

    在main()函数中，创建了一个Dog对象dg，一个Cat对象ct和一个LiHuaCat对象lhc。分别调用了它们的成员函数，输出了相应的信息。

    */
    return 0;
}
