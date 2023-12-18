/*06 - 函数模板和类模板的特化*/
#include <iostream>
#include <cstring>

using namespace std;

//函数模板 ---- 冒泡排序
template<typename T>
void mysort(T *arr, int n) {
    cout << "原始模板" << endl;

    for (int i = 0; i < n - 1; i++) {
        bool flag = true;
        //两两比较
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                flag = false;
            }
        }

        //没有发生交换，排序完成
        if (flag)
            break;
    }
}

//函数模板的特化 -----   const char *
template<>
void mysort<const char *>(const char **arr, int n) {
    cout << "特化模板" << endl;

    for (int i = 0; i < n - 1; i++) {
        bool flag = true;
        //两两比较
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                const char *tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                flag = false;
            }
        }

        //没有发生交换，排序完成
        if (flag)
            break;
    }
}

//类模板实现函数对象排序
template<typename T>
class Sortor {
public:
    //函数对象 --- 快速排序
    void operator()(T *arr, int n) {
        int L = 0;
        int R = n - 1;

        //退出条件
        if (n <= 1)
            return;


        T tmp = arr[L];
        while (L < R) {
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
        operator()(arr, L);
        operator()(arr + L + 1, n - L - 1);
    }
};

//类模板的特化
template<>
class Sortor<const char *> {
public:
    //函数对象 --- 快速排序
    void operator()(const char **arr, int n) {
        int L = 0;
        int R = n - 1;

        //退出条件
        if (n <= 1)
            return;


        const char *tmp = arr[L];
        while (L < R) {
            //以左边作为基准，比较右边
            while (L < R && strcmp(arr[R], tmp) >= 0)
                R--;
            arr[L] = arr[R];
            //比较左边
            while (L < R && strcmp(arr[L], tmp) <= 0)
                L++;
            arr[R] = arr[L];
        }

        //将基准放回重合位置
        arr[L] = tmp;

        //递归前面的分组和后面的分组
        operator()(arr, L);
        operator()(arr + L + 1, n - L - 1);
    }
};


//打印
template<typename T>
void print(T *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {5, 9, 6, 8, 4, 7, 1, 15, 2};
    double d_a[] = {3.9, 6.8, 4.1, 7.5, 3.6, 8.9, 2.4, 9.7, 1.3};
    string str_a[] = {"welcome", "template", "UK", "byebye", "Japan"};
    const char *str_a1[] = {"welcome", "template", "UK", "byebye", "Japan"};

    /*
    mysort(a,9);
    print(a,9);
    mysort(d_a,9);
    print(d_a,9);
    mysort(str_a,5);
    print(str_a,5);
    mysort(str_a1,5);
    print(str_a1,5);
    */

    Sortor<int> si;
    si(a, 9);
    print(a, 9);

    Sortor<double> sd;
    sd(d_a, 9);
    print(d_a, 9);

    Sortor<string> ss;
    ss(str_a, 5);
    print(str_a, 5);

    Sortor<const char *> sc;
    sc(str_a1, 5);
    print(str_a1, 5);

    return 0;
}