#pragma once

template <typename Type>
class SingleLinkedList
{
public:

	SingleLinkedList();
	~SingleLinkedList();
	//对单链表的基本操作
	void MakeEmpty();
	void Insert(Tyep item, int n = 0);
	void Remove(int n = 0);
	//返回单聊表的基本信息
	int length();
	Type Get(int n);
	//查找和排序
	SingleLinkedList<Type> * Search(Type item,int n = 0);
	//基础功能
	void Print();

private:
	SingleLinkedListNode<Type> *head;

};

template <typename Type>
SingleLinkedList::SingleLinkedList()
{
}

template <typename Type>
SingleLinkedList::~SingleLinkedList()
{
}