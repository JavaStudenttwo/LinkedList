#include"SingleLinkedListNode.h"

template <typename Type>
class SingleLinkedList
{
public:

	SingleLinkedList() :head(new SingleLinkedListNode<Type>()){}
	~SingleLinkedList() {
		MakeEmpty();
		delete head;
	}
	//对单链表的基本操
	void MakeEmpty();
	void Insert(Type item, int i = 0);
	void Remove(int i = 0);
	//返回单聊表的基本信息
	int length();
	Type Get(int i);
	//查找和排序
	SingleLinkedList<Type> * SequentialSearch(Type item);
	//基础功能
	void Print();

private:
	//链表的节点是私有的
	SingleLinkedListNode<Type> *head;

};

//删除单链表
template <typename Type>
void SingleLinkedList<Type>::MakeEmpty() {
	SingleLinkedListNode<Type> *pdel;
	while (head->pnext != nullptr)
	{
		pdel = head->pnext;
		head->pnext = pdel->pnext;
		delete pdel;
	}
}

//向单链表中插入元素
template <typename Type>
void SingleLinkedList<Type>::Insert(Type item, int i = 0) {
	if (i < 0)
	{
		cout << "请输入一个大于0的数" << endl;
	}
	SingleLinkedListNode<Type> *pmove = head;
	SingleLinkedListNode<Type> *pnode = new SingleLinkedListNode<Type>(item);
	for (int j = 0; j < i&&pmove; j++)
	{
		pmove = pmove->pnext;
	}
	if (pmove == nullptr)
	{
		cout << "数据插入位置错误，单链表没那么长！" << endl;
	}
	pnode->pnext = pmove->pnext;
	pmove->pnext = pnode;
}

//删除单链表中的元素
template <typename Type>
void SingleLinkedList<Type>::Remove(int i = 0) {
	if (i < 0)
	{
		cout << "请输入一个大于0的数" << endl;
	}
	SingleLinkedListNode<Type> *pmove = head, *pdel;
	for (int j = 0; j < i&&pmove->pnext; j++)
	{
		pmove = pmove->pnext;
	}
	if (pmove->pnext == nullptr)
	{
		cout << "" << endl;
	}
	pdel = pmove->pnext;
	pmove->pnext = pdel->pnext;
	delete pdel;
}


//返回单链表长度
template<typename Type>
int SingleLinkedList<Type>::length() {
	SingleLinkedListNode<Type> *pmove = head->pnext;
	int count = 0;
	while (pmove != nullptr) {
		pmove = pmove->pnext;
		count++;
	}
	return count;
}

//顺序查找
template<typename Type>
SingleLinkedList<Type> * SingleLinkedList<Type>::SequentialSearch(Type item) {
	
	SingleLinkedListNode<Type> *pmove = head->pnext;
	for (int i = 0; i < n&&pmove; i++)
	{
		pmove = pmove->pnext;
	}
	if (pmove == nullptr)
	{
		cout << "" << endl;
	}
}

//打印单链表中的所有数据
template<typename Type>
void SingleLinkedList<Type>::Print() {

	SingleLinkedListNode<Type> *pmove = head->pnext;
	cout << endl << "head";
	while (pmove != nullptr)
	{
		cout << "->" << pmove->data;
		pmove = pmove->pnext;
	}
	cout << "-over" << endl;
}
