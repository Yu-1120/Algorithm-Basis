/*08-typeinfo???????*/
#include <iostream>
#include <fstream>

using namespace std;

class Animal{
public:
    Animal(){}

    virtual void show()
    {
        cout<<"Animal show"<<endl;
    }
};

class Dog:public Animal{
public:
    Dog(){}

    virtual void show()
    {
        cout<<"Dog show"<<endl;
    }
};


class Cat:public Animal{
public:
    Cat(){}

    virtual void show()
    {
        cout<<"Cat show"<<endl;
    }
};

int main()
{
    int num;
    void *p = NULL;
    double d_num;

    cout<<typeid(int).name()<<endl;
    cout<<typeid(p).name()<<endl;
    cout<<typeid(d_num).name()<<endl;
    cout<<(typeid(num)==typeid(int))<<endl;

    Animal *pa = NULL;
    cout<<typeid(Animal).name()<<endl;
    cout<<typeid(pa).name()<<endl;

    Dog *pd = NULL;
    cout<<typeid(Dog).name()<<endl;
    cout<<typeid(pd).name()<<endl;

    Animal *pb = new Dog;
    cout<<typeid(pb).name()<<endl;
    cout<<typeid(*pb).name()<<endl;

    Cat ct;
    Animal &an = ct;
    cout<<typeid(an).name()<<endl;

    cout<<(typeid(an)==typeid(Cat))<<endl;
    cout<<(typeid(*pb)!=typeid(Dog))<<endl;
    
    return 0;
}
