#include "Iterator.h"

CIterator::CIterator(CClientTable * const paramClientTable)
{
	ptrClientTable = paramClientTable;
	currentIndex = -1;
}
//判断迭代是否已经结束-IsDone；
bool CIterator::IsDone()
{
	int clientCount;
	if(ptrClientTable->GetClientCount(clientCount) && clientCount == currentIndex){
		return true;
	}else{
		return false;
	}
}
//设置迭代器指向起始位置-First；
void CIterator::First()
{
	currentIndex = 0;
}
//设置迭代器指向当前元素的下一个-Next；
void CIterator::Next()
{
	++currentIndex;
}
//获取当前元素-GetCurrentItem；
bool CIterator::GetCurrentItem(CClientInfo &item)
{
	int clientCount;
	if(currentIndex == -1 || ptrClientTable->GetClientCount(clientCount) && clientCount == currentIndex){
		return false;
	}else{
		return ptrClientTable->GetClientByIndex(currentIndex, item);
	}
}














//#include "PublicServer/Iterator.h"
////判断迭代是否已经结束-IsDone；
//bool CIterator::IsDone()
//{
//	return false;
//}
////设置迭代器指向起始位置-First；
//void First()
//{
//}
////设置迭代器指向当前元素的下一个-Next；
//void Next()
//{
//}
////获取当前元素-GetCurrentItem；
//bool CIterator::GetCurrentItem(T &item);
//{
//	return false;
//}
