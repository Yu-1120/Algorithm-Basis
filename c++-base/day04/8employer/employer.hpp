#ifndef EMPLOYER_HPP
#define EMPLOYER_HPP

#include <iostream>
using namespace std;

class Object{
public:
    Object(const char *s=NULL);
    //拷贝构造
    Object(const Object &o);
    ~Object();

    //获取
    const char *get_p();

private:
    char *p;//说明信息
};

//虚继承
class Person:virtual public Object
{
public:
    Person(const char *s=NULL,string name="xxx");
    //获取
    string get_pname();

private:
    string p_name;//人名
};

class Comp:virtual public Object
{
public:
    Comp(const char *s=NULL,string name="xxx");
    //获取
    string get_cname();

private:
    string c_name;//公司名
};

//员工类
class Employer:virtual public Person,virtual public Comp{
public:
    Employer(const char *s=NULL,string pname="xxx",string cname="xxx",double salary=1000.0);
    void show();

private:
    double salary;
};

#endif // EMPLOYER_HPP
