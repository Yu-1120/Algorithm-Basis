/*08-构造Animal类*/
#include <iostream>
#include <cstring>

using namespace std;

class A{
public:
    A(){cout<<"A()"<<endl;}
};

class Animal{
public:
    //构造函数
    Animal()
    {
        cout<<"Animal()"<<endl;
        strcpy(name,"月饼");
        age = 3;
        weight = 5.6f;
    }


    //构造函数的重载
    Animal(const char *m_name,int m_age=3,float m_weight=10.1f)
    {
        cout<<"Animal(const char *,int,float)"<<endl;
        strcpy(name,m_name);
        age = m_age;
        weight = m_weight;
    }

    void show()
    {
        cout<<name<<":"<<age<<":"<<weight<<endl;
    }

    //设置name
    void set_name(const char *s)
    {
        strcpy(name,s);
    }

    //设置age
    void set_age(int a)
    {
        age = a;
    }

    //设置体重
    void set_weight(float w)
    {
        weight = w;
    }

protected:
    float weight;
private:
    int age;
    char name[20];
    A a;
};

int main()
{
    //Animal an;//调用无参构造函数
    //an.set_name("小飞飞");
    //an.set_age(4);
    //an.set_weight(14.4f);

    Animal an("小飞飞"/*,5,13.2f*/);
    //Animal *pa = new Animal;
    Animal *pa = new Animal("汤圆",7,24.5f);

    an.show();

    pa->show();
//    A()
//    Animal(const char *,int,float)
//    A()
//    Animal(const char *,int,float)
//    小飞飞:3:10.1
//    汤圆:7:24.5
    delete pa;
    return 0;
}
