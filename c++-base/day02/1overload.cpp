/*01-��������*/
#include <iostream>

using namespace std;

//���º����������ع�ϵ
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
{    //�ܽ᣺���ź�����������������
    print(); //����void print()
    print(1); //����void print(int a)
    print(3.15); //����void print(double a)
    print(2,4.6); //����void print(int a,double b)
    print(1.5,7);//����void print(double a,int b)
    print(2.1,4.6); //����void print(double a,double b)
    return 0;
}
