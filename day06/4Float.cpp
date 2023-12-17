/*04-单目运算符的重载练习*/
#include <iostream>

using namespace std;

class Float{
public:
    Float(double d=0.0):data(d){}

    //重载-号(负号)
    Float operator-()
    {
        return Float(-this->data);
    }

    //重载前++
    Float& operator++()
    {
        ++this->data;
        return *this;
    }

    //重载后++
    Float operator++(int)
    {
        return Float(this->data++);
    }

    //重载==
    bool operator==(const Float &d)
    {
        //浮点数不应该直接判等
        //return this->data==d.data;
        return this->data-d.data>-1e-15 && this->data-d.data<1e-15;
    }

    //+=
    Float& operator+=(const Float &d)
    {
        this->data += d.data;
        return *this;
    }

    friend ostream& operator<<(ostream &os,const Float &i);
    friend Float operator--(Float &i,int);
    friend Float& operator--(Float &i);

private:
    double data;
};

ostream& operator<<(ostream &os,const Float &i)
{
    return os<<i.data;
}

//重载后--
Float operator--(Float &i,int)
{
    return Float(i.data--);
}

//重载前--
Float& operator--(Float &i)
{
    --i.data;
    return i;
}

int main()
{
    Float f1(1.1);
    Float f2(1.1);

    cout<<(f1==f2)<<endl;

    //f2 = ++f1;
    //f2 = -f1;
    f2 += f1;

    cout<<f1<<endl;
    cout<<f2<<endl;

    return 0;
}
