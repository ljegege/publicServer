////用于遍历ClientTable的迭代器
//template <typename T>
//class CVectorIterator:public CIterator
//{
//// 构造函数
//public:
//	CVectorIterator(CClientTable * const paramClientTable);
////public操作函数：
//public:
////	判断迭代是否已经结束-IsDone；
//	virtual bool IsDone();
////	设置迭代器指向起始位置-First；
//	virtual void First();
////	设置迭代器指向当前元素的下一个-Next；
//	virtual void Next();
////	获取当前元素-GetCurrentItem；
//	virtual bool GetCurrentItem(T &item);
////私有成员变量：
//private:
////	记录当前访问到的元素位置-currentIndex；
//	int currentIndex;
////	vector<T> *ptrClientInfoVec;
//	CClientTable * ptrClientTable
//};
