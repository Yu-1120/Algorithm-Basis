/*03-单目运算符的重载*/
#include <iostream>

using namespace std;

class Interger{
public:
    Interger(int d=0):data(d){}

    //重载-号(负号)
    Interger operator-()
    {
        return Interger(-this->data);
    }

    //重载前++
    Interger& operator++()
    {
        ++this->data;
        return *this;
    }

    //重载后--
    Interger operator--(int)
    {
        return Interger(this->data--);
    }

    friend ostream& operator<<(ostream &os,const Interger &i);
    friend Interger operator++(Interger &i,int);
    friend Interger& operator--(Interger &i);

private:
    int data;
};

ostream& operator<<(ostream &os,const Interger &i)
{
    return os<<i.data;
}

//重载后++
Interger operator++(Interger &i,int)
{
    return Interger(i.data++);
}

//重载前--
Interger& operator--(Interger &i)
{
    --i.data;
    return i;
}

int main()
{
    Interger i1(10);
    Interger i2(20);

    //i2 = -i1;
    //cout<<i2<<endl;

    //i2 = ++i1;
    //i2 = i1++;
    //i2 = --i1;
    i2 = i1--;
    cout<<-i1<<endl;
    cout<<i2<<endl;

    return 0;
}
