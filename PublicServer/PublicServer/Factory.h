#pragma once 
#ifndef FACTORY_PENETRATE
#define FACTORY_PENETRATE
#include "ClientTable.h"
#include "Z:\git\tool\rsocket.h"
//#include "../../../tool/rsocket.h"
class CFactory{
protected:
	static bool isInit = false;
	static CFactory *ptrFactory;
public:

	static CFactory * GetInstance();
    //生成客户机列表对象函数-CreateClientTable：
    virtual CClientTable *CreateClientTable(int type);
    //生成接收和发送数据socket-CreateSocket；
    virtual CRSocket *CreateSocket(int type);
};
#endif
