/*03-C++的字符串流*/
#include <iostream>
#include <sstream>

using namespace std;

class Date{
public:
    Date(int y=2022,int m=3,int d=21):year(y),month(m),day(d){}

    friend ostream& operator<<(ostream &os,const Date &dt)
    {
        return os<<dt.year<<"-"<<dt.month<<"-"<<dt.day;
    }

private:
    int year;
    int month;
    int day;
};


int main()
{
    string name("张飞");
    int age = 21;

    //字符串输出流
    ostringstream oss;
    //将内容写入字符串流
    //cout<<name<<":"<<age<<endl;
    oss<<name<<":"<<age;
    cout<<oss.str()<<endl;

    //字符串输入流
    istringstream iss("刘备 30");
    //cin>>name>>age;
    iss>>name>>age;
    cout<<name<<":"<<age<<endl;

    ostringstream oss1;
    Date dt;
    //cout<<dt<<endl;
    oss1<<dt;//oss1<<dt.year<<"-"<<dt.month<<"-"<<dt.day;
    cout<<oss1.str()<<endl;

    return 0;
}