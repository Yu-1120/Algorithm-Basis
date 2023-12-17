/*01 - 模板实现二分查找*/
#include <iostream>
#include <cstring>

using namespace std;

//函数模板
template <typename T>
int search(T *arr,int n,T dt)
{
    //L表示查找的起始位置，R表示查找的结束位置
    int L = 0;
    int R = n-1;
    int mid = 0;

    while(L<=R){
        //找出中间元素
        mid = (L+R)/2;

        //比较中间元素和查找目标
        if(arr[mid]==dt){
            return mid;
        }
        else if(arr[mid]>dt){
            //前子表中查找
            R = mid-1;
        }
        else{
            L = mid+1;
        }
    }

    return -1;
}

//函数模板的特化
template <>
int search<const char *>(const char **arr,int n,const char *dt)
{
    //L表示查找的起始位置，R表示查找的结束位置
    int L = 0;
    int R = n-1;
    int mid = 0;

    while(L<=R){
        //找出中间元素
        mid = (L+R)/2;

        //比较中间元素和查找目标
        if(strcmp(arr[mid],dt)==0){
            return mid;
        }
        else if(strcmp(arr[mid],dt)>0){
            //前子表中查找
            R = mid-1;
        }
        else{
            L = mid+1;
        }
    }

    return -1;
}

//类模板
template <typename T>
class Searcher{
public:
    int operator()(T *arr,int from,int to,T dt)
    {
        //计算中间元素下标
        int mid = (from+to)/2;

        //2.递归结束条件
        if(from>to)
            return -1;

        //1.拆分问题
        if(arr[mid]==dt)
            return mid;
        else if(arr[mid]>dt)//前子表查找
            return operator()(arr,from,mid-1,dt);
        else
            return operator()(arr,mid+1,to,dt);
    }
};

//成员特化
template <>
int Searcher<const char *>::operator()(const char **arr,int from,int to,const char *dt)
{
    //计算中间元素下标
    int mid = (from+to)/2;

    //2.递归结束条件
    if(from>to)
        return -1;

    //1.拆分问题
    if(strcmp(arr[mid],dt)==0)
        return mid;
    else if(strcmp(arr[mid],dt)>0)//前子表查找
        return operator()(arr,from,mid-1,dt);
    else
        return operator()(arr,mid+1,to,dt);
}

int main()
{
    int a[] = {1,3,5,7,9,11,13,15,17,19};
    const char *ca[] = {"Japan","UK","byebye","template","welcome"};
    const char buf[] = "UK";

    //cout<<search(a,10,111)<<endl;
    //cout<<search(ca,5,buf)<<endl;

    Searcher<int> sc;
    cout<<sc(a,0,9,11)<<endl;
    Searcher<const char *> ss;
    cout<<ss(ca,0,4,buf)<<endl;

    return 0;
}
