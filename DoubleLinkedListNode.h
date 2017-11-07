#pragma once

template<typename Type> class DoubleLinkedList;

template<typename Type>
class DoubleLinkedListNode
{
private:
	friend typename DoubleLinkedList<Type>;
	//���캯������������
	DoubleLinkedListNode() :pprior(nullptr), pnext(nullptr) {}
	DoubleLinkedListNode(const Type item, DoubleLinkedListNode<Type> * next = nullptr, DoubleLinkedListNode<Type> * prior = nullptr)
		:data(item), pnext(next), pprior(prior) {}
	~DoubleLinkedListNode() {
		pprior = nullptr;
		pnext = nullptr;
	}
public:
	//˫����ڵ����Ļ�������
	Type GetData();
private:
	Type data;
	DoubleLinkedListNode * pprior;
	DoubleLinkedListNode * pnext;
};

//��ȡ����ڵ��е�����
template<typename Type> Type DoubleLinkedListNode<Type>::GetData() {
	return this->data;
}
