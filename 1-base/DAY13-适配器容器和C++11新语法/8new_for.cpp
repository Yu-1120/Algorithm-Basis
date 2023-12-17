/*07 - for循环新用法*/
#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};

    for(int x:arr)
        cout<< x<<" ";
    cout<<endl;

    //和auto结合使用
    for(auto x:arr)
        cout<< x<<" ";
    cout<<endl;

    vector<int> vi(arr,arr+9);
    srand(time(0));
    //修改容器
    for(auto &x:vi)
        x = rand()%100;
    //遍历容器
    for(auto x:vi)
        cout<< x<<" ";
    cout<<endl;

    return 0;
}
