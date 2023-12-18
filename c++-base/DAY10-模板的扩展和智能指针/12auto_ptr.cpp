/*12 - C++预定义智能指针*/
#include <iostream>
#include <memory>

using namespace std;

class Object{
public:
    Object(string s=""):str(s){}
    ~Object(){cout<<"~Object()"<<endl;}

    void show()const
    {
        cout<<this->str<<endl;
    }

    void set_str(const string &s)
    {
        this->str = s;
    }

private:
    string str;
};

int main()
{
    //管理 string *的指针
    auto_ptr<string> pa(new string("hello"));
    unique_ptr<string> us(new string("welcome"));
    shared_ptr<string> ss(new string("byebye"));

    //cout<<pa->c_str()<<endl;
    //cout<<us->c_str()<<endl;
    //cout<<ss->c_str()<<endl;

    auto_ptr<string> pa1 = pa;//pa将被置空
    //cout<<pa->c_str()<<endl;传递导致失效
    cout<<pa1->c_str()<<endl;
    //unique_ptr<string> us1 = us;//禁止拷贝和赋值
    shared_ptr<string> ss1 = ss;//共享
    ss1->append("冬天");
    cout<<ss->c_str()<<endl;
    cout<<ss1->c_str()<<endl;

    auto_ptr<Object> ao(new Object("hello"));
    unique_ptr<Object> uo(new Object("welcome"));
    shared_ptr<Object> so(new Object("byebye"));

    auto_ptr<Object> ao1 = ao;//ao1被置空
    //unique_ptr<Object> uo1;
    //uo1 = uo;//禁止拷贝和赋值
    shared_ptr<Object> so1;
    so1 = so;//共享
    so1->set_str("你好");

    so->show();
    so1->show();


    return 0;
}
