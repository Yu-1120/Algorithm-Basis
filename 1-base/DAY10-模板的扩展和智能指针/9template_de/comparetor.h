#ifndef COMPARETOR_H
#define COMPARETOR_H

//类模板的声明
template <typename T>
class Comparetor{
public:
    Comparetor(T mx,T my);

    T max()const;
    T min()const;

private:
    T x;
    T y;
};

//模板划分
#include "comparetor.cpp"

#endif // COMPARETOR_H
