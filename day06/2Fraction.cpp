/*02-双目运算符的重载*/
#include <iostream>

using namespace std;

//分数
class Fraction{
public:
    Fraction(int x=0,int y=1):x(x),y(y){}
    //打印
    void print()
    {
        cout<<this->x<<"/"<<this->y<<endl;
    }


    //成员函数重载+运算符
    Fraction operator+(const Fraction &fb)
    {
        return Fraction(this->x*fb.y+fb.x*this->y/*分子*/,this->y*fb.y/*分母*/);
    }

    Fraction operator-(const Fraction &fb)
    {
        return Fraction(this->x*fb.y-fb.x*this->y/*分子*/,this->y*fb.y/*分母*/);
    }

    //== > +=
    bool operator==(const Fraction &fb)
    {
        return this->x*fb.y == this->y*fb.x;
    }

    bool operator>(const Fraction &fb)
    {
        return this->x*fb.y > this->y*fb.x;
    }

    Fraction& operator+=(const Fraction &fb)
    {
        this->x = this->x*fb.y+fb.x*this->y;
        this->y = this->y*fb.y;

        return *this;
    }

    //友元函数
    friend Fraction operator+(const Fraction &fa, const Fraction &fb);
    friend Fraction operator*(const Fraction &fa, const Fraction &fb);
    friend Fraction operator/(const Fraction &fa, const Fraction &fb);
    friend istream& operator>>(istream &is, Fraction &fb);
    friend ostream& operator<<(ostream &os, const Fraction &fb);

private:
    int x;//分子
    int y;//分母
};

Fraction operator*(const Fraction &fa, const Fraction &fb)
{
    return Fraction(fa.x*fb.x/*分子*/,fa.y*fb.y/*分母*/);
}

Fraction operator/(const Fraction &fa, const Fraction &fb)
{
    return Fraction(fa.x*fb.y/*分子*/,fa.y*fb.x/*分母*/);
}

istream& operator>>(istream &is, Fraction &fb)
{
    return is>>fb.x>>fb.y;
}

ostream& operator<<(ostream &os, const Fraction &fb)
{
    return os<<fb.x<<"/"<<fb.y;
}

int main()
{
    Fraction fa;
    Fraction fb;
    cout<<"请输入第一个分数:";
    cin>>fa;
    cout<<"请输入第二个分数:";
    cin>>fb;

    cout<<(fa==fb)<<endl;
    cout<<(fa>fb)<<endl;
    fa += fb;
    cout<<fa<<endl;


    return 0;
}

