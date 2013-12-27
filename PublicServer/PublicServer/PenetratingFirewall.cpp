bool Init()
{
	return false;
}
//验证客户机身份-VerifyClient:
bool VerifyClient(const CClientInfo &clientInfo)
{
	return false;
}
//接受请求函数-RecvCmd:
bool RecvCmd(CClientInfo &clientInfo)
{
	return false;
}
//处理请求函数-DisposeCmd：
bool DisposeCmd(CClientInfo &clientInfo)
{
	return false;
}
//获取客户机列表-GetClientTable:
CClientInfo & GetClientTable()
{
	return false;
}

//处理注册命令-DisposeRegisterCmd；
bool DisposeRegisterCmd(const CCmd& cmd)
{
	return false;
}
//处理客户端获取自身对外IP和端口命令-DisposeGetIPandPortCmd
bool DisposeGetIPandPortCmd(const CCmd& cmd)
{
	return false;
}
//处理客户机获取指定客户机对外的IP和端口命令-DisposeGetPeerIPandPortCmd；
bool DisposeGetPeerIPandPortCmd(const CCmd& cmd)
{
	return false;
}
//处理客户机的心跳命令-DisposeHeartbeatCmd；
bool DisposeHeartbeatCmd(const CCmd& cmd)
{
	return false;
}
