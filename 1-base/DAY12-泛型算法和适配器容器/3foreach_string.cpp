/*03-for_each操作string*/
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

//函数
void modify(string &s)
{
    if (s == "hello")
        s = "byebye";
}

int main()
{
    array<string, 5> as = {"hello", "welcome", "UK", "Japan", "Friday"};
    cout << as.begin() << endl;             //打印地址
    for_each(as.begin(), as.end(), modify); //地址到地址执行，某个函数

    for (array<string, 5>::iterator it = as.begin(); it != as.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
