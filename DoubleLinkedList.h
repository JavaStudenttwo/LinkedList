#pragma once
#include "DoubleLinkedListNode.h"

template <typename Type>
class DoubleLinkedList
{
public:

	DoubleLinkedList() :head(new DoubleLinkedListNode<Type>()) {
		head->pprior = head;
		head->pnext = head;
	}
	~DoubleLinkedList() {
		MakeEmpty();
		delete head;
	}
	//对双链表的基本操
	void MakeEmpty();
	void Insert(Type item, int i = 0);
	void Remove(int i = 0);
	void RemoveAll(Type item);
	//返回双聊表的基本信息
	int length();
	Type Get(int i);
	//查找和排序
	DoubleLinkedListNode<Type> * SequentialSearch(Type item);
	//基础功能
	void Print();

private:
	//链表的头节点是私有的
	DoubleLinkedListNode<Type> *head;

};

//删除双链表
template <typename Type>
void DoubleLinkedList<Type>::MakeEmpty() {
	DoubleLinkedListNode<Type> *pdel;
	DoubleLinkedListNode<Type> *pmove = head->pnext;
	while (pmove != nullptr)
	{
		pdel = pmove;
		pmove = pdel->pnext;
		delete pdel;
	}
	head->pnext = head;
	head->pprior = head;
}

//向双链表中插入元素
template <typename Type>
void DoubleLinkedList<Type>::Insert(Type item, int i = 0) {
	if (i < 0)
	{
		cout << "请输入一个大于0的数" << endl;
	}
	DoubleLinkedListNode<Type> *pmove = head;
	DoubleLinkedListNode<Type> *pnode = new DoubleLinkedListNode<Type>(item);
	for (int j = 0; j < i; j++)
	{
		pmove = pmove->pnext;
		if (pmove == head) {
			cout << "i值越界,链表没有那么长！" << endl;
			goto END;
		}
	}

	pnode->pnext = pmove->pnext;
	pnode->pprior = pmove;
	pmove->pnext = pnode;
	pnode->pnext->pprior = pnode;

END:1 == 1;
}

//删除双链表中的元素
template <typename Type>
void DoubleLinkedList<Type>::Remove(int i = 0) {
	if (i < 0) {
		cout << "请输入一个大于0的数" << endl;
	}
	DoubleLinkedListNode<Type> *pmove = head, *pdel;
	for (int j = 0; j < i; j++) {
		pmove = pmove->pnext;
		//当pmove == head，说明pmove移动了一个链表长度，又绕回了链表起始点
		if (pmove == head) {
			cout << "i值越界,链表没有那么长！" << endl;
			break;
		}
	}

	pdel = pmove;
	pmove->pprior->pnext = pdel->pnext;
	pmove->pnext->pprior = pdel->pprior;
	Type temp = pdel->data;
	cout << "删除的结点中保存的数据是:" << temp << endl;
	delete pdel;
}

//删除双链表中与目标元素匹配的所有项
template <typename Type>
void DoubleLinkedList<Type>::RemoveAll(Type item) {
	DoubleLinkedListNode<Type> *pmove = head;
	DoubleLinkedListNode<Type> *pdel = head->pnext;
	while (pdel != nullptr)
	{
		if (pdel->data == item) {
			pmove->pnext = pdel->pnext;
			delete pdel;
			pdel = pmove->pnext;
			continue;
		}
		pmove = pmove->pnext;
		pdel = pdel->pnext;
	}
}

//返回双链表长度
template<typename Type>
int DoubleLinkedList<Type>::length() {
	DoubleLinkedListNode<Type> *_pprior = head->pprior, *_pprior = head->pnext;
	int count = 0;
	while (1)
	{
		if (_pprior->pnext == _pnext)
		{
			break;
		}
		if (_pprior == _pnext && _pprior != head)
		{
			count++;
			break;
		}
		count += 2;
		_pprior = _pprior->pprior;
		_pnext = _pnext->pnext;
	}
	return count;
}

//顺序查找
template<typename Type>
DoubleLinkedListNode<Type> * DoubleLinkedList<Type>::SequentialSearch(Type item) {

	DoubleLinkedListNode<Type> *pmove = head->pnext;
	for (int i = 0; i < n&&pmove; i++)
	{
		pmove = pmove->pnext;
	}
	if (pmove == nullptr)
	{
		cout << "" << endl;
	}
}

//打印双链表中的所有数据
template<typename Type>
void DoubleLinkedList<Type>::Print() {

	DoubleLinkedListNode<Type> *pmove = head->pnext;
	cout << endl << "head";
	while (pmove != head)
	{
		cout << "->" << pmove->data;
		pmove = pmove->pnext;
	}
	cout << "-over" << endl;
}
