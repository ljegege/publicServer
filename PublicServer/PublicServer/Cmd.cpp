#include "Cmd.h"
CCmd::CCmd(int paramId, string paramSignature, int paramType, string paramMessage, string paramIp, int paramPort)
:id(paramId),
 signature(paramSignature),
 type(paramType),
 message(paramMessage),
 ip(paramIp),
 port(paramPort)
{

}

CCmd::CCmd(const CCmd& paramCmd)
{
	id = paramCmd.id;
	signature = paramCmd.signature;
	type = paramCmd.type;
	message = paramCmd.message;	
}

CCmd & CCmd::operator=(const CCmd & paramCmd)
{
	id = paramCmd.id;
	signature = paramCmd.signature;
	type = paramCmd.type;
	message = paramCmd.message;	
	return *this;
}

//	格式化命令-Serialize：将对象的内容格式化成char数组
bool CCmd::Serialize(char *rtBuf, int &len)
{
	memcpy(rtBuf, 0, len);

	int serializeLen = 0;
	int dataLen = sizeof(id);
	
	if(len < serializeLen + dataLen){
		return false;
	}
	memcpy(rtBuf, &id, dataLen);
	serializeLen += dataLen;

	dataLen = signature.size();
	if(len < serializeLen + dataLen  + sizeof(int)){
		return false;
	}
	memcpy(rtBuf + serializeLen, &dataLen,  + sizeof(int));	
	serializeLen += sizeof(int);

	memcpy(rtBuf + serializeLen, signature.c_str(),  + dataLen);	
	serializeLen += dataLen;

	dataLen = sizeof(type);
	if(len < serializeLen + dataLen){
		return false;
	}
	memcpy(rtBuf + serializeLen, &type, dataLen);
	serializeLen += dataLen;

	dataLen = message.size();
	if(len < serializeLen + dataLen + sizeof(int)){
		return false;
	}
	memcpy(rtBuf + serializeLen, &dataLen,  + sizeof(int));	
	serializeLen += sizeof(int);

	memcpy(rtBuf + serializeLen, message.c_str(), dataLen);
	len = serializeLen + dataLen;

    return true;
}

//	解析命令-Parse：将char数据解析成命令对象
bool CCmd::Parse(const char *ptrData, const int &len)
{
	int parseLen = 0;
	int dataLen = 0;
	id = *(int *)ptrData;
	parseLen += sizeof(int);

	dataLen = *(int *)(ptrData + parseLen);
	parseLen += sizeof(int);

	signature.clear();
	signature.append(ptrData + parseLen, dataLen);
	parseLen += dataLen;

	type = *(int *)(ptrData + parseLen);
	parseLen += sizeof(int);

	dataLen = *(int *)(ptrData + parseLen);
	message.clear();
	message.append(ptrData + parseLen, dataLen);
	
    return true;
}






//
//bool CCmd::getId(int &rtId)
//{
//    rtId = id;
//    return true;
//}
//bool CCmd::setId(const int &paramId)
//{
//    id = paramId;
//    return true;
//}
//
//bool CCmd::getSignature(string &rtSignature)
//{
//    rtSignature = signature;
//    return true;
//}
//
//bool CCmd::setSignature(const string &paramSignature)
//{
//    signature = paramSignature;
//    return true;
//}
//
//bool CCmd::getType(int &rtType)
//{
//    rtType = type;
//    return true;
//}
//bool CCmd::setType(const int &paramType)
//{
//    type = paramType;
//    return true;
//}
//
//bool CCmd::getMessage(string &rtMessage)
//{
//    rtMessage = message;
//    return true;
//}
//
//bool CCmd::setMessage(const string &paramMessage)
//{
//    message = paramMessage;
//    return true;
//}







