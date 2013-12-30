#include "ClientVectorTable.h"

//	初始化客户机列表-InitClientTable();
bool CClientVectorTable::InitClientTable()
{
	return true;	
}

//	添加客户机-AddClient
bool CClientVectorTable::AddClient(const CClientInfo & paramClientInfo)
{
	clientInfoVec.push_back(paramClientInfo);
	return false;	
}

//	删除客户机-DeleteClient
bool CClientVectorTable::DeleteClient(const int & paramId)
{
	for(vector<CClientInfo>::iterator iterClient = clientInfoVec.begin(); iterClient != clientInfoVec.end(); ++iterClient){
		int rtId;			
		if(iterClient->GetId(rtId) && rtId == paramId){
			clientInfoVec.erase(iterClient);
			return true;
		}
	}
	return false;	
}

//	查找客户机-SearchClient；
bool CClientVectorTable::SearchClient(const int & paramId, CClientInfo &rtClientInfo)
{
	for(vector<CClientInfo>::iterator iterClient = clientInfoVec.begin(); iterClient != clientInfoVec.end(); ++iterClient){
		int rtId;			
		if(iterClient->GetId(rtId) && rtId == paramId){
			rtClientInfo = *iterClient;
			return true;
		}
	}
	return false;	
}

//	或者指定位置的客户机信息-GetClientByIndex
bool CClientVectorTable::GetClientByIndex(const int & index, CClientInfo &rtClientInfo)
{
	if(index > clientInfoVec.size()){
		return false;
	}
	rtClientInfo = clientInfoVec[index - 1];
	return true;	
}	

//	获取客户机的个数-GetClientCount
bool CClientVectorTable::GetClientCount(int & rtCount)
{
	rtCount = clientInfoVec.size();
	return true;	
}

bool CClientVectorTable::Clear()
{
	clientInfoVec.clear();
	return true;
}










