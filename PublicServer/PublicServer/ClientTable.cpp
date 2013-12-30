#include "ClientTable.h"

//	初始化客户机列表-InitClientTable();
bool CClientTable::InitClientTable()
{
	return false;
}
//	添加客户机-AddClient；
bool CClientTable::AddClient(const CClientInfo & paramClientInfo)
{
	return false;
}
//	删除客户机-DeleteClient；
bool CClientTable::DeleteClient(const int & paramId)
{
	return false;
}
//	查找客户机-SearchClient；
bool CClientTable::SearchClient(const int & paramId, CClientInfo &rtClientInfo)
{
	return false;
}
//	或者指定位置的客户机信息-GetClientByIndex；
bool CClientTable::GetClientByIndex(const int & index, CClientInfo &rtClientInfo)
{
	return false;
}	
//	获取客户机的个数-GetClientCount；
bool CClientTable::GetClientCount(int & rtCount)
{
	return false;
}	
bool CClientTable::Clear()
{
	return false;
}