#pragma once

template <typename Type>
class SingleLinkedList
{
public:

	SingleLinkedList();
	~SingleLinkedList();
	//�Ե�����Ļ�������
	void MakeEmpty();
	void Insert(Tyep item, int n = 0);
	void Remove(int n = 0);
	//���ص��ı�Ļ�����Ϣ
	int length();
	Type Get(int n);
	//���Һ�����
	SingleLinkedList<Type> * Search(Type item,int n = 0);
	//��������
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