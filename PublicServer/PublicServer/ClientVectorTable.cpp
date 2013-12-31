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
CClientInfo * CClientVectorTable::SearchClient(const int & paramId)
{
	for(vector<CClientInfo>::iterator iterClient = clientInfoVec.begin(); iterClient != clientInfoVec.end(); ++iterClient){		
		if(iterClient->GetId == paramId){
			return iterClient;
		}
	}
	return NULL;	
}

//	或者指定位置的客户机信息-GetClientByIndex
CClientInfo * CClientVectorTable::GetClientByIndex(const int & index)
{
	if(index > clientInfoVec.size()){
		return NULL;
	}
	return &clientInfoVec[index - 1];	
}	

//	获取客户机的个数-GetClientCount
int CClientVectorTable::GetClientCount()
{
	return clientInfoVec.size();
	
}

bool CClientVectorTable::Clear()
{
	clientInfoVec.clear();
	return true;
}










