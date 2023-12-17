/*01-复数类运算的重载*/
#include <iostream>

using namespace std;

class Complex{
public:
    explicit Complex(double r=0.0,double i=0.0):real(r),imag(i){}

    //重载实现+ - *
    Complex operator+(const Complex &c)
    {
        return Complex(this->real+c.real,this->imag+c.imag);
    }

    Complex operator-(const Complex &c)
    {
        return Complex(this->real-c.real,this->imag-c.imag);
    }

    Complex operator*(const Complex &c)
    {
        return Complex(this->real*c.real-this->imag*c.imag,
                       this->imag*c.real+this->real*c.imag);
    }

    //重载== !=
    bool operator==(const Complex &c)
    {
        return this->real==c.real && this->imag==c.imag;
    }

    bool operator!=(const Complex &c)
    {
        return !(this->real==c.real && this->imag==c.imag);
    }

    //重载+= fa+fb  fa += fb
    Complex& operator+=(const Complex &c)
    {
        this->real += c.real;
        this->imag += c.imag;

        return *this;
    }

    //实现Complex+double
    Complex operator+(const double &d)
    {
        return Complex(this->real+d,this->imag);
    }

    void print()
    {
        cout<<this->real<<(this->imag>=0 ? "+" : "")
            <<this->imag<<"i"<<endl;
    }

    friend Complex operator+(const double &d,const Complex &c);
    friend istream& operator>>(istream &is,Complex &c);
    friend ostream& operator<<(ostream &os,const Complex &c);

private:
    double real;//实部
    double imag;//虚部
};

//重载double+Complex
Complex operator+(const double &d,const Complex &c)
{
    return Complex(d+c.real,c.imag);
}

//重载cin>>Complex运算符
istream& operator>>(istream &is,Complex &c)
{
    //分别输入实部和虚部
    return is>>c.real>>c.imag;
}

//重载cout<<Complex运算符
ostream& operator<<(ostream &os,const Complex &c)
{
    //分别输出实部和虚部
    return os<<c.real<<(c.imag>=0 ? "+" : "")
            <<c.imag<<"i";
}

int main()
{
    Complex c1(2,3);
    Complex c2(5,-4);

    Complex c3 = c1+c2;
    c3.print();

    c3 = c1-c2;
    c3.print();

    c3 = c1*c2;
    c3.print();

    cout<<(c1==c2)<<endl;

    //c1 += c2;
    //c1.print();
    //c3 = c1+2.1;
    c3 = 2.3+c1;
    c3.print();

    //Complex c = 2.1;//隐式转换 ===> Complex(2.1)
    //Complex c = Complex(2.1);
    //c.print();
    cout<<"请输入一个复数:";
    cin>>c1;//operator>>(cin,c1);===>cin>>c1.real>>c1.imag;
    //c1.print();
    cout<<c1<<endl;//operator<<(cout,c1);===>cout<<c.real<<(c.imag>=0 ? "+" : "")<<c.imag<<"i";


    return 0;
}
