/*07-const�����const��Ա*/
#include <iostream>
#include <cstring>

using namespace std;

class A{
public:
    A(int n=0,int m=0):num(n),x(m){}

    void show()
    {
        //this->num = 111;
        cout<<"show()"<<endl;
    }


    void show()const//const��Ա����
    {
        this->x = 100;
        cout<<"x:"<<x<<endl;
        cout<<"show()const"<<endl;
    }

    //����const��ʲô��

    /*


    const�ؼ�������������������ʾ�ñ�����ֵ�ڳ��������ڼ䲻�ɸı䡣

    ���ڳ�Ա���������һ����������const��Ա��������ô�����Ա������ֵֻ���ڹ��캯���н��г�ʼ����

    �����ڶ�����������������У���ֵ�ǲ����޸ĵġ��Ᵽ֤�˶����״̬�Ĳ����ԣ�ͬʱҲ�ṩ��һЩ����İ�ȫ�ԡ�

    �����������У�num��Ա����������Ϊconst���������ֵֻ���ڹ��캯���г�ʼ�������Ҳ��ܱ��޸ġ�

    ��ȷ����num��Ա������ֵ��������������������б��ֲ��䡣

    ���⣬��const��Ա�����У�����ͨ��mutable�ؼ������޸ĳ�Ա������ֵ������ζ�ż�ʹ��Ա������const�ģ�

    ������Ȼ������const��Ա�������޸����������������У�x��Ա����������Ϊmutable��������ǿ�����show()const�������޸�����ֵ��

        ��const��Ա�����У����ǿ���ͨ��mutable�ؼ���������Ҫ�޸ĵĳ�Ա�������������ں����ж�������޸ġ�


        class MyClass {
        private:
            int myVar;
        public:
            MyClass(int value) : myVar(value) {}

            void modifyVar() const {
                myVar = 42; // ��const��Ա�������޸�myVar��ֵ
            }
        };

        int main() {
            MyClass obj(10);
            obj.modifyVar(); // ����const��Ա�����޸�myVar��ֵ  !!!!
            return 0;
        }





    */

private:
    const int num;//const��Ա����
    mutable int x;//������const��Ա�������޸�
};

int main()
{
    A a(10,20);
    const A b(66,88);//const����

    a.show();
    // show()

    b.show();
    //x:100
    // show()const
 /*
     outcome��
    // show()
    //x:100
    // show()const



    */



    return 0;
}
