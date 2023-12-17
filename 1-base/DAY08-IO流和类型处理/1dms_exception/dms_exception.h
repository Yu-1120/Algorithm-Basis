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

//服务器无响应异常
class dms_server_no_response_exception:public dms_server_exception{
public:
    dms_server_no_response_exception(string msg="server no response exception")throw();
};

//服务器资源不足异常
class dms_server_no_resource_exception:public dms_server_exception{
public:
    dms_server_no_resource_exception(string msg="server no resource exception")throw();
};

//客户端异常子类
class dms_client_exception:public dms_exception{
public:
    dms_client_exception(string msg="client exception")throw();
};

//客户端连接异常
class dms_client_no_connection_exception:public dms_client_exception{
public:
    dms_client_no_connection_exception(string msg="client no connection exception")throw();
};

//客户端数据越界异常
class dms_client_outofrange_exception:public dms_client_exception{
public:
    dms_client_outofrange_exception(string msg="client outofrange exception")throw();
};

#endif // DMS_EXCEPTION_H
