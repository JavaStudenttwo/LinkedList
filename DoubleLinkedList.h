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
	//��˫����Ļ�����
	void MakeEmpty();
	void Insert(Type item, int i = 0);
	void Remove(int i = 0);
	void RemoveAll(Type item);
	//����˫�ı�Ļ�����Ϣ
	int length();
	Type Get(int i);
	//���Һ�����
	DoubleLinkedListNode<Type> * SequentialSearch(Type item);
	//��������
	void Print();

private:
	//�����ͷ�ڵ���˽�е�
	DoubleLinkedListNode<Type> *head;

};

//ɾ��˫����
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

//��˫�����в���Ԫ��
template <typename Type>
void DoubleLinkedList<Type>::Insert(Type item, int i = 0) {
	if (i < 0)
	{
		cout << "������һ������0����" << endl;
	}
	DoubleLinkedListNode<Type> *pmove = head;
	DoubleLinkedListNode<Type> *pnode = new DoubleLinkedListNode<Type>(item);
	for (int j = 0; j < i; j++)
	{
		pmove = pmove->pnext;
		if (pmove == head) {
			cout << "iֵԽ��,����û����ô����" << endl;
			goto END;
		}
	}

	pnode->pnext = pmove->pnext;
	pnode->pprior = pmove;
	pmove->pnext = pnode;
	pnode->pnext->pprior = pnode;

END:1 == 1;
}

//ɾ��˫�����е�Ԫ��
template <typename Type>
void DoubleLinkedList<Type>::Remove(int i = 0) {
	if (i < 0) {
		cout << "������һ������0����" << endl;
	}
	DoubleLinkedListNode<Type> *pmove = head, *pdel;
	for (int j = 0; j < i; j++) {
		pmove = pmove->pnext;
		//��pmove == head��˵��pmove�ƶ���һ�������ȣ����ƻ���������ʼ��
		if (pmove == head) {
			cout << "iֵԽ��,����û����ô����" << endl;
			break;
		}
	}

	pdel = pmove;
	pmove->pprior->pnext = pdel->pnext;
	pmove->pnext->pprior = pdel->pprior;
	Type temp = pdel->data;
	cout << "ɾ���Ľ���б����������:" << temp << endl;
	delete pdel;
}

//ɾ��˫��������Ŀ��Ԫ��ƥ���������
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

//����˫������
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

//˳�����
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

//��ӡ˫�����е���������
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
