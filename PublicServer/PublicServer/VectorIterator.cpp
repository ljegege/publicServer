#include "PublicServer/VectorIterator.h"

CVectorIterator::CVectorIterator(CClientTable * const paramClientTable)
{
	ptrClientTable = paramClientTable;
	currentIndex = -1;
}
//判断迭代是否已经结束-IsDone；
bool CVectorIterator::IsDone()
{
	int clientCount;
	if(ptrClientTable->GetClientCount(clientCount) && clientCount == currentIndex){
		return true;
	}else{
		return false;
	}
}
//设置迭代器指向起始位置-First；
virtual void First()
{
	currentIndex = 0;
}
//设置迭代器指向当前元素的下一个-Next；
virtual void Next()
{
	++currentIndex;
}
//获取当前元素-GetCurrentItem；
bool CVectorIterator::GetCurrentItem(T &item);
{
	int clientCount;
	if(currentIndex == -1 || ptrClientTable->GetClientCount(clientCount) && clientCount == currentIndex){
		return false;
	}else{
		return ptrClientTable->GetClientByIndex(currentIndex, item);
	}
}
