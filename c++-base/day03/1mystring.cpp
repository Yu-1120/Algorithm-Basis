/*01-字符串类的作业*/
#include <iostream>
#include <cstring>

using namespace std;

class mystring{
public:
    //构造函数
    mystring(const char *s=NULL)
    {
        if(!s){//没有传参数
            len = 10;
            str = new char[len];
            memset(str,0,10);
        }
        else{
            len = strlen(s)+1;
            str = new char[len];
            strcpy(str,s);
        }
    }

    //打印字符串
    void show()
    {
        cout<<str<<endl;
    }

    //获取空间大小
    size_t get_len()
    {
        cout<<this<<endl;
        return len;
    }

    //修改字符串内容 健壮性
    void modify_str(const char *s)
    {
        if(!s){//为空修改为长度为10的空串
            delete[] str;
            len = 10;
            str = new char[len];
            memset(str,0,10);
        }
        else{//非空
            if(len<strlen(s)+1){//空间不够
                //调整空间
                delete[] str;
                len = strlen(s)+1;
                str = new char[len];
            }
            strcpy(str,s);
        }
    }

private:
    char *str;//字符串内容首地址
    size_t len;//空间大小
};


int main()
{
    //mystring str1;
    mystring str1("hello");
    cout<<"str1地址:"<<&str1<<endl;
    str1.show();
    cout<<str1.get_len()<<endl;

    str1.modify_str("welcome to GEC!");
    str1.show();
    cout<<str1.get_len()<<endl;

    mystring str2;
    cout<<"str2地址:"<<&str2<<endl;
    cout<<str2.get_len()<<endl;

    return 0;
}
