/*02-泛型算法*/
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

//类模板
template <typename T>
class A{
public:
    A(T t=0):t(t){}

    //重载<运算符
    bool operator<(const A &a)const
    {
        return this->t<a.t;
    }

    bool operator>(const A &a)const
    {
        return this->t>a.t;
    }

    //重载==运算符支持查找
    bool operator==(const A &a)const
    {
        return this->t==a.t;
    }

    //输出
    friend ostream& operator<<(ostream &os,const A &a)
    {
        return os<<a.t;
    }

private:
    T t;
};

//函数模板比较器
template <typename T>
bool comp(const T &a,const T &b)
{
    return a>b;
}

//函数对象类模板比较器
template <typename T>
class Comparetor{
public:
    bool operator()(const T &a,const T &b)
    {
        return a>b;
    }
};

//对参数+1
template <typename T>
void inc_T(T &t)
{
    t++;
}

//打印
template <typename T>
void print_T(const T &t)
{
    cout<<t<<endl;
}

//函数对象打印
template <typename T>
class Print_T{
public:
    void operator()(const T &t)
    {
        cout<<t<<endl;
    }
};

//打印模板
template <typename T>
void print(T *a,int n)
{
    for(int i=0;i<n;i++){
        cout <<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //1.排序
    int arr[9] = {6,1,9,3,7,2,8,5,4};
    // sort(arr,arr+9);//arr~arr+9-1的范围内排序  从小到大排列
    //使用比较器排序
    sort(arr,arr+9,comp<int>);//重载了函数模板比较器，从大到小排列
    print(arr,9);

    // //对容器排序
    array<int,10> arr1 = {5,2,3,1,7,9,4,8,11,6};
    sort(arr1.begin()+1,arr1.end()-2);//指定排序范围   //只排序了中间的几个元素  5 1 2 3 4 7 8 9 11 6
    cout<<"array1排序后:";
    for(array<int,10>::iterator it=arr1.begin();it!=arr1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    array<A<int>,10> arr2 = {5,2,3,1,7,9,4,8,11,6};
    //默认<排序
    //sort(arr2.begin(),arr2.end());
    //函数比较器
    //sort(arr2.begin(),arr2.end(),comp<A<int>>);
    //函数对象比较器
    sort(arr2.begin(),arr2.end(),Comparetor<A<int>>());  //写法跟comp<int 差不多>
    cout<<"array2排序后:";
    for(array<A<int>,10>::iterator it=arr2.begin();it!=arr2.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //2.查找
    cout<<"---------------------查找----------------------"<<endl;
    int *p = find(arr,arr+9,9);//查到9个元素
     cout<<*p<<endl; // 9 这个是9是元素的个数还是数组长度==(好像都差不多意思)
    if(p==arr+9){
        cout<<"没找到!"<<endl;
    }
    else{
        cout<<"找到了 "<<*p<<endl;
    }

    //容器查找
    cout<<"---------------------容器查找----------------------"<<endl;
    array<int,10>::iterator it = find(arr1.begin(),arr1.end(),11);
    if(it==arr1.end()){
        cout<<"没找到!"<<endl;
    }
    else{
        cout<<"找到了 "<<*it<<endl;
    }

    //类类型查找
    cout<<"---------------------类类型查找----------------------"<<endl;
    array<A<int>,10>::iterator itt = find(arr2.begin(),arr2.end(),A<int>(12));
    if(itt==arr2.end()){
        cout<<"没找到!"<<endl;
    }
    else{
        cout<<"找到了 "<<*it<<endl;
    }

    //3.遍历
    cout<<"-----------------遍历--------------------------"<<endl;
    for_each(arr,arr+9,inc_T<int>);//+1
    //print(arr,9);
    //for_each(arr,arr+9,print_T<int>);//打印
    //for_each(arr,arr+9,Print_T<int>());
    //遍历类类型
    for_each(arr2.begin(),arr2.end(),Print_T<A<int>>());

    return 0;
}
