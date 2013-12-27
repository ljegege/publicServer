#include "PublicServer/Cmd.h"

bool Cmd::getId(int &rtId)
{
    rtId = id;
    return true;
}
bool Cmd::setId(const int &paramId)
{
    id = paramId;
    return true;
}

bool Cmd::getSignature(string &rtSignature)
{
    rtSignature = signature;
    return true;
}

bool Cmd::setSignature(const string &paramSignature)
{
    signature = paramSignature;
    return true;
}

bool Cmd::getType(int &rtType)
{
    rtType = type;
    return true;
}
bool Cmd::setType(const int &paramType)
{
    type = paramType;
    return true;
}

bool Cmd::getMessage(string &rtMessage)
{
    rtMessage = message;
    return true;
}

bool Cmd::setMessage(const string &paramMessage)
{
    message = paramMessage;
    return true;
}


//	格式化命令-Serialize：将对象的内容格式化成char数组；
bool Cmd::Serialize(char *rtBuf, const int &len)
{
    return false;
}
//	解析命令-Parse：将char数据解析成命令对象；
bool Parse(const char *ptrData, const int &len);
{
    return false;
}














