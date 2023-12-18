/*01 - 作业,获取字符串前后相同的部分*/
#include <iostream>

using namespace std;

int main()
{
    string str1,str2,str3;
    //记录字符串前后相同的长度
    int front_len = 0,back_len = 0;

    //输入要比较的字符串
    cout<<"请输入第一个字符串:";
    getline(cin,str1);
    cout<<"请输入第二个字符串:";
    getline(cin,str2);

    cout<<str1<<endl;
    cout<<str2<<endl;

    size_t min_len = str1.length()<str2.length()?str1.length():str2.length();
    //从前往后遍历，计算相同字符的长度
    size_t i;
    for(i=0;i<min_len;i++){
        //遇到第一个不同的字符，退出
        if(str1.at(i)!=str2.at(i))
            break;
    }
    front_len = i;

    //从后往前遍历字符串，计算相同字符的长度
    for(i=0;i<min_len;i++){
        if(str1.at(str1.length()-1-i)!=str2.at(str2.length()-1-i))
            break;
    }
    back_len = i;

    //如果两个字符串相同
    if(str1==str2){
        cout<<"合并结果:"<<str1<<endl;
    }
    else{
        str3 = str1.substr(0,front_len)+str1.substr(str1.length()-back_len,back_len);
        cout<<"合并结果:"<<str3<<endl;
    }

    return 0;
}