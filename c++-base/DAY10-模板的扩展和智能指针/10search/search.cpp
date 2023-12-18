#include <iostream>
#include <cstring>

using namespace std;
//---------------------具体实现------------------------------
template<typename T>
int Searcher<T>::operator()(T *arr, int from, int to, T dt) {
    //计算中间元素下标
    int mid = (from + to) / 2;

    //2.递归结束条件
    if (from > to)
        return -1;

    //1.拆分问题
    if (arr[mid] == dt)
        return mid;
    else if (arr[mid] > dt)//前子表查找
        return operator()(arr, from, mid - 1, dt);
    else
        return operator()(arr, mid + 1, to, dt);
}
//---------------------具体实现------------------------------
//成员特化
template<>
int Searcher<const char *>::operator()(const char **arr, int from, int to, const char *dt) {
    //计算中间元素下标
    int mid = (from + to) / 2;

    //2.递归结束条件
    if (from > to)
        return -1;

    //1.拆分问题
    if (strcmp(arr[mid], dt) == 0)
        return mid;
    else if (strcmp(arr[mid], dt) > 0)//前子表查找
        return operator()(arr, from, mid - 1, dt);
    else
        return operator()(arr, mid + 1, to, dt);
}

