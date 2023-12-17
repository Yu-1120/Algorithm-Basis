#include <iostream>
#include <cstdlib>
#include <ctime>

#include "dms_exception.h"

using namespace std;

//dms系统发送数据接口 ------ 服务器异常 客户端异常 ...
void send_data()
{
    srand(time(0));
    int r = rand()%4;

    if(r==0){
        cout<<"发送成功"<<endl;
    }
    else if(r==1){//服务器异常
        throw dms_server_exception("dms服务器异常");
    }
    else if(r==2){//客户端异常
        throw dms_client_exception("dms客户端异常");
    }
    else if(r==3){//其他异常
        throw dms_exception("dms其他异常");
    }

}

int main()
{
    //执行可能抛出异常的代码
    try {
        send_data();
    }  catch (dms_server_exception &e) {
        cout<<"服务器异常"<<endl;
        cout<<e.what()<<endl;
    } catch (dms_client_exception &e) {
        cout<<"客户端异常"<<endl;
        cout<<e.what()<<endl;
    } catch (dms_exception &e) {
        cout<<"其他异常"<<endl;
        cout<<e.what()<<endl;
    }

    return 0;
}
