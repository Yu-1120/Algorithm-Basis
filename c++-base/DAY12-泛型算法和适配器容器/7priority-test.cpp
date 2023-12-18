/*06 - 优先队列的使用*/
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> qi;
    

    //入队
    qi.push(4);
    qi.push(5);
    qi.push(8);
    qi.push(1);
    qi.push(3);
    qi.push(2);

    //出队
    while(!qi.empty()){
        cout<<qi.top()<<" ";//优者先出.最大的数先出来
        qi.pop();
    }
    cout<<endl;
   

    return 0;
}
