#pragma once

template<typename Type> class SingleLinkedList;

template<typename Type>
class SingleLinkedListNode
{
private:
	friend typename SingleLinkedList<Type>;
	//构造函数和析构函数
	SingleLinkedListNode() :pnext(nullptr){}
	SingleLinkedListNode(const Type item, SingleLinkedListNode<Type> * next = nullptr) :data(item),pnext(next){}
	~SingleLinkedListNode() {
		pnext = nullptr;
	}
public:
	//单链表节点对象的基本方法
	Type GetData();
	//friend ostream& operator<< <Type>(ostream&, SingleLinkedListNode<Type>&);
private:
	Type data;
	SingleLinkedListNode * pnext;
};

//获取链表节点中的数据
template<typename Type> Type SingleLinkedListNode<Type>::GetData() {
	return this->data;
}

//重载运算符
//template<typename Type> ostream& operator<<(ostream& os, SingleLinkedListNode<Type>& out) {
//	os << out.data;
//	return os;
//}