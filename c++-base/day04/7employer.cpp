/*06-���ؼ̳�ʵ��Ա����*/
#include <iostream>
#include <cstring>

using namespace std;
/*

C++ʵ�ֶ��ؼ̳е�һ��ʾ�������ж������ĸ��ࣺObject��Person��Comp��Employer��

*/



/*
    Object�ࣺ���ǻ��࣬����һ��˽�г�Ա����p�����ڴ洢�ַ�����Ϣ��
    ����һ��Ĭ�Ϲ��캯����һ���������캯����һ������������һ����ȡpֵ�ĳ�Ա������

*/
class Object{
public:
    Object(const char *s=NULL)
    {
        cout<<"Object()"<<endl;

        if(s){
            this->p = new char[strlen(s)+1];
            strcpy(this->p, s);
        }
        else{
            this->p = new char[10];
            memset(this->p,0,10);
        }
    }

    //��������
    Object(const Object &o)
    {
        cout<<"Object(const Object &o)"<<endl;
        if(strlen(o.p)){
            this->p = new char[strlen(o.p)+1];
            strcpy(this->p, o.p);
        }
        else{//�մ�
            this->p = new char[10];
            memset(this->p,0,10);
        }
    }

    ~Object()
    {
        cout<<"~Object()"<<endl;
        delete[] this->p;
    }

    //��ȡ
    const char *get_p()
    {
        return this->p;
    }

private:
    char *p;//˵����Ϣ
};
/*

    Person�ࣺ��̳���Object�࣬������һ��˽�г�Ա����p_name�����ڴ洢������
    ����һ��Ĭ�Ϲ��캯����һ����ȡp_nameֵ�ĳ�Ա������
*/
//��̳�
class Person:virtual public Object
{
public:
    Person(const char *s=NULL,string name="xxx"):Object(s),p_name(name)
    {
        cout<<"Person()"<<endl;
    }

    //��ȡ
    string get_pname()
    {
        return this->p_name;
    }

private:
    string p_name;//����
};
/*

    Comp�ࣺҲ��̳���Object�࣬������һ��˽�г�Ա����c_name�����ڴ洢��˾����
    ����һ��Ĭ�Ϲ��캯����һ����ȡc_nameֵ�ĳ�Ա������
*/
class Comp:virtual public Object
{
public:
    Comp(const char *s=NULL,string name="xxx"):Object(s),c_name(name)
    {
        cout<<"Comp()"<<endl;
    }

    //��ȡ
    string get_cname()
    {
        return this->c_name;
    }

private:
    string c_name;//��˾��
};
/*

    Employer�ࣺͬʱ��̳���Person���Comp�࣬������һ��˽�г�Ա����salary�����ڴ洢нˮ��
    ����һ��Ĭ�Ϲ��캯����һ����ʾ������Ϣ�ĳ�Ա������

*/
//Ա����
class Employer:virtual public Person,virtual public Comp{
public:
    Employer(const char *s=NULL,string pname="xxx",string cname="xxx",double salary=1000.0):
        Object(s),Person(s,pname),Comp(s,cname),salary(salary)
    {
        cout<<"Employer()"<<endl;
    }

    void show()
    {
        cout<<this->get_pname()<<":"<<this->get_cname()<<":"<<
              this->get_p()<<":"<<this->salary<<endl;
    }

private:
    double salary;
};
/*

C++ʵ�ֶ��ؼ̳е�һ��ʾ�������ж������ĸ��ࣺObject��Person��Comp��Employer��

*/
int main()
{
    Employer ep("�廢�Ͻ�","�ŷ�","���",300000.0);
    ep.show();

    Employer ep1 = ep;
/*

        Object()
        Person()
        Comp()
        Employer()
        �ŷ�:���:�廢�Ͻ�:300000
        Object(const Object &o)
        ~Object()
        ~Object()


*/
    return 0;
}




