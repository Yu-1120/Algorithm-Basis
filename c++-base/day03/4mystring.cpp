/*04-字符串类的析构函数*/
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
            len = strlen(s)+1;   //+1是“/n”
            str = new char[len];
            strcpy(str,s);
        }
    }

//    如果没有传递参数，即!s为真，那么将字符串对象的初始值设为长度为10的空字符串。
//    这里使用了new运算符动态分配了一个长度为10的字符数组，并使用memset函数将数组中的每个元素都设置为0。

//    如果传递了参数s，则先计算参数s的长度，并将长度加1，得到字符串对象的总长度。
//    然后使用new运算符动态分配了一个长度为len的字符数组，并使用strcpy函数将参数s的值复制到新分配的字符数组中。



    //析构函数
    ~mystring()
    {
        delete[] this->str;
    }

    //打印字符串
    void show()const
    {
        cout<<str<<endl;
    }

    //获取空间大小
    size_t get_len()const
    {
        cout<<this<<endl;
        return len;
    }

    //获取指定位置的字符
    char at(size_t n)const
    {
        if(n>=len){//越界
            return -1;
        }

        return this->str[n];
    }

    //修改字符串内容 健壮性
    void modify_str(const char *s)
    {
        if(!s){//为空修改为长度为10的空串
            delete[] str;
            len = 10;
            str = new char[len];
            memset(str,0,10);
//            memset是计算机中C/C++语言初始化函数。作用是将某一块内存中的内容全部设置为指定的值，

//            这个函数通常为新申请的内存做初始化工作。
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
    /*
        用于修改字符串内容的函数。它接受一个参数 s，表示要修改的字符串内容。

        如果传入的参数 s 为空指针（即没有传入字符串内容），则将字符串对象的内容修改为长度为10的空串。

        这里使用了动态内存分配，先释放原有的内存空间，然后重新分配一个长度为10的字符数组，并将其初始化为全零。

        如果传入的参数 s 非空指针，则进行以下操作：

        首先判断当前字符串的长度是否小于待修改字符串的长度加1，如果是，说明空间不够，需要调整空间大小。
        释放原有的内存空间。
        根据待修改字符串的长度加1，重新分配一个足够大的字符数组。
        使用 strcpy 函数将待修改字符串的内容复制到新的字符数组中。


    */






private:
    char *str;//字符串内容首地址
    size_t len;//空间大小
};


int main()
{
//    mystring str1;
    mystring str1("welcome to wyu!");
    str1.show();
//    cout<<str1.get_len()<<endl;
    str1.modify_str("hello wrold");
    str1.show();
    size_t n;
    cout<<"请输入指定位置:";
    cin>>n;
    cout<<"该位置的字符为"<<str1.at(n)<<endl;

    return 0;
}
