/*03-��������*/
#include <iostream>

using namespace std;

class A{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
};

class Animal{
public:
    //���캯��
    Animal(string name,int age,double weight)
    {
        cout<<"Animal()"<<endl;
        //ʹ��thisָ�����ͬ����Ա����
        this->name = name;
        this->age = age;
        this->weight = weight;
//        this->a = new A;
    }

    //��������
    ~Animal()
    {
        cout<<"~Animal()"<<endl;
        delete a;
    }

    //��Ա����
    void run()
    {
        cout<<this->name<<" run!"<<endl;
    }


    Animal *show()
    {
        cout<<this->name<<":"<<this->age<<":"<<this->weight<<endl;
        //this��Ϊ����ֵ

        /*
            thisָ���������ĳ�Ա�����͹��캯����ʹ�ã�������ǵ��øú����Ķ���(����Ķ���)�ĵ�ַ��

            �ڳ�Ա�����У�thisָ��ָ����øú����Ķ���
            �ڹ��캯���У�thisָ��ָ�����ڹ���Ķ���




        */
        return this;
    }

private:
    string name;//C++�ṩ���ַ����� =
    int age;
    double weight;
    A *a;//������
};


int main()
{
    Animal *pa = new Animal("����",5,9.4);
    pa->show();

    delete pa;
    return 0;
}
