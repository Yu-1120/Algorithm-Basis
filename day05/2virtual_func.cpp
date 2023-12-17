/*02-虚函数和虚函数表*/
#include <iostream>

using namespace std;

class Animal{
public:
    //成员函数
    virtual void show()//虚函数
    {
        cout<<"Animal show"<<endl;
    }

    void run()
    {
        cout<<"Animal run"<<endl;
    }

    virtual void eat()
    {
        cout<<"Animal eat"<<endl;
    }

};

class Dog:public Animal{
public:
    //重写虚函数
    virtual void show()//虚函数
    {
        cout<<"Dog show"<<endl;
    }

    virtual void eat()
    {
        cout<<"Dog eat bones"<<endl;
    }

};

class Cat:public Animal{
public:
    //重写虚函数
    virtual void show()//虚函数
    {
        cout<<"Cat show"<<endl;
    }

    virtual void eat()
    {
        cout<<"Cat eat fish"<<endl;
    }

};

typedef void (*pfunc_t)();//为函数指针类型起别名

int main()
{
    /*
    //没有成员变量的类类型对象所占空间大小是1
    //cout<<sizeof(Animal)<<endl;
    Animal an;
    //long addr = *(long *)&an;//取出对象前8个字节的数据
    //pfunc_t *pt = (pfunc_t *)addr;//转化为虚函数表首地址类型

    pfunc_t *pt = *(pfunc_t **)&an;//取出对象前8个字节的数据 --- 虚函数表的地址
    //调用虚函数
    pt[0]();//an.show();
    pt[1]();//an.eat();

    Dog dg;

    pt = *(pfunc_t **)&dg;//取出对象前8个字节的数据 --- 虚函数表的地址
    //调用虚函数
    pt[0]();//an===>show();
    pt[1]();//dg===>eat();
    */
    //Animal *pa = new Animal;
    //Dog *pd = new Dog;
    //有虚函数，父类类型记录子类对象
    Animal *pa = new Dog;
    pa->show();
    pa->run();
    pa->eat();

    delete pa;
    return 0;
}
