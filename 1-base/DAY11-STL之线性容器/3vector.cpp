/*03-向量的使用*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //1.构造向量对象
    vector<int> vi1;//空向量
    vector<int> vi2(10);//指定大小
    vector<int> vi3(10,5);//指定大小和初始值
    int a[5] = {1,2,3,4,5};
    vector<int> vi4(a,a+5);//5个,不包括结束位置 用已有数据初始化

    for(size_t i=0;i<5;i++){
        //cout<<vi4[i]<<" ";
        cout<<vi4.at(i)<<" ";
    }
    cout<<endl;

    //使用迭代器访问vector
    vector<int>::iterator it = vi4.begin();//it是指向vi3的起始正向迭代器
    //迭代器支持*运算
    cout<<*it<<endl;;//获取迭代器指向的元素
    it++;//移动迭代器到下一个元素的位置
    cout<<*it<<endl;

    //使用正向迭代器遍历vector
    for(vector<int>::iterator itt=vi4.begin();itt!=vi4.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    //反向迭代器
    cout<<"反向迭代:";
    for(vector<int>::reverse_iterator itt=vi4.rbegin();itt!=vi4.rend();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    //成员函数
    cout<<"大小:"<<vi4.size()<<endl;
    cout<<"容量:"<<vi4.capacity()<<endl;
    //调整大小
    vi4.resize(8,10);
    //vi4.clear();
    //调整容量
    vi4.reserve(19);
    cout<<"调整大小后:";
    for(vector<int>::iterator itt=vi4.begin();itt!=vi4.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;
    cout<<"大小:"<<vi4.size()<<endl;
    cout<<"容量:"<<vi4.capacity()<<endl;

    cout<<"首元素:"<<vi4.front()<<endl;
    cout<<"尾元素:"<<vi4.back()<<endl;
    //插入
    vi4.insert(vi4.begin()+2,44);
    vi4.push_back(123);//尾部插入
    cout<<"插入数据后:";
    for(vector<int>::iterator itt=vi4.begin();itt!=vi4.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;
    //删除
    vi4.erase(vi4.begin()+3);
    vi4.pop_back();
    cout<<"删除数据后:";
    for(vector<int>::iterator itt=vi4.begin();itt!=vi4.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;
    //判空
    cout<<"判空:"<<vi1.empty()<<" "<<vi4.empty()<<endl;

    //修改容器后要重置迭代器
    it = vi4.end()-3;
    cout<<*it<<endl;

    //vector的嵌套=相当于一个二维数组
    vector<vector<int>> vvi;

    return 0;
}
