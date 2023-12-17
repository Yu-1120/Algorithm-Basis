/*06 - 队列的使用*/
#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main()
{
    queue<int> qi;                  // deque作为底层容器
    queue<string, list<string>> qs; // deque是顺序，list是链式的队列

    qs.push("今天");
    qs.push("广州");
    qs.push("下雨");

    cout << "大小:" << qs.size() << endl;
    while (!qs.empty())
    {
        cout << qs.front() << " "; //队首元素
        qs.pop();
    }
    cout << endl;

    return 0;
}
