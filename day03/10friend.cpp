/*09-�ַ�����ľ�̬����*/
#include <iostream>
#include <cstring>

using namespace std;
/*


*/
class A{
public:
    int x;
      int z;
protected:
    int y;
//private:


    //��Ԫ����������
    friend void setA(A &a);
    //��Ԫ�������
    friend class B;
};
/*


*/
class B{
public:
    void show()
    {
        cout<<a.x<<":"<<a.y<<":"<<a.z<<endl;
    }

private:
    A a;
};


void setA(A &a)
{
    a.x = 10;
    a.y = 20;
    a.z = 30;
}
/*
    ��δ���չʾ��һ����ΪA���࣬���а���������˽�г�Ա����x��y��z��

    ����������������Ԫ����setA()��B���show()������

    ���������У����ȴ�����һ��A��Ķ���a��Ȼ���������Ԫ����setA()������a�ĳ�Ա������ֵ��

    ��������������һ��B��Ķ���b��������������show()���������a����ĳ�Ա������ֵ��

    ���ݴ�����߼���a�����x��y��z��Ա������ֵ�ֱ�����Ϊ10��20��30��

    ���b�����show()���������a����ĳ�Ա������ֵ��

*/
int main()
{
    A a;
    setA(a);
    B b;
    b.show();
/*
����е����

*/
    return 0;
}
