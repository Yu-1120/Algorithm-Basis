/*04-����쳣���׳��Ͳ���*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void C();
void B();
void A();

class Temp{
public:
    //���׳��κ��쳣
    void show()throw()
    {
        cout<<"show Temp"<<endl;
    }
};

//A���������׳�int���쳣
void A()
{
    try {
        B();
    } catch (int e) {
        cout<<"A-�������ϼ�int���쳣"<<endl;
        //�����׳�
        throw e;
    } catch (double e) {
        cout<<"A-������double���쳣,����"<<e<<endl;
    }
}


//B���������ų�int,double�����쳣
void B()
{
    try {
        C();
    } catch (int e) {
        cout<<"B-�������ϼ�int���쳣"<<endl;
        //�����׳�
        throw e;
    } catch (double e) {
        cout<<"B-�������ϼ�double���쳣"<<endl;
        //�����׳�
        throw e;
    } catch (const char *e) {
        cout<<"B-������const char *���쳣,����"<<e<<endl;
    } catch (Temp *e) {
        cout<<"B-������Temp *���쳣,����"<<endl;
        e->show();
        delete e;
    }

}

//C���������׳�int,double,const char *,Temp *���͵��쳣
void C()
{
    srand(time(0));
    int s = rand()%5;//0 1 2 3 4


    if(s==0){
        cout<<"C - ��������!"<<endl;
    }
    else if(s==1){
        //�׳�int���쳣
        throw 1;
    }
    else if(s==2){
        //�׳�double���쳣
        throw 3.14;
    }
    else if(s==3){
        //�ų�const char *���쳣
        throw "�����";
    }
    else if(s==4){
        //�ų�Temp *���쳣
        throw new Temp;
    }
}

int main()
{
    try {
        A();
    } catch (int e) {
        cout<<"main-������int���쳣,����"<<e<<endl;
    }

    return 0;
}
