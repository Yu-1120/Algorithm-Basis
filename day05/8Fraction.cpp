/*08-双目运算符的重载*/
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
        cout<<"NO 1"<<endl;
        //1/2+1/3 = 3/6+2/6
        return Fraction(this->x*fb.y+fb.x*this->y/*分子*/,this->y*fb.y/*分母*/);
    }

    Fraction operator-(const Fraction &fb)
    {
        return Fraction(this->x*fb.y-fb.x*this->y/*分子*/,this->y*fb.y/*分母*/);
    }

    //友元函数
    friend Fraction operator+(const Fraction &fa, const Fraction &fb);
    friend Fraction operator*(const Fraction &fa, const Fraction &fb);
    friend Fraction operator/(const Fraction &fa, const Fraction &fb);

private:
    int x;//分子
    int y;//分母
};

//使用全局函数重载+
Fraction operator+(const Fraction &fa, const Fraction &fb)
{
    cout<<"NO 2"<<endl;
    //1/2+1/3 = 3/6+2/6 = 5/6
    return Fraction(fa.x*fb.y+fb.x*fa.y/*分子*/,fa.y*fb.y/*分母*/);
}

Fraction operator*(const Fraction &fa, const Fraction &fb)
{
    return Fraction(fa.x*fb.x/*分子*/,fa.y*fb.y/*分母*/);
}

Fraction operator/(const Fraction &fa, const Fraction &fb)
{
    return Fraction(fa.x*fb.y/*分子*/,fa.y*fb.x/*分母*/);
}

int main()
{
    Fraction fa(1,2);
    Fraction fb(1,3);

    Fraction fc = fa+fb;//fa.operator+(fb);   operator+(fa,fb);
    fc.print();

    fc = fa-fb;
    fc.print();


    fc = fa*fb;
    fc.print();

    fc = fa/fb;
    fc.print();

    return 0;
}

