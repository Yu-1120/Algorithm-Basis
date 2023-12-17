/*01-��������ʵ��*/
#include <iostream>
#include <cstring>

using namespace std;
    /*
        ���캯����MyArray(int *arr=NULL, size_t len=10)��

        �ù��캯������һ��ָ�����������ָ��arr��һ������len��Ϊ������
        ���������arr����ʹ��arr�����ݳ�ʼ������Ԫ�أ����򣬽�����Ԫ�س�ʼ��Ϊ0��
    */
class MyArray{
public:
    //���캯��
    MyArray(int *arr=NULL,size_t len=10):len(len)
    {
        //����ռ�
        this->pdata = new int[this->len];
        //��ʼ������Ԫ��
        if(arr){
            //�����������ʹ����������ݽ��г�ʼ��
            memcpy(this->pdata, arr, this->len*sizeof(int));
        }
        else{
            //û�д�����ͳ�ʼ��Ϊ0
            memset(this->pdata, 0, this->len*sizeof(int));
        }
    }
    /*
        ����������~MyArray()�������������ͷ��˶�̬������ڴ�ռ䡣
    */
    //��������
    ~MyArray()
    {
        delete[] this->pdata;
    }
    /*
        �������캯����MyArray(const MyArray &arr)��
       �ÿ������캯�����ڴ���һ�������ж���������ͬ���¶���
        ������һ����������arr��Ϊ��������ʹ��arr�����ݳ�ʼ���¶��������Ԫ�ء�
    */
    //�������캯��
    MyArray(const MyArray &arr):len(arr.len)/*��ʼ�������б�*/
    {
        //this->len = arr.len;
        this->pdata = new int[this->len];
        memcpy(this->pdata, arr.pdata, this->len*sizeof(int));
    }
    /*
        ��ӡ������void print_arr()���ú������ڴ�ӡ�����Ԫ�ء�


    */
    //��ӡ
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
        ��main�����У����ȴ�����һ���յ�MyArray����arr1��Ȼ�����print_arr()��ӡ����Ԫ�أ�ӦΪ�գ���
        ���ţ�������һ������9��Ԫ�ص���������arr����������Ϊ�������ݸ�MyArray���캯����������һ����Ϊarr2�Ķ���
        Ȼ���ٴε���print_arr()��ӡarr2��Ԫ�أ�ӦΪ{1, 2, 3, 4, 5, 6, 7, 8, 9}����
        ���ͨ���������캯��������һ����Ϊarr3�Ķ��󣬲���arr2��Ϊ�������ݸ��������캯����
        ����ٴε���print_arr()��ӡarr3��Ԫ�أ�Ӧ��arr2��ͬ����
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
