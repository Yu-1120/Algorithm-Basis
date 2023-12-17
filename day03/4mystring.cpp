/*04-�ַ��������������*/
#include <iostream>
#include <cstring>

using namespace std;

class mystring{
public:
    //���캯��
    mystring(const char *s=NULL)
    {
        if(!s){//û�д�����
            len = 10;
            str = new char[len];
            memset(str,0,10);
        }
        else{
            len = strlen(s)+1;   //+1�ǡ�/n��
            str = new char[len];
            strcpy(str,s);
        }
    }

//    ���û�д��ݲ�������!sΪ�棬��ô���ַ�������ĳ�ʼֵ��Ϊ����Ϊ10�Ŀ��ַ�����
//    ����ʹ����new�������̬������һ������Ϊ10���ַ����飬��ʹ��memset�����������е�ÿ��Ԫ�ض�����Ϊ0��

//    ��������˲���s�����ȼ������s�ĳ��ȣ��������ȼ�1���õ��ַ���������ܳ��ȡ�
//    Ȼ��ʹ��new�������̬������һ������Ϊlen���ַ����飬��ʹ��strcpy����������s��ֵ���Ƶ��·�����ַ������С�



    //��������
    ~mystring()
    {
        delete[] this->str;
    }

    //��ӡ�ַ���
    void show()const
    {
        cout<<str<<endl;
    }

    //��ȡ�ռ��С
    size_t get_len()const
    {
        cout<<this<<endl;
        return len;
    }

    //��ȡָ��λ�õ��ַ�
    char at(size_t n)const
    {
        if(n>=len){//Խ��
            return -1;
        }

        return this->str[n];
    }

    //�޸��ַ������� ��׳��
    void modify_str(const char *s)
    {
        if(!s){//Ϊ���޸�Ϊ����Ϊ10�Ŀմ�
            delete[] str;
            len = 10;
            str = new char[len];
            memset(str,0,10);
//            memset�Ǽ������C/C++���Գ�ʼ�������������ǽ�ĳһ���ڴ��е�����ȫ������Ϊָ����ֵ��

//            �������ͨ��Ϊ��������ڴ�����ʼ��������
        }
        else{//�ǿ�
            if(len<strlen(s)+1){//�ռ䲻��
                //�����ռ�
                delete[] str;
                len = strlen(s)+1;
                str = new char[len];
            }
            strcpy(str,s);
        }
    }
    /*
        �����޸��ַ������ݵĺ�����������һ������ s����ʾҪ�޸ĵ��ַ������ݡ�

        �������Ĳ��� s Ϊ��ָ�루��û�д����ַ������ݣ������ַ�������������޸�Ϊ����Ϊ10�Ŀմ���

        ����ʹ���˶�̬�ڴ���䣬���ͷ�ԭ�е��ڴ�ռ䣬Ȼ�����·���һ������Ϊ10���ַ����飬�������ʼ��Ϊȫ�㡣

        �������Ĳ��� s �ǿ�ָ�룬��������²�����

        �����жϵ�ǰ�ַ����ĳ����Ƿ�С�ڴ��޸��ַ����ĳ��ȼ�1������ǣ�˵���ռ䲻������Ҫ�����ռ��С��
        �ͷ�ԭ�е��ڴ�ռ䡣
        ���ݴ��޸��ַ����ĳ��ȼ�1�����·���һ���㹻����ַ����顣
        ʹ�� strcpy ���������޸��ַ��������ݸ��Ƶ��µ��ַ������С�


    */






private:
    char *str;//�ַ��������׵�ַ
    size_t len;//�ռ��С
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
    cout<<"������ָ��λ��:";
    cin>>n;
    cout<<"��λ�õ��ַ�Ϊ"<<str1.at(n)<<endl;

    return 0;
}
