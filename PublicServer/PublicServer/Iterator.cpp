#include "PublicServer/Iterator.h"
//判断迭代是否已经结束-IsDone；
bool CIterator::IsDone()
{
	return false;
}
//设置迭代器指向起始位置-First；
virtual void First()
{
}
//设置迭代器指向当前元素的下一个-Next；
virtual void Next()
{
}
//获取当前元素-GetCurrentItem；
bool CIterator::GetCurrentItem(T &item);
{
	return false;
}
