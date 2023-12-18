/*01-多重继承，虚继承作业*/
#include <iostream>
#include <cstring>

using namespace std;

//最高层父类
class Person{
public:
    Person(const char *name=NULL)
    {
        if(name){
            this->name = new char[strlen(name)+1];
            strcpy(this->name,name);
        }
        else{//默认名 ---- 张三
            this->name = new char[strlen("张三")+1];
            strcpy(this->name,"张三");
        }
    }

    Person(const Person &p)
    {
        this->name = new char[strlen(p.name)+1];
        strcpy(this->name,p.name);
    }

    ~Person()
    {
        delete[] this->name;
    }

    //公有接口
    const char *get_name()
    {
        return this->name;
    }

private:
    char *name;
};

class Worker:virtual public Person{
public:
    Worker(const char *name=NULL,double salary=4000.0):
        Person(name),salary(salary)
    {

    }

    //公有接口
    double get_salary()
    {
        return this->salary;
    }

private:
    double salary;
};

class Farmer:virtual public Person{
public:
    Farmer(const char *name=NULL,double area=300.0):
        Person(name),area(area)
    {

    }

    //公有接口
    double get_area()
    {
        return this->area;
    }

private:
    double area;
};

//农民工类
class FarmWorker:virtual public Worker,virtual public Farmer{
public:
    FarmWorker(const char *name=NULL,double salary=4000.0,double area=300.0):
        Person(name),Worker(name,salary),Farmer(name,area)
    {

    }

    /*
    FarmWorker(const FarmWorker &f):Person(f),Worker(f),Farmer(f)
    {
        cout<<"xxx"<<endl;
    }
    */

    void show()
    {
        cout<<this->get_name()<<":"<<this->get_salary()<<":"<<this->get_area()<<endl;
    }
};

int main()
{
    FarmWorker fw("王大强",10000.0,1500.0);
    fw.show();

    FarmWorker fw1 = fw;

    return 0;
}
