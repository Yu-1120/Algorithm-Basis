/*06-多重继承实现员工类*/
#include <iostream>
#include <cstring>

using namespace std;
/*

C++实现多重继承的一个示例，其中定义了四个类：Object、Person、Comp和Employer。

*/



/*
    Object类：这是基类，包含一个私有成员变量p，用于存储字符串信息。
    它有一个默认构造函数，一个拷贝构造函数，一个析构函数和一个获取p值的成员函数。

*/
class Object{
public:
    Object(const char *s=NULL)
    {
        cout<<"Object()"<<endl;

        if(s){
            this->p = new char[strlen(s)+1];
            strcpy(this->p, s);
        }
        else{
            this->p = new char[10];
            memset(this->p,0,10);
        }
    }

    //拷贝构造
    Object(const Object &o)
    {
        cout<<"Object(const Object &o)"<<endl;
        if(strlen(o.p)){
            this->p = new char[strlen(o.p)+1];
            strcpy(this->p, o.p);
        }
        else{//空串
            this->p = new char[10];
            memset(this->p,0,10);
        }
    }

    ~Object()
    {
        cout<<"~Object()"<<endl;
        delete[] this->p;
    }

    //获取
    const char *get_p()
    {
        return this->p;
    }

private:
    char *p;//说明信息
};
/*

    Person类：虚继承了Object类，增加了一个私有成员变量p_name，用于存储人名。
    它有一个默认构造函数，一个获取p_name值的成员函数。
*/
//虚继承
class Person:virtual public Object
{
public:
    Person(const char *s=NULL,string name="xxx"):Object(s),p_name(name)
    {
        cout<<"Person()"<<endl;
    }

    //获取
    string get_pname()
    {
        return this->p_name;
    }

private:
    string p_name;//人名
};
/*

    Comp类：也虚继承了Object类，增加了一个私有成员变量c_name，用于存储公司名。
    它有一个默认构造函数，一个获取c_name值的成员函数。
*/
class Comp:virtual public Object
{
public:
    Comp(const char *s=NULL,string name="xxx"):Object(s),c_name(name)
    {
        cout<<"Comp()"<<endl;
    }

    //获取
    string get_cname()
    {
        return this->c_name;
    }

private:
    string c_name;//公司名
};
/*

    Employer类：同时虚继承了Person类和Comp类，包含了一个私有成员变量salary，用于存储薪水。
    它有一个默认构造函数，一个显示所有信息的成员函数。

*/
//员工类
class Employer:virtual public Person,virtual public Comp{
public:
    Employer(const char *s=NULL,string pname="xxx",string cname="xxx",double salary=1000.0):
        Object(s),Person(s,pname),Comp(s,cname),salary(salary)
    {
        cout<<"Employer()"<<endl;
    }

    void show()
    {
        cout<<this->get_pname()<<":"<<this->get_cname()<<":"<<
              this->get_p()<<":"<<this->salary<<endl;
    }

private:
    double salary;
};
/*

C++实现多重继承的一个示例，其中定义了四个类：Object、Person、Comp和Employer。

*/
int main()
{
    Employer ep("五虎上将","张飞","蜀国",300000.0);
    ep.show();

    Employer ep1 = ep;
/*

        Object()
        Person()
        Comp()
        Employer()
        张飞:蜀国:五虎上将:300000
        Object(const Object &o)
        ~Object()
        ~Object()


*/
    return 0;
}




