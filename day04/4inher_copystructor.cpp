/*04-�̳��еĿ����������������*/
#include <iostream>
#include <cstring>

using namespace std;
/*
    ��δ���չʾ��C++�м̳��еĿ������캯�����������ء�

    ���ȶ�����һ������A������һ��˽�г�Ա����pdata���ַ�ָ�����ͣ����������г�Ա������Ĭ�Ϲ��캯�����������캯��������������

    ���Ŷ�����һ��������B���̳��Ի���A������һ��˽�г�Ա����abc���ַ�ָ�����ͣ����������г�Ա������

    Ĭ�Ϲ��캯�����������캯����������������main�����У�����������B��Ķ���b1��b2��ͨ���������캯����ʼ��b2��

    ��󣬷���������B�ĳ�Ա����show()�͸���A�����س�Ա����show()��

*/
class A{
public:
    A()
    {
        cout<<"A()"<<endl;
        this->pdata = new char[10];
        memset(this->pdata, 0, 10);
    }

    //��������
    A(const A &a)
    {
        cout<<"A(const A &a)"<<endl;
        this->pdata = new char[10];
        memcpy(this->pdata,a.pdata,10);
    }

    ~A()
    {
        cout<<"~A()"<<endl;
        delete[] this->pdata;
    }

    void show()
    {
        cout<<"show A"<<endl;
    }

private:
    char *pdata;
};

class B:public A{
public:
    B()
    {
        cout<<"B()"<<endl;
        this->abc = new char[10];
        memset(this->abc, 0, 10);
    }

    //���࿽������ --- ͨ����ʼ�������б���ø���Ŀ�������
    B(const B &b):A(b)
    {
        cout<<"B(const B &b)"<<endl;
        this->abc = new char[10];
        memcpy(this->abc,b.abc,10);
    }

    ~B()
    {
        cout<<"~B()"<<endl;
        delete[] this->abc;
    }

    void show()
    {
        cout<<"show B"<<endl;
        //this->A::show();
    }

private:
    char *abc;
};

int main()
{
    B b1;
    B b2 = b1;

    //����ͬ����Ա�����أ�Ĭ�Ϸ��������ͬ����Ա
//    b2.show();
//    A()
//    B()
//    A(const A &a)
//    B(const B &b)
//    show B  ������
//    ~B()
//    ~A()
//    ~B()
//    ~A()


    //���ʸ�������س�Ա
//    b2.A::show();
//    A()
//    B()
//    A(const A &a)
//    B(const B &b)
//    show A  !!!!
//    ~B()
//    ~A()
//    ~B()
//    ~A()




    /*
        A()
        B()
        A(const A &a)
        B(const B &b)
        show B
        show A
        ~B()
        ~A()
        ~B()
        ~A()

    */
    return 0;
}
