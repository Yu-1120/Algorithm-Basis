/*02-输入输出流*/
#include <iostream>

using namespace std;

int main()
{
    //cout<<"hello";
    //clog<<"hello";
    //cerr<<"hello";

    //while(1);
    cout<<"请输入一个字符:";
    char ch = cin.get();
    cout.put(ch);

    //清除缓冲区
    cin.ignore(100,'\n');

    //读一行
    cout<<"请输入一行:";
    char buf[100] = {};
    //可以读空格
    cin.getline(buf,sizeof(buf));
    //cin>>buf;
    cout<<buf<<endl;

    return 0;
}