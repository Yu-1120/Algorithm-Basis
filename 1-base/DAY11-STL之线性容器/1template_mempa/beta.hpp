#ifndef BETA_HPP
#define BETA_HPP

template <typename T>
class Beta{
public:
    Beta(int i,T t);
    void show()const;
    //函数模板成员
    template <typename V>
    V bobo(V v,T t);

private:
    //类模板成员
    template <typename K>
    class Test{
    public:
        Test(K k);
        void show()const;
        K get_value()const;

    private:
        K value;
    };

    //使用类模板成员
    Test<int> t1;
    Test<T> t2;
};

#include "beta.cpp"

#endif // BETA_HPP
