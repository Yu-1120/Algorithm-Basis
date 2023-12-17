/*04 - 堆栈*/
#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

int main()
{
    //定义堆栈对象
    //stack<int,vector<int>> sv;
    //stack<string> ss;//deque
    //stack<string,vector<string>> ss;
    stack<string,list<string>> ss;

    //入栈
    ss.push("天");
    ss.push("气");
    ss.push("真");
    ss.push("好");
    ss.push("!");

    //出栈
    while(!ss.empty()){
        cout<<ss.top()<<endl;//栈顶元素
        // ss.pop();弹出最上面的那个
    }
    cout<<endl;


    return 0;
}
