/*08 - 类模板的成员特化*/
#include <iostream>
#include <cstring>

using namespace std;

//类模板实现函数对象排序
template <typename T>
class Sortor{
public:
    //函数对象 --- 快速排序
    void operator()(T *arr,int n)
    {
        int L = 0;
        int R = n-1;

        //退出条件
        if(n<=1)
            return;


        T tmp = arr[L];
        while(L<R){
            //以左边作为基准，比较右边
            while(L<R&&arr[R]>=tmp)
                R--;
            arr[L] = arr[R];
            //比较左边
            while(L<R&&arr[L]<=tmp)
                L++;
            arr[R] = arr[L];
        }

        //将基准放回重合位置
        arr[L] = tmp;

        //递归前面的分组和后面的分组
        operator()(arr,L);
        operator()(arr+L+1,n-L-1);
    }

    void print(T *arr,int n)
    {
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

//针对类模板的成员特化 ----- 特化重载函数对象的成员函数
template <>
void Sortor<const char *>::operator()(const char **arr,int n)
{
    int L = 0;
    int R = n-1;

    //退出条件
    if(n<=1)
        return;


    const char *tmp = arr[L];
    while(L<R){
        //以左边作为基准，比较右边
        while(L<R&&strcmp(arr[R],tmp)>=0)
            R--;
        arr[L] = arr[R];
        //比较左边
        while(L<R&&strcmp(arr[L],tmp)<=0)
            L++;
        arr[R] = arr[L];
    }

    //将基准放回重合位置
    arr[L] = tmp;

    //递归前面的分组和后面的分组
    operator()(arr,L);
    operator()(arr+L+1,n-L-1);
}

int main()
{

    int a[] = {5,9,6,8,4,7,1,15,2};
    double d_a[] = {3.9,6.8,4.1,7.5,3.6,8.9,2.4,9.7,1.3};
    string str_a[] = {"welcome","template","UK","byebye","Japan"};
    const char *str_a1[] = {"welcome","template","UK","byebye","Japan"};

    Sortor<int> si;
    si(a,9);
    si.print(a,9);

    Sortor<double> sd;
    sd(d_a,9);
    sd.print(d_a,9);

    Sortor<string> ss;
    ss(str_a,5);
    ss.print(str_a,5);

    Sortor<const char *> sc;
    sc(str_a1,5);
    sc.print(str_a1,5);

    return 0;
}
