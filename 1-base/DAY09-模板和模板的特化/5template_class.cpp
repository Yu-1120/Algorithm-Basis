/*05 - 类模板的使用*/
#include <iostream>

using namespace std;

//类模板的声明
template <typename T>
class Data{
public:
    Data(T a):dt(a){}

    T get_dt()
    {
        return this->dt;
    }

    void set_dt(T a)
    {
        this->dt = a;
    }

    void show()
    {
        cout<<this->dt<<endl;
    }

private:
    T dt;
};

int main()
{
    //类模板的使用
    Data<int> di(10);
    di.show();

    Data<double> dd(10.5);
    dd.show();

    Data<string> ds("hello");
    ds.show();

    return 0;
}
