/*08 - 类模板的递归实例化*/
#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;

template <typename T>
class MyArray{
public:
    //构造函数
    MyArray(T *arr=NULL,size_t len=10):len(len)
    {
        //分配空间 ----- 默认抛异常
        this->pdata = new T[this->len];
        //初始化数组元素
        if(arr){
            //传入了数组就使用数组的数据进行初始化
            memcpy(this->pdata, arr, this->len*sizeof(T));
        }
        else{
            //没有传数组就初始化为0
            //memset(this->pdata, 0, this->len*sizeof(T));
        }
    }

    //析构函数
    ~MyArray()
    {
        delete[] this->pdata;
    }

    //拷贝构造函数
    MyArray(const MyArray &arr):len(arr.len)/*初始化参数列表*/
    {
        //this->len = arr.len;
        this->pdata = new T[this->len];
        memcpy(this->pdata, arr.pdata, this->len*sizeof(T));
    }

    //重载=运算符
    MyArray& operator=(const MyArray &arr)
    {
        //防止自赋值
        if(this==&arr)
            return *this;

        //释放旧空间
        delete[] this->pdata;
        //申请空间
        this->pdata = new T[arr.len];
        this->len = arr.len;
        //拷贝数据
        for(size_t i=0;i<arr.len;i++){
            this->pdata[i] = arr.pdata[i];
        }

        return *this;
    }

    //数组对象,重载[]
    T& operator[](int n)
    {
        return this->pdata[n];
    }

    //at成员函数，可能抛出out_of_range的异常
    T& at(size_t n)
    {
        //下标有效
        if(n<this->len)
            return this->pdata[n];

        //无效抛出out_of_range的异常
        throw out_of_range("at下标越界");
    }

    //重载(强转) ------ (int)得到数组第一个元素
    operator T()
    {
        return this->pdata[0];
    }

    //强转(size_t)，得到数组长度
    operator size_t()
    {
        return this->len;
    }

    //重载() ----- 函数对象 ---- 数组求和
    T operator()(const MyArray &arr)
    {
        T sum = 0;
        for(size_t i=0;i<arr.len;i++){
            sum += arr.pdata[i];
        }

        return sum;
    }

    //重载<<
    friend ostream& operator<<(ostream &os,const MyArray &arr)
    {
        for(size_t i=0;i<arr.len-1;i++)
            os<<arr.pdata[i]<<",";

        return os<<arr.pdata[arr.len-1];
    }

private:
    T *pdata;
    /*const */size_t len;
};


int main()
{
    MyArray<int> arr;
    arr[1] = 111;
    cout<<arr<<endl;

    //递归实例化
    MyArray<MyArray<int>> arr1;
    arr1[1][1] = 100;
    cout<<arr1[1][1]<<endl;
    cout<<arr1<<endl;

    return 0;
}
