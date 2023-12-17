/*04-字符串类的析构函数*/
#include <iostream>
#include <cstring>

using namespace std;

class Date{
public:
    Date(int year=2022,int month=3,int day=14,const char *s="hello"):year(year),month(month),day(day)
    {
        this->str = new char[strlen(s)];
        strcpy(this->str,s);
        cout<<"Date()"<<endl;
    }


    //拷贝构造
    Date(const Date &dt)
    {
        cout<<"Date(const Date &dt)"<<endl;
        //使用参数对象的数据去初始化新建对象的数据
        //非指针类型的成员直接拷贝赋值
        this->year = dt.year;
        this->month = dt.month;
        this->day = dt.day;

        //指针类型的成员要重新分配空间，拷贝指向的数据
        this->str = new char[strlen(dt.str)+1];
        strcpy(this->str,dt.str);
    }


    ~Date()
    {
        cout<<"~Date()"<<endl;
        delete[] this->str;
    }

    void show()
    {
        cout<<this->str<<":"<<this->year<<"-"<<this->month<<"-"<<this->day<<endl;

    }

    //修改str
    void set_str(const char *s)
    {
        strcpy(this->str,s);
    }

private:
    int year;
    int month;
    int day;
    char *str;
};

Date show(Date dt)//拷贝构造
{
    cout<<"show Date"<<endl;
    return dt;//拷贝一份dt返回
}

int main()
{
    Date dt1(2019,12,30,"welcome to GEC");//Date()
    dt1.show();   //welcome to GEC:2019-12-30

    //show(dt1);//Date dt = dt1;
    Date dt2 = dt1;//拷贝构造  Date(const Date &dt)
    //Date dt2;
    //dt2 = dt1;
    dt2.show();  //welcome to GEC:2019-12-30

    dt1.set_str("byebye");
    dt1.show();   //byebye:2019-12-30
    dt2.show();  //welcome to GEC:2019-12-30

    /*
        有两个对象就会析构出两个对象出来

    */


    return 0;
}
