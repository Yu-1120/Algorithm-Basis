/*01-字符串重载作业*/
#include <iostream>
#include <cstring>

using namespace std;

class mystring{
public:
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

    //拷贝构造函数
    mystring(const mystring &s)
    {
        this->len = s.len;
        this->str = new char[this->len];
        strcpy(this->str,s.str);
    }

    //析构函数
    ~mystring()
    {
        delete[] this->str;
    }

    //+
    mystring operator+(const mystring &s)
    {
        /*
        char *tmp_buf = new char[this->len+s.len];
        memset(tmp_buf,0,this->len+s.len);
        strcpy(tmp_buf,this->str);
        strcat(tmp_buf,s.str);

        mystring tmp_str(tmp_buf);
        //释放
        delete[] tmp_buf;

        return tmp_str;
        */
        mystring tmp_str;
        tmp_str.set_len(this->len+s.len);
        strcpy(tmp_str.str,this->str);
        strcat(tmp_str.str,s.str);

        return tmp_str;
    }

    //赋值
    mystring& operator=(const mystring &s)
    {
        //防止自赋值
        if(this==&s)
            return *this;

        //释放旧空间
        delete[] this->str;
        //申请空间
        this->str = new char[s.len];
        this->len = s.len;
        //拷贝数据
        for(size_t i=0;i<s.len;i++){
            this->str[i] = s.str[i];
        }

        return *this;
    }

    //[]
    char& operator[](int n)
    {
        return this->str[n];
    }

    //(char)
    operator char()
    {
        return this->str[0];
    }

    //函数对象比较字符串
    bool operator()(const mystring &s)
    {
        return strcmp(this->str,s.str)==0;
    }

    //扩容
    void set_len(size_t len)
    {
        if(len>this->len){
            char *tmp_buf = new char[len];
            strcpy(tmp_buf,this->str);
            delete[] this->str;
            this->str = tmp_buf;
        }
    }

    //获取空间大小
    size_t get_len()
    {
        return this->len;
    }

    //获取字符串长度
    size_t get_size()
    {
        return strlen(this->str);
    }

    //获取指定位置的字符
    char at(size_t n)
    {
        if(n>=this->len){//越界
            return -1;
        }

        return this->str[n];
    }

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

    friend ostream& operator<<(ostream &os,const mystring &s);

private:
    char *str;//字符串内容首地址
    size_t len;//空间大小
};

ostream& operator<<(ostream &os,const mystring &s)
{
    return os<<s.str;
}

int main()
{
    mystring str1("hello");
    mystring str2("world");

    cout<<(str1+str2)<<endl;
    str1 = str2;
    cout<<str2[2]<<endl;
    str2[2] = 'e';
    cout<<str2<<endl;
    cout<<(char)str2<<endl;

    cout<<str1(str2)<<endl;

    return 0;
}
