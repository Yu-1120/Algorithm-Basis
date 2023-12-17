/*03-异常的抛出和捕获*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class A{
public:
    //不抛出任何异常
    void show()throw()
    {
        cout<<"show A"<<endl;
    }
};

//foo函数可能抛出int,double,const char *,A *类型的异常
void foo()throw(int,double,const char *,A *)
{
    srand(time(0));
    int s = rand()%5;//0 1 2 3 4

    cout<<"foo start!"<<endl;

    if(s==0){
        cout<<"正常运行!"<<endl;
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
        //排除A *型异常
        throw new A;
    }

    cout<<"foo finished!"<<endl;
}

int main()
{
    try{
        foo();
        cout<<"after foo!"<<endl;
    }catch (int e) {//捕获int异常
        cout<<"捕获到了int型异常="<<e<<endl;
    }
    catch (double e) {//捕获double异常
        cout<<"捕获到了double型异常="<<e<<endl;
    }
    catch (const char *e) {//捕获const char *异常
        cout<<"捕获到了const char *型异常="<<e<<endl;
        cout<<"无法处理,继续抛出"<<endl;
        throw e;
    }
    catch (A *e) {//捕获A *异常
        cout<<"捕获到了A *型异常"<<endl;
        e->show();
        delete e;
    }

    cout<<"app finished!"<<endl;
    return 0;
}
