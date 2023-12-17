/*03-多态*/
#include <iostream>

using namespace std;

class Animal{
public:
    //虚析构
    virtual ~Animal()
    {
        cout<<"~Animal"<<endl;
    }

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
    virtual ~Dog()
    {
        cout<<"~Dog"<<endl;
    }

    //重写虚函数
    virtual void show()//虚函数
    {
        cout<<"Dog show"<<endl;
    }

    void run()//名字隐藏
    {
        cout<<"Dog run"<<endl;
    }

    virtual void eat()
    {
        cout<<"Dog eat bones"<<endl;
    }

};

class Cat:public Animal{
public:
    virtual ~Cat()
    {
        cout<<"~Cat"<<endl;
    }

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

//传入一个Animal对象 ----- 多态
void animal_gogo(Animal *p)
{
    p->show();
    p->eat();
}

int main()
{
    Animal *pa = new Animal;
    //pa->show();
    //pa->run();
    //pa->eat();
    animal_gogo(pa);
    delete pa;

    //有虚函数，父类类型记录子类对象
    pa = new Dog;
    //pa->show();
    //pa->run();
    //pa->eat();
    animal_gogo(pa);
    delete pa;

    pa = new Cat;
    //pa->show();
    //pa->run();
    //pa->eat();
    animal_gogo(pa);
    delete pa;

    //Dog dg;
    //Animal &ra = dg;
    //ra.show();
    //ra.Animal::show();

    return 0;
}
