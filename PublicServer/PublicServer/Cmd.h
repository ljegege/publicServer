#ifndef CMD_PENETRATE
#define CMD_PENETRATE

#pragma once 
#include <string>
using namespace std;
class CCmd{
private:
	//成员变量：
	//	客户机ID；
	int id;
	//	客户机签名；
	string signature;
	//	命令类型；
	int type;
	//	命令内容；
	string message;
	string ip;
	int port;
	//操作函数：
public:
	// 构造函数
	CCmd(int id = -1, string signature = "", int type = -1, string message = "", string ip = "", int port = -1);
	CCmd(const CCmd& paramCmd);
	CCmd & operator=(const CCmd & paramCmd);
	//	各个成员变量的Get和Set函数；
	inline int GetId()
	{
		return id;
	}
	inline void SetId(const int &paramId)
	{
		id = paramId;
	}

	inline string GetSignature()
	{
		return signature;
	}
	inline void SetSignature(const string &paramSignature)
	{
		signature = paramSignature;
	}

	inline int GetType()
	{
		return type;
	}
	inline void SetType(const int &paramType)
	{
		type = paramType;
	}


	inline string GetMessage()
	{
		return message;
	}

	inline void SetMessage(const string &paramMessage)
	{
		message = paramMessage;
	}

	inline string GetIp()
	{
		return ip;
	}
	inline void SetIp(const string &paramIp)
	{
		ip = paramIp;
	}


	inline int GetPort1()
	{
		return port;
	}

	inline void SetPort1(const int &paramPort)
	{
		port = paramPort;
	}

	//	格式化命令-Serialize：将对象的内容格式化成char数组；
	bool Serialize(char *rtBuf, int &len);
	//	解析命令-Parse：将char数据解析成命令对象；
	bool Parse(const char *ptrData, const int &len);
};

#endif
