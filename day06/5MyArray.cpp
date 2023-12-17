/*05-数组对象，强转和函数对象*/
#include <iostream>
#include <cstring>

using namespace std;

class MyArray{
public:
    //构造函数
    MyArray(int *arr=NULL,size_t len=10):len(len)
    {
        //分配空间
        this->pdata = new int[this->len];
        //初始化数组元素
        if(arr){
            //传入了数组就使用数组的数据进行初始化
            memcpy(this->pdata, arr, this->len*sizeof(int));
        }
        else{
            //没有传数组就初始化为0
            memset(this->pdata, 0, this->len*sizeof(int));
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
        this->pdata = new int[this->len];
        memcpy(this->pdata, arr.pdata, this->len*sizeof(int));
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
        this->pdata = new int[arr.len];
        this->len = arr.len;
        //拷贝数据
        for(size_t i=0;i<arr.len;i++){
            this->pdata[i] = arr.pdata[i];
        }

        return *this;
    }

    //数组对象,重载[]
    int& operator[](int n)
    {
        return this->pdata[n];
    }

    //重载(强转) ------ (int)得到数组第一个元素
    operator int()
    {
        return this->pdata[0];
    }

    //强转(size_t)，得到数组长度
    operator size_t()
    {
        return this->len;
    }

    //重载() ----- 函数对象 ---- 数组求和
    int operator()(const MyArray &arr)
    {
        int sum = 0;
        for(size_t i=0;i<arr.len;i++){
            sum += arr.pdata[i];
        }

        return sum;
    }

    //重载<<
    friend ostream& operator<<(ostream &os,const MyArray &arr);

private:
    int *pdata;
    /*const */size_t len;
};

ostream& operator<<(ostream &os,const MyArray &arr)
{
    for(size_t i=0;i<arr.len-1;i++)
        os<<arr.pdata[i]<<",";

    return os<<arr.pdata[arr.len-1];
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    MyArray arr2(arr,9);
    cout<<arr2<<endl;

    MyArray arr1;
    cout<<arr1<<endl;
    arr1 = arr2;
    cout<<arr1<<endl;

    arr1[0] = 10;//arr1.operator[](0) = 10; ===> arr1.pdata[0] = 10;
    cout<<arr1<<endl;
    cout<<arr2<<endl;
    cout<<arr2[5]<<endl;

    cout<<(int)arr1<<endl;//arr1.operator int(); ===> arr1.pdata[0]
    cout<<"arr1的长度为"<<(size_t)arr1<<endl;

    //函数对象求和
    cout<<"arr1求和结果为"<<arr1(arr1)<<endl;//arr1.operator()(arr1);
    cout<<"arr2求和结果为"<<arr1(arr2)<<endl;

    return 0;
}
