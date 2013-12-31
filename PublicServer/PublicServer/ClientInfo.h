#pragma once 
#ifndef	CLIENTINF_PENETRATE
#define CLIENTINF_PENETRATE
#include <string>
using namespace std;

//用于记录客户机信息
class CClientInfo{
	//成员变量：
private:
	int id;
	//	客户机签名；
	string signature;
	//	客户机状态；
	int state;
	//	客户机IP地址；
	string ip;
	//	客户机端口；
	int port;
	//	心跳间隔；
	int heartbeatInterval;
public:
	// 构造函数
	CClientInfo(int paramId = -1,string paramSignature = "", int paramState = -1, string paramIp = "", int paramPort = -1, int paramHeartbeatInterval = -1);
	CClientInfo(const CClientInfo& clientInfo);
	CClientInfo & operator=(const CClientInfo & paramClientInfo);
	//操作函数：
	//	各个成员变量的set和get函数
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

	inline int GetState()
	{
		return state;
	}
	inline void SetState(const int &paramState)
	{
		state = paramState;
	}

	inline string GetIp()
	{
		return ip;
	}
	inline void SetIp(const string &paramIp)
	{
		ip = paramIp;
	}

	inline int GetPort()
	{
		return port;
	}
	inline void SetPort(const int &paramPort)
	{
		port = paramPort;
	}

	inline int GetHeartbeatInterval()
	{
		return heartbeatInterval;
	}
	inline void SetHeartbeatInterval(const int &paramHeartbeat)
	{
		heartbeatInterval = paramHeartbeat;
	}

};
#endif
