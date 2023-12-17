/*01-函数重载*/
#include <iostream>

using namespace std;

//以下函数构成重载关系
void print()
{
    cout<<"print()"<<endl;
}

void print(int a)
{
    cout<<"print(int)"<<endl;
}


void print(double a)
{
    cout<<"print(double)"<<endl;
}

void print(int a,double b)
{
    cout<<"print(int,double)"<<endl;
}

void print(double a,int b)
{
    cout<<"print(double,int)"<<endl;
}
void print(double a,double b)
{
    cout<<"print(double,double)"<<endl;
}
int main()
{    //总结：看着函数参数来调函数的
    print(); //调用void print()
    print(1); //调用void print(int a)
    print(3.15); //调用void print(double a)
    print(2,4.6); //调用void print(int a,double b)
    print(1.5,7);//调用void print(double a,int b)
    print(2.1,4.6); //调用void print(double a,double b)
    return 0;
}
