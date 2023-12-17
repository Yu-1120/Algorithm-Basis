/*05-快速排序*/
#include <iostream>

using namespace std;

template <typename T>
void myqsort(T *arr, int n)
{
    int L = 0;
    int R = n - 1;

    //退出条件
    if (n <= 1)
        return;

    T tmp = arr[L];
    while (L < R)
    {
        //以左边作为基准，比较右边
        while (L < R && arr[R] >= tmp)
            R--;
        arr[L] = arr[R];
        //比较左边
        while (L < R && arr[L] <= tmp)
            L++;
        arr[R] = arr[L];
    }

    //将基准放回重合位置
    arr[L] = tmp;

    //递归前面的分组和后面的分组
    myqsort(arr, L);
    myqsort(arr + L + 1, n - L - 1);
}

//打印
template <typename T>
void print(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//计算长度的
template <typename T>
int count(T &n)
{
    int s1 = sizeof(n);
    int s2 = sizeof(n[0]);
    return s1 / s2;
}
int main()
{
    int a[] = {5, 9, 6, 8, 4, 3, 7, 1, 15, 2};

    myqsort(a, count(a));
    print(a, 10);

    return 0;
}
