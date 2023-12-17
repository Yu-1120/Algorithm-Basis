#include "dms_exception.h"

dms_exception::dms_exception(string msg)throw():description(msg)
{

}

string dms_exception::what()throw()
{
    return this->description;
}

dms_server_exception::dms_server_exception(string msg)throw():dms_exception(msg)
{

}

dms_server_no_response_exception::dms_server_no_response_exception(string msg)throw():dms_server_exception(msg)
{

}

dms_server_no_resource_exception::dms_server_no_resource_exception(string msg)throw():dms_server_exception(msg)
{

}

dms_client_exception::dms_client_exception(string msg)throw():dms_exception(msg)
{

}

dms_client_no_connection_exception::dms_client_no_connection_exception(string msg)throw():dms_client_exception(msg)
{

}

dms_client_outofrange_exception::dms_client_outofrange_exception(string msg)throw():dms_client_exception(msg)
{

}
