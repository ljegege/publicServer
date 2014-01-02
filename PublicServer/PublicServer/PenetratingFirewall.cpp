#include "PenetratingFirewall.h"
#include "ClientTable.h"
#include <sstream>
#include <fstream>
using namespace std;

CPenetratingFirewall::CPenetratingFirewall()
{
}

CPenetratingFirewall::~CPenetratingFirewall()
{
}

bool CPenetratingFirewall::Init(string initFilePath, const CClientInfo& userInfo)
{
	CClientInfo clientInfo;
	int id;
	string signature;
	ifstream input(initFilePath);

	selfInfo = userInfo;
	CFactory *ptrFactory = CFactory::GetInstance();
	ptrClientTable = ptrFactory->CreateClientTable(enumVecTable);
	ptrSock = ptrFactory->CreateSocket(enumReliableSocket);


	clientInfo.SetState(enumOffLine);	
	while(input>>id>>signature){
		clientInfo.SetId(id);
		clientInfo.SetSignature(signature);		
		ptrClientTable->AddClient(clientInfo);
	}

	ptrSock->Create(SOCK_DGRAM);
	ptrSock->Bind(selfInfo.GetIp(), selfInfo.GetPort1());

	return false;
}
//验证客户机身份-VerifyClient:
bool CPenetratingFirewall::VerifyClient(CClientInfo &clientInfo) const
{
	return 	VerifyClient(clientInfo.GetId(), clientInfo.GetSignature());
}

bool CPenetratingFirewall::VerifyClient(const int &id, const string& signature) const
{
	CClientInfo *ptrClientInfo;
	if(!(ptrClientInfo = ptrClientTable->SearchClient(id))){
		return false;
	}
	if(signature.compare(ptrClientInfo->GetSignature()) == 0){
		return true;
	}else {
		return false;
	}
}

//接受请求函数-RecvCmd:
bool CPenetratingFirewall::RecvCmd(CCmd& cmd)
{
	char buf[maxCmdLen];
	int bufLen = maxCmdLen;
	string ip;
	int port;
	if(ptrSock->Recvfrom(buf, bufLen, &ip, &port) > 0){
		cmd.SetIp(ip);
		cmd.SetPort1(port);
		return cmd.Parse(buf, bufLen);
	}else{
		return false;
	}
}
//处理请求函数-DisposeCmd：
bool CPenetratingFirewall::DisposeCmd(CCmd& cmd)
{
	switch(cmd.GetType()){
	case enumRegisterCmd:
		{
			return DisposeRegisterCmd(cmd);	 
		}
	case enumIpPort:
		{
			return DisposeGetIPandPortCmd(cmd);
		}
	case enumPeerIpPort:
		{
			return DisposeGetPeerIPandPortCmd(cmd);
		}
	default:
		{
			return false;
		}
	}
}
//获取客户机列表-GetClientTable:
CClientTable * CPenetratingFirewall::GetClientTable()
{
	return ptrClientTable;
}

//处理注册命令-DisposeRegisterCmd；
bool CPenetratingFirewall::DisposeRegisterCmd(CCmd& cmd)
{
	CClientInfo *ptrClientInfo;
	if((ptrClientInfo = ptrClientTable->SearchClient(cmd.GetId()))){
		if(cmd.GetSignature().compare(ptrClientInfo->GetSignature()) == 0){
			// 更新客户机信息
			ptrClientInfo->SetIp(cmd.GetIp());
			ptrClientInfo->SetPort1(cmd.GetPort1());
			ptrClientInfo->SetState(enumOnline);
			// 填充用户返回给客户机的命令消息
			cmd.SetType(enumRegisterCmdReply);
			cmd.SetId(selfInfo.GetId());
			cmd.SetSignature(selfInfo.GetSignature());			
			
			ostringstream  ostring;
			ostring<<cmd.GetPort1();
			string tmp = cmd.GetIp() + "|" + ostring.str();
			cmd.SetMessage(tmp);

			// 将消息发送给客户机
			char buf[maxCmdLen];
			int len = maxCmdLen;
			if(cmd.Serialize(buf, len)){
				if(ptrSock->Sendto(buf, len, cmd.GetIp(), cmd.GetPort1()) < 0){
					return false;
				}else{
					return true;
				}
			}
		}
	}
	return false;
}
//处理客户端获取自身对外IP和端口命令-DisposeGetIPandPortCmd
bool CPenetratingFirewall::DisposeGetIPandPortCmd(CCmd& cmd)
{
	return DisposeRegisterCmd(cmd);
}
//处理客户机获取指定客户机对外的IP和端口命令-DisposeGetPeerIPandPortCmd；
bool CPenetratingFirewall::DisposeGetPeerIPandPortCmd(CCmd& cmd)
{
	CClientInfo *ptrClientInfo;
	if((ptrClientInfo = ptrClientTable->SearchClient(cmd.GetId()))){
		if(cmd.GetSignature().compare(ptrClientInfo->GetSignature()) == 0){
			// 更新客户机信息
			ptrClientInfo->SetIp(cmd.GetIp());
			ptrClientInfo->SetPort1(cmd.GetPort1());
			ptrClientInfo->SetState(enumOnline);

			istringstream istring(cmd.GetMessage());
			int peerId;
			istring >> peerId;
			if((ptrClientInfo = ptrClientTable->SearchClient(peerId))){
				// 填充用户返回给客户机的命令消息
				cmd.SetType(enumRegisterCmdReply);
				cmd.SetId(selfInfo.GetId());
				cmd.SetSignature(selfInfo.GetSignature());	

				ostringstream  ostring;
				ostring<<ptrClientInfo->GetPort1();
				string tmp = ptrClientInfo->GetIp() + "|" + ostring.str();
				cmd.SetMessage(tmp);

				// 将消息发送给客户机
				char buf[maxCmdLen];
				int len = maxCmdLen;
				if(cmd.Serialize(buf, len)){
					if(ptrSock->Sendto(buf, len, cmd.GetIp(), cmd.GetPort1()) < 0){
						return false;
					}else{
						return true;
					}
				}
			}
		}
	}
	return false;
}
//处理客户机的心跳命令-DisposeHeartbeatCmd；
bool CPenetratingFirewall::DisposeHeartbeatCmd(CCmd& cmd)
{
	return false;
}
