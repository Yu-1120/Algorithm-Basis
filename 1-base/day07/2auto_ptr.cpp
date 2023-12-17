/*02-指针对象*/
#include <iostream>
#include <cstring>

using namespace std;

class A{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}

    void show()
    {
        cout<<"show A"<<endl;
    }
};

//实现一个指针对象，管理A类型的指针
class myauto_ptr{
public:
    myauto_ptr(A *p=NULL):pdata(p)
    {
        cout<<"myauto_ptr()"<<endl;
    }

    ~myauto_ptr()
    {
        cout<<"~myauto_ptr()"<<endl;
        if(this->pdata)
            delete this->pdata;
    }

    //重载->运算符
    A *operator->()
    {
        return this->pdata;
    }

    //重载*运算符
    A& operator*()
    {
        return *this->pdata;
    }

private:
    A *pdata;//要管理的指针
};

int main()
{
    A *pa = new A;

    //使用指针对象管理pa ----- 无需再释放pa
    myauto_ptr ap(pa);

    //通过指针对象访问管理的指针指向的成员
    ap->show();
    //ap.operator->()->show();

    //解引用指针对象得到管理对象
    (*ap).show();
    //ap.operator*().show();

    return 0;
}
