﻿#pragma once 
#ifndef CLIENT_TABLE_PENETRATE
#define CLIENT_TALBE_PENETRATE
#include "ClientInfo.h"
//用于记录注册穿透服务的所有客户机
class CClientTable{
public:
//操作函数：
//	初始化客户机列表-InitClientTable();
	virtual bool InitClientTable() = 0;
//	添加客户机-AddClient；
	virtual bool AddClient(const CClientInfo & paramClientInfo) = 0;
//	删除客户机-DeleteClient；
	virtual bool DeleteClient(const int & paramId) = 0;
//	查找客户机-SearchClient；
	virtual CClientInfo * SearchClient(const int & paramId) = 0;
//	或者指定位置的客户机信息-GetClientByIndex；
	virtual CClientInfo * GetClientByIndex(const int & index) = 0;	
//	获取客户机的个数-GetClientCount；
	virtual int GetClientCount() = 0;	
	virtual bool Clear() = 0;
};

#endif
