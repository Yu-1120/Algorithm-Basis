/*06 - 优先队列的使用*/
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

class student{
public:
    student(int id=0,string name="",int age=0):id(id),name(name),age(age){}

    //按名字去重，==判断name
    bool operator==(const student &s)const
    {
        return this->name==s.name;
    }

    //默认按id从小到大排序
    bool operator<(const student &s)const
    {
        return this->id<s.id;
    }


    //自己作为函数对象用作比较器 name排序
    bool operator()(const student &s1,const student &s2)
    {
        return s1.name<s2.name;
    }

    //重载输出
    friend ostream& operator<<(ostream &os,const student &s)
    {
        return os<<s.id<<":"<<s.name<<":"<<s.age;
    }

    friend class Compare_age;

private:
    int id;
    string name;
    int age;
};

//函数对象比较器，比较年龄
class Compare_age{
public:
    bool operator()(const student &s1,const student &s2)
    {
        return s1.age>s2.age;
    }
};

//函数对象比较器
class Compare{
public:
    bool operator()(const int &a,const int &b)
    {
        return a>b;
    }
};

int main()
{
   
  

    //priority_queue<student> ps;//默认比较器
    //priority_queue<student,vector<student>,student> ps;//自己作为函数对象比较器，类型，底层容器，函数类型
    priority_queue<student,vector<student>,Compare_age> ps;//外部函数对象比较器

    ps.push(student(4,"张飞",23));
    ps.push(student(2,"关羽",26));
    ps.push(student(5,"赵云",19));
    ps.push(student(1,"刘备",31));
    ps.push(student(6,"黄忠",50));

    while(!ps.empty()){
        cout<<ps.top()<<endl;;//优者先出
        ps.pop();
    }

    return 0;
}
