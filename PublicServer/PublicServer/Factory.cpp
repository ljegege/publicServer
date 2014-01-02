#include "Factory.h"
#include "ClientVectorTable.h"
#include "Type.h"

CFactory *CFactory::GetInstance()
{
	if(isInit){
		return ptrFactory;
	}else{
		isInit = true;
		return new CFactory;
	}
}

//生成客户机列表对象函数-CreateClientTable：
CClientTable *CFactory::CreateClientTable(int type)
{
	switch(type){
		case enumVecTable: return new CClientVectorTable;
		default: return NULL;
	}
}
    
//生成接收和发送数据socket-CreateSocket；
CRSocket *CFactory::CreateSocket(int type)
{
	switch(type){
		case enumReliableSocket: return new CRSocket;
		default: return NULL;
	}
}
