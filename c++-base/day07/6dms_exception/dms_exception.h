#ifndef DMS_EXCEPTION_H
#define DMS_EXCEPTION_H

#include <string>
using namespace std;

//异常的基类
class dms_exception{
public:
    dms_exception(string msd="dms exception")throw();
    //声明what方法
    virtual string what()throw();

private:
    string description;
};

//服务器异常子类
class dms_server_exception:public dms_exception{
public:
    dms_server_exception(string msg="server exception")throw();
};

//客户端异常子类
class dms_client_exception:public dms_exception{
public:
    dms_client_exception(string msg="client exception")throw();
};

#endif // DMS_EXCEPTION_H
