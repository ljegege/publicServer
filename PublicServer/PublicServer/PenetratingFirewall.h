#pragma once 
#ifndef PENETRATE_FIREWALL_TYPE_PENETRATE
#define PENETRATE_FIREWALL_TYPE_PENETRATE

#include "ClientInfo.h"
#include "ClientTable.h"
#include "Cmd.h"
#include "Iterator.h"
#include "Type.h"
#include "Factory.h"
#include "Z:\git\tool\rsocket.h"
//#include "../../../tool/rsocket.h"
//用于表示穿透局域网服务的对象
class CPenetratingFirewall
{
public:
	CPenetratingFirewall();
	~CPenetratingFirewall();
//公有操作函数：
//	初始化函数-Init：初始化客户机列表和创建接收和发送数据的socket；
	bool Init(string initFilePath, const CClientInfo& userInfo);
//	接受请求函数-RecvCmd:
	bool RecvCmd(CCmd& cmd);
//	处理请求函数-DisposeCmd：
	bool DisposeCmd(CCmd& cmd);
//	获取客户机列表-GetClientTable:
	CClientTable * GetClientTable();
protected:
//受保护操作函数：
	//	验证客户机身份-VerifyClient:
	bool VerifyClient(CClientInfo &clientInfo) const;
	bool VerifyClient(const int &id, const string& signature) const;
//	处理注册命令-DisposeRegisterCmd；
	bool DisposeRegisterCmd(CCmd& cmd);
//	处理客户端获取自身对外IP和端口命令-DisposeGetIPandPortCmd；
	bool DisposeGetIPandPortCmd(CCmd& cmd);
//	处理客户机获取指定客户机对外的IP和端口命令-DisposeGetPeerIPandPortCmd；
	bool DisposeGetPeerIPandPortCmd(CCmd& cmd);
//	处理客户机的心跳命令-DisposeHeartbeatCmd；
	bool DisposeHeartbeatCmd(CCmd& cmd);
private:
//成员变量：
	CClientInfo selfInfo;
	//	用于接收请求和发送数据的socket；
	CRSocket* ptrSock;
//	客户机表；
	CClientTable* ptrClientTable;

};

#endif
