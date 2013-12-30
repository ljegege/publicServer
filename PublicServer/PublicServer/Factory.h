#pragma once 
#ifndef FACTORY_PENETRATE
#define FACTORY_PENETRATE
#include "ClientTable.h"
#include "../../../tool/rsocket.h"
class CFactory{
public:
    //生成客户机列表对象函数-CreateClientTable：
    virtual CClientTable *CreateClientTable(int type);
    //生成接收和发送数据socket-CreateSocket；
    virtual CRSocket *CreateSocket(int type);
};
#endif
