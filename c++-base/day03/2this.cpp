/*02-this指针*/
#include <iostream>
#include <cstring>

using namespace std;

//类的前置声明
class Animal;

//函数声明
void show_Animal(Animal &an);

class Animal{
public:
    //构造函数
    Animal(string name,int age,double weight)
    {
        cout<<"Animal()"<<endl;
        //使用this指针访问同名成员变量
        this->name = name;
        this->age = age;
        this->weight = weight;
    }

    //成员函数
    void run()
    {
        cout<<this->name<<" run!"<<endl;
    }


    Animal *show()
    {
        //this作为函数参数
        show_Animal(*this);
        /*
            this指针可以在类的成员函数和构造函数中使用，代表的是调用该函数的对象(构造的对象)的地址、

            在成员函数中，this指针指向调用该函数的对象
            在构造函数中，this指针指向正在构造的对象




        */
        cout<<this->name<<":"<<this->age<<":"<<this->weight<<endl;
        //this作为返回值
        return this;
    }

private:
    string name;//C++提供的字符串类 =
    int age;
    double weight;
};

void show_Animal(Animal &an)
{
    cout<<"show_Animal"<<endl;
    an.run();
}

int main()
{
    //Animal an("元宵",4,11.2);
    //an.run();

    Animal *pa = new Animal("端午",5,9.4);
    pa->show()->show()->show()->run();
// pa->show() 返回了是this本身的东西
//    Animal()
//    show_Animal
//    端午 run!
//    端午:5:9.4
//    show_Animal
//    端午 run!
//    端午:5:9.4
//    show_Animal
//    端午 run!
//    端午:5:9.4
//**********************
//    端午 run!


//    pa->show();
//    Animal()
//    show_Animal
//    端午 run!
//    端午:5:9.4




    delete pa;
    return 0;
}
