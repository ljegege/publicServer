#include "PublicServer/ClientInfo.h"

bool CClientInfo::getId(int &rtId)
{
    rtId = id;
    return true;
}
bool CClientInfo::setId(const int &paramId)
{
    id = paramId;
    return true;
}

bool CClientInfo::getSignature(string &rtSignature)
{
    rtSignature = signature;
    return true;
}
bool CClientInfo::setSignature(const string &paramSignature)
{
    signature = paramSignature;
    return true;
}

bool CClientInfo::getState(int &rtState)
{
    rtState = state;
    return true;
}
bool CClientInfo::setState(const int &paramState)
{
    state = paramState;
    return true;
}

bool CClientInfo::getIp(string &rtIp)
{
    rtIp = ip;
    return true;
}
bool CClientInfo::setIp(const string &paramIp)
{
    ip = paramIp;
    return true;
}

bool CClientInfo::getPort(int &rtPort)
{
    rtPort = port;
    return true;
}
bool CClientInfo::setPort(const int &paramPort)
{
    port = paramPort;
    return true;
}

bool CClientInfo::getHeartbeatInterval(int &rtHeartbeat)
{
    rtHeartbeat = heartbeat;
    return true;
}

bool CClientInfo::setHeartbeatInterval(const int &paramHeartbeat)
{
    heartbeatInterval = paramHeartbeat;
    return true;
}






