#pragma once

template<typename Type> class SingleLinkedList;

template<typename Type>
class SingleLinkedListNode
{
	friend typename SingleLinkedList<Type>;
public:
	//构造函数和析构函数
	SingleLinkedListNode() :pnext(nullptr);
	SingleLinkedListNode(const Type item, SingleLinkedListNode<Type> * next = nullptr);
	~SingleLinkedListNode();
	//单链表节点对象的基本方法
	Type GetData();
	friend ostream& operator<< <Type>(ostream&, SingleLinkedListNode<Type>&);
private:
	Type data;
	SingleLinkedListNode * pnext;
};

//空参构造函数
template<typename Type>
SingleLinkedListNode::SingleLinkedListNode() :pnext(nullptr) {}

//构造函数，参数为一个单链表对象和一个节点数据
template<typename Type>
SingleLinkedListNode::SingleLinkedListNode(const Type item, SingleLinkedListNode<Type> * next = nullptr) 
	:data(item), pnext(next) {
}

//析构函数
template<typename Type>
SingleLinkedListNode::~SingleLinkedListNode() {
	pnext = nullptr;
}

//获取链表节点中的数据
template<typename Type> Type SingleLinkedListNode<Type>::GetData() {
	return this->data;
}

//重载运算符
template<typename Type> ostream& operator<<(ostream& os, SingleLinkedListNode<Type>& out) {
	os << out.data;
	return os;
}