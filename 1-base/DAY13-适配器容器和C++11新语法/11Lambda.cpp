/*11 - Lambda表达式*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//判断整除的函数对象
class Get_mode {
public:
    Get_mode(int d = 1) : div(d) {}

    //重载()运算符 --- 判断参数是否能被div整除
    bool operator()(int x) {
        return x % div == 0;
    }

private:
    int div;
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vi(arr, arr + 9);
    //---------------------
    cout << Get_mode(3)(arr[7]) << endl;

    //泛型算法函数count_if用于计算符合标准(函数)的元素个数
    //---------------------
    //count_if的参数是 范围 + 测试是否符合标准函数/函数对象
    cout << count_if(vi.begin(), vi.end(), Get_mode(3)) << endl;//计算vi中能被3整除的元素个数
    //使用Lambda实现跟上面的语法的语一样
    cout << count_if(vi.begin(), vi.end(), [](int x)/*->bool*/{
        return x % 4 == 0;//被4整除，函数体
    }) << endl;
    //--------------------- 但是第一种方法比较，简洁，
    // 这个就是lamba语法-》现在的语言也越来越倾向于简介

    //使用for_each计算能被3整除的元素个数  这个也是算出大小
    int count = 0;
    for_each(vi.begin(), vi.end(), [&count](int x) {
        count += x % 3 == 0;
    });

    cout << "能被3整除的个数为:" << count << endl;

    return 0;
}
