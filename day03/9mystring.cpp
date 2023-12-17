/*09-字符串类的静态函数*/
#include <iostream>
#include <cstring>

using namespace std;

class mystring{
public:

    /*

        构造函数：用于初始化字符串对象。它接受一个 C 风格的字符串作为参数，并根据是否提供该参数来执行不同的操作。
        如果没有提供参数，则创建一个长度为 10 的空字符串；如果提供了参数，则将参数复制到新创建的字符串中。
    */
    //构造函数
    mystring(const char *s=NULL)
    {
        if(!s){//没有传参数
            this->len = 10;
            this->str = new char[this->len];
            memset(this->str,0,10);
        }
        else{
            this->len = strlen(s)+1;
            this->str = new char[this->len];
            strcpy(this->str,s);
        }
    }
    /*
        拷贝构造函数：用于创建一个与现有字符串对象相同的副本。
        它接受一个 const mystring& 类型的参数，并将其内容复制到新创建的对象中。

    */
    //拷贝构造函数
    mystring(const mystring &s)
    {
        this->len = s.len;
        this->str = new char[this->len];
        strcpy(this->str,s.str);
    }
    /*
        用于释放字符串对象的内存。它在对象销毁时自动调用，释放动态分配的字符数组。

    */
    //析构函数
    ~mystring()
    {
        delete[] this->str;
    }
    /*

        用于打印字符串的内容。它将存储在对象中的字符数组输出到标准输出流
    */
    //打印字符串
    void show()
    {
        cout<<this->str<<endl;
    }
    /*
        返回字符串的长度。它使用 strlen 函数计算存储在对象中的字符数组的长度。

    */
    //获取空间大小
    size_t get_len()
    {
        return this->len;
    }
    /*
        返回字符串的实际长度，而不是存储在对象中的字符数组的长度。它使用 strlen 函数计算存储在对象中的字符数组的长度。

    */
    //获取字符串长度
    size_t get_size()
    {
        return strlen(this->str);
    }
    /*
        返回指定位置的字符。它接受一个 size_t 类型的参数，表示要访问的位置。如果位置越界，则返回 -1。

    */
    //获取字符串长度
    //获取指定位置的字符
    char at(size_t n)
    {
        if(n>=this->len){//越界
            return -1;
        }

        return this->str[n];
    }
    /*
        用于修改字符串的内容。它接受一个 C 风格的字符串作为参数，并将对象中的字符数组替换为新的字符串。
        如果传入的参数为空指针，则将字符数组清空为长度为 10 的空字符串。

    */
    //修改字符串内容 健壮性
    void modify_str(const char *s)
    {
        if(!s){//为空修改为长度为10的空串
            delete[] this->str;
            this->len = 10;
            this->str = new char[this->len];
            memset(this->str,0,10);
        }
        else{//非空
            if(this->len<strlen(s)+1){//空间不够
                //调整空间
                delete[] this->str;
                this->len = strlen(s)+1;
                this->str = new char[this->len];
            }
            strcpy(this->str,s);
        }
    }
    /*
        用于分配指定大小的字符数组空间。它接受一个 size_t 类型的参数，表示要分配的空间大小，
        并返回一个指向新分配的字符数组的指针。

    */
    //静态成员函数，分配字符串空间
    static char *get_space(size_t n)
    {
        return new char[n];
    }

private:
    char *str;//字符串内容首地址
    size_t len;//空间大小
};


int main()
{
    /*
    在 main() 函数中，首先通过调用 mystring::get_space(100) 静态成员函数分配了一个长度为 100 的字符数组空间，
    并将指针保存在变量 s 中。然后，使用 strcpy 函数将字符串 "welcome" 复制到该字符数组中。
    最后，通过调用 cout 对象的成员函数 << 将字符数组的内容输出到标准输出流。

    请注意，这段代码存在一些问题和潜在的错误。例如，没有对 new 操作符返回的指针进行判空处理，可能导致空指针访问错误。
    另外，在 modify_str() 函数中，如果传入的参数为空指针，会释放之前分配的字符数组空间，
    但没有重新分配足够的空间来存储新的字符串，
    可能导致越界访问错误。因此，在实际使用中需要注意这些问题并进行相应的错误处理。

    */
    char *s = mystring::get_space(100);
    strcpy(s,"welcome");

    cout<<s<<endl;

    return 0;
}
