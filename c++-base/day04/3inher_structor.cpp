/*03-继承中的构造函数和析构函数*/
#include <iostream>
#include <cstring>

using namespace std;

class A{
public:
    A(){cout<<"A()"<<endl;}
    A(int a,int b){cout<<"A(int,int)"<<endl;}
    ~A(){cout<<"~A()"<<endl;}

private:
    int x;
    int y;
};

class B:public A{
public:
    B(){cout<<"B()"<<endl;}
    B(int a,int b,int c):A(a,b)/*给父类的构造函数传参*/,z(c){cout<<"B(int,int,int)"<<endl;};
    ~B(){cout<<"~B()"<<endl;}

private:
    int z;
};

int main()
{
    //B b;
    B b(1,2,3);
    /*
         //先构造父类，再构造子类，先析构子类，再析构父类
        A(int,int)
        B(int,int,int)
        ~B()
        ~A()
    */
    return 0;
}
