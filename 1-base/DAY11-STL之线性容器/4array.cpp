/*04-静态数组的使用*/
#include <iostream>
#include <array>

using namespace std;

class Data{
public:
    explicit Data(int d=0):dt(d){}
    friend ostream& operator<<(ostream &os,const Data &d)
    {
        return os<<d.dt;
    }

private:
    int dt;
};

int main()
{
    array<int,5> ai = {2,4,6,8,10};
    array<int,5> ai1 = {1,3,5,7,9};

    //正向迭代
    cout<<"正向迭代:";
    for(array<int,5>::iterator itt=ai.begin();itt!=ai.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    cout<<"大小:"<<ai.size()<<endl;
    cout<<"首元素:"<<ai.front()<<endl;
    cout<<"尾元素:"<<ai.back()<<endl;

    //填充
    ai.fill(33);
    cout<<"填充后:";
    for(array<int,5>::iterator itt=ai.begin();itt!=ai.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;
    //交换
    ai.swap(ai1);//类型必须相同
    cout<<"交换后ai:";
    for(array<int,5>::iterator itt=ai.begin();itt!=ai.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    cout<<"交换后ai1:";
    for(array<int,5>::iterator itt=ai1.begin();itt!=ai1.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    //往array中放Data对象
    array<Data,6> ad;
    ad.at(2) = Data(123);
    cout<<"正向迭代:";
    for(array<Data,6>::iterator itt=ad.begin();itt!=ad.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    return 0;
}
