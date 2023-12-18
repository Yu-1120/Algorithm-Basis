/*09 - 类模板的局部特化*/
#include <iostream>
#include <cstring>

using namespace std;

//通用类模板
template<typename T1, typename T2, typename T3>
class Trib {
public:
    Trib() { cout << "Trib<T1,T2,T3>" << endl; }
};

//局部特化
//1.特化一部分类型参数
template<typename T1, typename T2>
class Trib<T1, T2, int> {
public:
    Trib() { cout << "Trib<T1,T2,int>" << endl; }
};

template<typename T1>
class Trib<T1, double, int> {
public:
    Trib() { cout << "Trib<T1,double,int>" << endl; }
};

//2.特化类型参数的关系
template<typename T1, typename T2>
class Trib<T1, T2, T2> {
public:
    Trib() { cout << "Trib<T1,T2,T2>" << endl; }
};

template<typename T1>
class Trib<T1, T1, T1> {
public:
    Trib() { cout << "Trib<T1,T1,T1>" << endl; }
};

//3.特化数组和指针类型
template<typename T1, typename T2, typename T3>
class Trib<T1 *, T2 *, T3 *> {
public:
    Trib() { cout << "Trib<T1*,T2*,T3*>" << endl; }
};

template<typename T1, typename T2, typename T3>
class Trib<T1[], T2[], T3[]> {
public:
    Trib() { cout << "Trib<T1[],T2[],T3[]>" << endl; }
};

int main() {
    //Trib<char,double,int> t1;
    //Trib<char,long,int> t2;
    Trib<char, long, double> t3;

    //Trib<char,double,double> t4;
    //Trib<double,double,double> t5;
    //理解为方法重载，只是传入的类型程而已
    Trib<char *, long *, double *> t6;
    Trib<char[], long[], double[]> t7;

    return 0;
}
