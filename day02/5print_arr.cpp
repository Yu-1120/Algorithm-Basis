/*05-��ӡ����*/
#include <iostream>

using namespace std;
int arr[] = {1,2,3,4,5,6,7,8,9};
int arr_size = sizeof(arr) / sizeof(arr[0]);

void print_arr(int *a,int n=arr_size,char op=',')
{
    //��ӡ�������ڶ���
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<op;

    //��ӡ���һ��
    cout<<a[n-1]<<endl;
}

int main()
{


    std::cout << "����Ԫ�ظ���Ϊ�� " << arr_size << std::endl;
    print_arr(arr);
    print_arr(arr,7);
    print_arr(arr,3,' ');
    print_arr(arr,7,'-');

    return 0;
}
