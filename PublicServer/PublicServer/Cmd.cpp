#include "PublicServer/Cmd.h"

CCmd::CCmd(int paramId = -1，string paramSignature = “”，int paramType = -1, string paramMessage = "")
:id(paramId),
 signature(paramSignature),
 type(paramType),
 message(paramMessage)
{

}

CCmd::CCmd(const CCmd& paramCmd)
{
	id = paramCmd.id;
	signature = paramCmd.signature;
	type = paramCmd.type;
	message = paramCmd.message;	
}

CCmd::CCmd & operator=(const CCmd & paramCmd)
{
	id = paramCmd.id;
	signature = paramCmd.signature;
	type = paramCmd.type;
	message = paramCmd.message;	
	return *this;
}

bool CCmd::getId(int &rtId)
{
    rtId = id;
    return true;
}
bool CCmd::setId(const int &paramId)
{
    id = paramId;
    return true;
}

bool CCmd::getSignature(string &rtSignature)
{
    rtSignature = signature;
    return true;
}

bool CCmd::setSignature(const string &paramSignature)
{
    signature = paramSignature;
    return true;
}

bool CCmd::getType(int &rtType)
{
    rtType = type;
    return true;
}
bool CCmd::setType(const int &paramType)
{
    type = paramType;
    return true;
}

bool CCmd::getMessage(string &rtMessage)
{
    rtMessage = message;
    return true;
}

bool CCmd::setMessage(const string &paramMessage)
{
    message = paramMessage;
    return true;
}


//	格式化命令-Serialize：将对象的内容格式化成char数组；
bool CCmd::Serialize(char *rtBuf, const int &len)
{
    return false;
}
//	解析命令-Parse：将char数据解析成命令对象；
bool Parse(const char *ptrData, const int &len);
{
    return false;
}














