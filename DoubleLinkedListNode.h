#pragma once

template<typename Type> class DoubleLinkedList;

template<typename Type>
class DoubleLinkedListNode
{
private:
	friend typename DoubleLinkedList<Type>;
	//构造函数和析构函数
	DoubleLinkedListNode() :pprior(nullptr), pnext(nullptr) {}
	DoubleLinkedListNode(const Type item, DoubleLinkedListNode<Type> * next = nullptr, DoubleLinkedListNode<Type> * prior = nullptr)
		:data(item), pnext(next), pprior(prior) {}
	~DoubleLinkedListNode() {
		pprior = nullptr;
		pnext = nullptr;
	}
public:
	//双链表节点对象的基本方法
	Type GetData();
private:
	Type data;
	DoubleLinkedListNode * pprior;
	DoubleLinkedListNode * pnext;
};

//获取链表节点中的数据
template<typename Type> Type DoubleLinkedListNode<Type>::GetData() {
	return this->data;
}
