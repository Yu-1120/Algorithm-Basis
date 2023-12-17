/*09-�ַ�����ľ�̬����*/
#include <iostream>
#include <cstring>

using namespace std;

class mystring{
public:

    /*

        ���캯�������ڳ�ʼ���ַ�������������һ�� C �����ַ�����Ϊ�������������Ƿ��ṩ�ò�����ִ�в�ͬ�Ĳ�����
        ���û���ṩ�������򴴽�һ������Ϊ 10 �Ŀ��ַ���������ṩ�˲������򽫲������Ƶ��´������ַ����С�
    */
    //���캯��
    mystring(const char *s=NULL)
    {
        if(!s){//û�д�����
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
        �������캯�������ڴ���һ���������ַ���������ͬ�ĸ�����
        ������һ�� const mystring& ���͵Ĳ��������������ݸ��Ƶ��´����Ķ����С�

    */
    //�������캯��
    mystring(const mystring &s)
    {
        this->len = s.len;
        this->str = new char[this->len];
        strcpy(this->str,s.str);
    }
    /*
        �����ͷ��ַ���������ڴ档���ڶ�������ʱ�Զ����ã��ͷŶ�̬������ַ����顣

    */
    //��������
    ~mystring()
    {
        delete[] this->str;
    }
    /*

        ���ڴ�ӡ�ַ��������ݡ������洢�ڶ����е��ַ������������׼�����
    */
    //��ӡ�ַ���
    void show()
    {
        cout<<this->str<<endl;
    }
    /*
        �����ַ����ĳ��ȡ���ʹ�� strlen ��������洢�ڶ����е��ַ�����ĳ��ȡ�

    */
    //��ȡ�ռ��С
    size_t get_len()
    {
        return this->len;
    }
    /*
        �����ַ�����ʵ�ʳ��ȣ������Ǵ洢�ڶ����е��ַ�����ĳ��ȡ���ʹ�� strlen ��������洢�ڶ����е��ַ�����ĳ��ȡ�

    */
    //��ȡ�ַ�������
    size_t get_size()
    {
        return strlen(this->str);
    }
    /*
        ����ָ��λ�õ��ַ���������һ�� size_t ���͵Ĳ�������ʾҪ���ʵ�λ�á����λ��Խ�磬�򷵻� -1��

    */
    //��ȡ�ַ�������
    //��ȡָ��λ�õ��ַ�
    char at(size_t n)
    {
        if(n>=this->len){//Խ��
            return -1;
        }

        return this->str[n];
    }
    /*
        �����޸��ַ��������ݡ�������һ�� C �����ַ�����Ϊ���������������е��ַ������滻Ϊ�µ��ַ�����
        �������Ĳ���Ϊ��ָ�룬���ַ��������Ϊ����Ϊ 10 �Ŀ��ַ�����

    */
    //�޸��ַ������� ��׳��
    void modify_str(const char *s)
    {
        if(!s){//Ϊ���޸�Ϊ����Ϊ10�Ŀմ�
            delete[] this->str;
            this->len = 10;
            this->str = new char[this->len];
            memset(this->str,0,10);
        }
        else{//�ǿ�
            if(this->len<strlen(s)+1){//�ռ䲻��
                //�����ռ�
                delete[] this->str;
                this->len = strlen(s)+1;
                this->str = new char[this->len];
            }
            strcpy(this->str,s);
        }
    }
    /*
        ���ڷ���ָ����С���ַ�����ռ䡣������һ�� size_t ���͵Ĳ�������ʾҪ����Ŀռ��С��
        ������һ��ָ���·�����ַ������ָ�롣

    */
    //��̬��Ա�����������ַ����ռ�
    static char *get_space(size_t n)
    {
        return new char[n];
    }

private:
    char *str;//�ַ��������׵�ַ
    size_t len;//�ռ��С
};


int main()
{
    /*
    �� main() �����У�����ͨ������ mystring::get_space(100) ��̬��Ա����������һ������Ϊ 100 ���ַ�����ռ䣬
    ����ָ�뱣���ڱ��� s �С�Ȼ��ʹ�� strcpy �������ַ��� "welcome" ���Ƶ����ַ������С�
    ���ͨ������ cout ����ĳ�Ա���� << ���ַ�����������������׼�������

    ��ע�⣬��δ������һЩ�����Ǳ�ڵĴ������磬û�ж� new ���������ص�ָ������пմ������ܵ��¿�ָ����ʴ���
    ���⣬�� modify_str() �����У��������Ĳ���Ϊ��ָ�룬���ͷ�֮ǰ������ַ�����ռ䣬
    ��û�����·����㹻�Ŀռ����洢�µ��ַ�����
    ���ܵ���Խ����ʴ�����ˣ���ʵ��ʹ������Ҫע����Щ���Ⲣ������Ӧ�Ĵ�����

    */
    char *s = mystring::get_space(100);
    strcpy(s,"welcome");

    cout<<s<<endl;

    return 0;
}
