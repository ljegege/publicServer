#include "PenetratingFirewall.h"
#include "ClientTable.h"
bool CPenetratingFirewall::Init(string initFilePath)
{
	return false;
}
//验证客户机身份-VerifyClient:
bool CPenetratingFirewall::VerifyClient(CClientInfo &clientInfo) const
{
	//
	//CIterator clientTableIterator(ptrClientTable);
	//for(clientTableIterator.First(); !clientTableIterator.IsDone(); clientTableIterator.Next()){
	//	clientTableIterator.GetCurrentItem(tmpClientInfo);
	//	
	//}
	int clientID;
	CClientInfo tmpClientInfo;
	clientInfo.GetId(clientID);
	string clientTableSig;
	string paramSig;

	if(!ptrClientTable->SearchClient(clientID, tmpClientInfo)){
		return false;
	}

	tmpClientInfo.GetSignature(clientTableSig);
	clientInfo.GetSignature(paramSig);
	if(clientTableSig.compare(paramSig) == 0){
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
	int type;
	cmd.GetType(type);
	switch(type){
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
	int clientId;
	CClientInfo clientInfo;
	cmd.GetId(clientId);
	if(ptrClientTable->SearchClient(clientId, clientInfo)){
		string cmdSignature, clientSignagure;
		cmd.getSignature(cmdSignature);
		clientInfo.GetSignature(clientSignagure);
		if(cmdSignature.compare(clientSignagure) == 0){

		}
	}
	return false;
}
//处理客户端获取自身对外IP和端口命令-DisposeGetIPandPortCmd
bool CPenetratingFirewall::DisposeGetIPandPortCmd(CCmd& cmd)
{
	return false;
}
//处理客户机获取指定客户机对外的IP和端口命令-DisposeGetPeerIPandPortCmd；
bool CPenetratingFirewall::DisposeGetPeerIPandPortCmd(CCmd& cmd)
{
	return false;
}
//处理客户机的心跳命令-DisposeHeartbeatCmd；
bool CPenetratingFirewall::DisposeHeartbeatCmd(CCmd& cmd)
{
	return false;
}
