#include "PublicServer/ClientInfo.h"

CClientInfo::CClientInfo(int paramId = -1，string paramSignature = “”，int paramState = -1，string paramIp = “”，int paramPort = -1, int paramHeartbeatInterval = -1)
:id(paramId),
 signature(paramSignature),
 state(paramState),
 ip(paramIp),
 port(paramPort),
 heartbeatInterval(paramHeartbeatInterval)
{
		
}

CClientInfo::CClientInfo(const CClientInfo& paramClientInfo)
{
	id = paramClientInfo.id;
 	signature = paramClientInfo.signature;
 	state = paramClientInfo.state;
 	ip = paramClientInfo.ip;
 	port = paramClientInfo.port;
 	heartbeatInterval = paramClientInfo.heartbeatInterval;	
}

CClientInfo & operator=(const CClientInfo & paramClientInfo)
{
	id = paramClientInfo.id;
 	signature = paramClientInfo.signature;
 	state = paramClientInfo.state;
 	ip = paramClientInfo.ip;
 	port = paramClientInfo.port;
 	heartbeatInterval = paramClientInfo.heartbeatInterval;	
	return *this;	
}

bool CClientInfo::GetId(int &rtId)
{
    rtId = id;
    return true;
}
bool CClientInfo::SetId(const int &paramId)
{
    id = paramId;
    return true;
}

bool CClientInfo::GetSignature(string &rtSignature)
{
    rtSignature = signature;
    return true;
}
bool CClientInfo::SetSignature(const string &paramSignature)
{
    signature = paramSignature;
    return true;
}

bool CClientInfo::GetState(int &rtState)
{
    rtState = state;
    return true;
}
bool CClientInfo::SetState(const int &paramState)
{
    state = paramState;
    return true;
}

bool CClientInfo::GetIp(string &rtIp)
{
    rtIp = ip;
    return true;
}
bool CClientInfo::SetIp(const string &paramIp)
{
    ip = paramIp;
    return true;
}

bool CClientInfo::GetPort(int &rtPort)
{
    rtPort = port;
    return true;
}
bool CClientInfo::SetPort(const int &paramPort)
{
    port = paramPort;
    return true;
}

bool CClientInfo::GetHeartbeatInterval(int &rtHeartbeat)
{
    rtHeartbeat = heartbeat;
    return true;
}

bool CClientInfo::SetHeartbeatInterval(const int &paramHeartbeat)
{
    heartbeatInterval = paramHeartbeat;
    return true;
}






