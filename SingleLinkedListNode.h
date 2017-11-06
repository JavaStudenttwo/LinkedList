#pragma once

template<typename Type> class SingleLinkedList;

template<typename Type>
class SingleLinkedListNode
{
	friend typename SingleLinkedList<Type>;
public:
	//���캯������������
	SingleLinkedListNode() :pnext(nullptr);
	SingleLinkedListNode(const Type item, SingleLinkedListNode<Type> * next = nullptr);
	~SingleLinkedListNode();
	//������ڵ����Ļ�������
	Type GetData();
	friend ostream& operator<< <Type>(ostream&, SingleLinkedListNode<Type>&);
private:
	Type data;
	SingleLinkedListNode * pnext;
};

//�ղι��캯��
template<typename Type>
SingleLinkedListNode::SingleLinkedListNode() :pnext(nullptr) {}

//���캯��������Ϊһ������������һ���ڵ�����
template<typename Type>
SingleLinkedListNode::SingleLinkedListNode(const Type item, SingleLinkedListNode<Type> * next = nullptr) 
	:data(item), pnext(next) {
}

//��������
template<typename Type>
SingleLinkedListNode::~SingleLinkedListNode() {
	pnext = nullptr;
}

//��ȡ����ڵ��е�����
template<typename Type> Type SingleLinkedListNode<Type>::GetData() {
	return this->data;
}

//���������
template<typename Type> ostream& operator<<(ostream& os, SingleLinkedListNode<Type>& out) {
	os << out.data;
	return os;
}