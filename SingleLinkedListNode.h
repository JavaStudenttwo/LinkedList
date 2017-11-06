#pragma once

template<typename Type> class SingleLinkedList;

template<typename Type>
class SingleLinkedListNode
{
private:
	friend typename SingleLinkedList<Type>;
	//���캯������������
	SingleLinkedListNode() :pnext(nullptr){}
	SingleLinkedListNode(const Type item, SingleLinkedListNode<Type> * next = nullptr) :data(item),pnext(next){}
	~SingleLinkedListNode() {
		pnext = nullptr;
	}
public:
	//������ڵ����Ļ�������
	Type GetData();
	//friend ostream& operator<< <Type>(ostream&, SingleLinkedListNode<Type>&);
private:
	Type data;
	SingleLinkedListNode * pnext;
};

//��ȡ����ڵ��е�����
template<typename Type> Type SingleLinkedListNode<Type>::GetData() {
	return this->data;
}

//���������
//template<typename Type> ostream& operator<<(ostream& os, SingleLinkedListNode<Type>& out) {
//	os << out.data;
//	return os;
//}