#include <iostream>

using namespace std;

template <typename T>
Beta<T>::Beta(int i,T t):t1(i),t2(t)
{

}

template <typename T>
void Beta<T>::show()const
{
    t1.show();
    t2.show();
}

//函数模板成员
template <typename T>
template <typename V>
V Beta<T>::bobo(V v,T t)
{
    return t1.get_value()+t2.get_value()+v/t;
}

//类模板成员
template <typename T>
template <typename K>
Beta<T>::Test<K>::Test(K k):value(k)
{

}

template <typename T>
template <typename K>
void Beta<T>::Test<K>::show()const
{
    cout<<this->value<<endl;
}

template <typename T>
template <typename K>
K Beta<T>::Test<K>::get_value()const
{
    return this->value;
}
