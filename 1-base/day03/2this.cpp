/*02-thisָ��*/
#include <iostream>
#include <cstring>

using namespace std;

//���ǰ������
class Animal;

//��������
void show_Animal(Animal &an);

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
    }

    //��Ա����
    void run()
    {
        cout<<this->name<<" run!"<<endl;
    }


    Animal *show()
    {
        //this��Ϊ��������
        show_Animal(*this);
        /*
            thisָ���������ĳ�Ա�����͹��캯����ʹ�ã��������ǵ��øú����Ķ���(����Ķ���)�ĵ�ַ��

            �ڳ�Ա�����У�thisָ��ָ����øú����Ķ���
            �ڹ��캯���У�thisָ��ָ�����ڹ���Ķ���




        */
        cout<<this->name<<":"<<this->age<<":"<<this->weight<<endl;
        //this��Ϊ����ֵ
        return this;
    }

private:
    string name;//C++�ṩ���ַ����� =
    int age;
    double weight;
};

void show_Animal(Animal &an)
{
    cout<<"show_Animal"<<endl;
    an.run();
}

int main()
{
    //Animal an("Ԫ��",4,11.2);
    //an.run();

    Animal *pa = new Animal("����",5,9.4);
    pa->show()->show()->show()->run();
// pa->show() ��������this�����Ķ���
//    Animal()
//    show_Animal
//    ���� run!
//    ����:5:9.4
//    show_Animal
//    ���� run!
//    ����:5:9.4
//    show_Animal
//    ���� run!
//    ����:5:9.4
//**********************
//    ���� run!


//    pa->show();
//    Animal()
//    show_Animal
//    ���� run!
//    ����:5:9.4




    delete pa;
    return 0;
}