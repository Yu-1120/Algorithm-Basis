/*03-C++的字符串*/
#include <iostream>
#include <string>//不是 string.h  cstring

using namespace std;

int main()
{
    string str1("hello");
    string str2 = " GZFX2108FX!";
    cout<<str1<<str2<<endl;

    //str1 = "byebye";
    //cout<<str1<<str2<<endl;

    //cout<<str1+str2<<endl;
    //str1 += str2;
    //cout<<str1<<endl;

    //cout<<(str1==str2)<<endl;
    //cout<<(str1>str2)<<endl;
    //cout<<(str1<=str2)<<endl;

    //cout<<str1[13]<<endl;
    //cout<<str1.at(13)<<endl;

    //转换成C风格字符串
    const char *s = str1.c_str();
    cout<<s<<endl;

    //长度/大小
    //cout<<str1.size()<<endl;
    //cout<<str1.length()<<endl;
    //容量
    //cout<<str1.capacity()<<endl;
    //str1 += str2;
    //cout<<str1.capacity()<<endl;
    //最大大小
    //cout<<str1.max_size()<<endl;
    //str1 = "";
    //判空
    //cout<<str1.empty()<<endl;

    //拷贝
    char buf[100] = {};
    str1.copy(buf,3,1);
    cout<<buf<<endl;

    //在指定位置插入
    //str1.insert(2,"KKK");
    //str1.insert(2,str2);
    //str1.insert(2,"John",3);
    //str1.insert(2,str2,3,4);
    //cout<<str1<<endl;

    //交换
    //str1.swap(str2);
    //cout<<str1<<str2<<endl;

    //按字符查找
    //cout<<str2.find('X')<<endl;
    //cout<<str2.find('X',5)<<endl;
    //按字符串查找
    //cout<<str2.find(string("FX"))<<endl;

    //获取子串
    cout<<str2.substr(2,4)<<endl;
    cout<<str2.substr(4)<<endl;


    return 0;
}