/*01-数组对象的实现*/
#include <iostream>
#include <cstring>

using namespace std;
    /*
        构造函数：MyArray(int *arr=NULL, size_t len=10)。

        该构造函数接受一个指向整数数组的指针arr和一个长度len作为参数。
        如果传入了arr，则使用arr的数据初始化数组元素；否则，将数组元素初始化为0。
    */
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
    /*
        析构函数：~MyArray()。该析构函数释放了动态分配的内存空间。
    */
    //析构函数
    ~MyArray()
    {
        delete[] this->pdata;
    }
    /*
        拷贝构造函数：MyArray(const MyArray &arr)。
       该拷贝构造函数用于创建一个与已有对象内容相同的新对象。
        它接受一个常量引用arr作为参数，并使用arr的数据初始化新对象的数组元素。
    */
    //拷贝构造函数
    MyArray(const MyArray &arr):len(arr.len)/*初始化参数列表*/
    {
        //this->len = arr.len;
        this->pdata = new int[this->len];
        memcpy(this->pdata, arr.pdata, this->len*sizeof(int));
    }
    /*
        打印函数：void print_arr()。该函数用于打印数组的元素。


    */
    //打印
    void print_arr()
    {
        for(size_t i=0;i<this->len;i++)
            cout<<this->pdata[i]<<" ";
        cout<<endl;
    }

private:
    int *pdata;
    /*const */size_t len;
};

/*
        在main函数中，首先创建了一个空的MyArray对象arr1，然后调用print_arr()打印数组元素（应为空）。
        接着，创建了一个包含9个元素的整型数组arr，并将其作为参数传递给MyArray构造函数，创建了一个名为arr2的对象。
        然后再次调用print_arr()打印arr2的元素（应为{1, 2, 3, 4, 5, 6, 7, 8, 9}）。
        最后，通过拷贝构造函数创建了一个名为arr3的对象，并将arr2作为参数传递给拷贝构造函数。
        最后再次调用print_arr()打印arr3的元素（应与arr2相同）。
*/
int main()
{
    MyArray arr1;
    arr1.print_arr();

    int arr[] = {1,2,3,4,5,6,7,8,9};
    MyArray arr2(arr,9);
    arr2.print_arr();

    MyArray arr3 = arr2;
    arr3.print_arr();
    /*
        0 0 0 0 0 0 0 0 0 0
        1 2 3 4 5 6 7 8 9
        1 2 3 4 5 6 7 8 9
    */
    return 0;
}
