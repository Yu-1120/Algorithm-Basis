/*06-双端队列的使用*/
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> di(10,5);//长度为10，初始值为5

    cout<<"正向迭代:";
    for(deque<int>::iterator itt=di.begin();itt!=di.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    //头部插入
    di.push_front(100);
    di.push_back(200);

    cout<<"插入后:";
    for(deque<int>::iterator itt=di.begin();itt!=di.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    //头部删除
    di.pop_front();
    cout<<"删除后:";
    for(deque<int>::iterator itt=di.begin();itt!=di.end();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;

    //头部删除
    cout<<"反向迭代:";
    for(deque<int>::reverse_iterator itt=di.rbegin();itt!=di.rend();itt++){
        cout<<*itt<<" ";
    }
    cout<<endl;


    return 0;
}
