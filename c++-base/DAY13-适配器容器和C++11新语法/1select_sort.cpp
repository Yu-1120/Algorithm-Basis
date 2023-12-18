/*01-简单选择排序*/
#include <iostream>

using namespace std;
//二叉树排序
//函数模板实现简单选择排序
template <typename T>
void select_sort(T *arr, int n)
{
    int max = 0; //最大值下标

    for (int i = 0; i < n - 1; i++)
    {
        max = i;
        //从i开始往后的序列扫描,找出最大值的下标
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[max])
                max = j;
        }

        //交换max和i
        if (max != i)
        {
            T temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
}

template <typename T>
void print(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[10] = {6, 8, 2, 1, 9, 7, 4, 5, 3, 16};

    select_sort(a, 10);
    print(a, 10);

    return 0;
}