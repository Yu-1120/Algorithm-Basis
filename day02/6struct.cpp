/*06-�ṹ����������*/
#include <iostream>
#include <unistd.h>
#include <iomanip>

using namespace std;

//ʱ��ṹ��
struct Time{
    //���� ----- ��Ա����
    int hour;//ʱ
    int min;//��
    int sec;//��

    //���� ----- ��Ա����
    //����ʱ��
    void set_time(int h=23,int m=59,int s=55)
    {
        hour = h;
        min = m;
        sec = s;
    }

    //��ӡʱ��
    void print_time()
    {
        cout<<setw(2)<<setfill('0')<<hour<<":"
            <<setw(2)<<setfill('0')<<min<<":"
            <<setw(2)<<setfill('0')<<sec<<"\r\n";
    }

    //����
    void run()
    {
        sec++;
        if(sec==60){
            sec = 0;
            min++;
            if(min==60){
                min = 0;
                hour++;
                if(hour==24){
                    hour = 0;
                }
            }
        }
    }
};

int main()
{
    //ʹ�ýṹ�����͹�����󣬲���Ҫ��struct
    Time t;
      Time t1;
    //���ʳ�Ա����
    t1.hour = 14;
    t1.min = 11;
    t1.sec = 30;

    //���ʳ�Ա����
    t1.print_time();  //���ʲ���
    while(1){
        t.set_time();
        t.print_time();
        sleep(1);
        t.run();
    }

    return 0;
}
