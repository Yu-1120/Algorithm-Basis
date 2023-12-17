/*04-多层异常的抛出和捕获*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void C();
void B();
void A();

class Temp{
public:
    //不抛出任何异常
    void show()throw()
    {
        cout<<"show Temp"<<endl;
    }
};

//A函数可能抛出int型异常
void A()
{
    try {
        B();
    } catch (int e) {
        cout<<"A-捕获到了上级int型异常"<<endl;
        //继续抛出
        throw e;
    } catch (double e) {
        cout<<"A-捕获到了double型异常,处理"<<e<<endl;
    }
}


//B函数可能排除int,double类型异常
void B()
{
    try {
        C();
    } catch (int e) {
        cout<<"B-捕获到了上级int型异常"<<endl;
        //继续抛出
        throw e;
    } catch (double e) {
        cout<<"B-捕获到了上级double型异常"<<endl;
        //继续抛出
        throw e;
    } catch (const char *e) {
        cout<<"B-捕获到了const char *型异常,处理"<<e<<endl;
    } catch (Temp *e) {
        cout<<"B-捕获到了Temp *型异常,处理"<<endl;
        e->show();
        delete e;
    }

}

//C函数可能抛出int,double,const char *,Temp *类型的异常
void C()
{
    srand(time(0));
    int s = rand()%5;//0 1 2 3 4


    if(s==0){
        cout<<"C - 正常运行!"<<endl;
    }
    else if(s==1){
        //抛出int型异常
        throw 1;
    }
    else if(s==2){
        //抛出double型异常
        throw 3.14;
    }
    else if(s==3){
        //排除const char *型异常
        throw "起火了";
    }
    else if(s==4){
        //排除Temp *型异常
        throw new Temp;
    }
}

int main()
{
    try {
        A();
    } catch (int e) {
        cout<<"main-捕获到了int型异常,处理"<<e<<endl;
    }

    return 0;
}
