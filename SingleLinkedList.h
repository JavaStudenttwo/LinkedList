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
	//�Ե�����Ļ�����
	void MakeEmpty();
	void Insert(Type item, int i = 0);
	void Remove(int i = 0);
	//���ص��ı�Ļ�����Ϣ
	int length();
	Type Get(int i);
	//���Һ�����
	SingleLinkedList<Type> * SequentialSearch(Type item);
	//��������
	void Print();

private:
	//����Ľڵ���˽�е�
	SingleLinkedListNode<Type> *head;

};

//ɾ��������
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

//�������в���Ԫ��
template <typename Type>
void SingleLinkedList<Type>::Insert(Type item, int i = 0) {
	if (i < 0)
	{
		cout << "������һ������0����" << endl;
	}
	SingleLinkedListNode<Type> *pmove = head;
	SingleLinkedListNode<Type> *pnode = new SingleLinkedListNode<Type>(item);
	for (int j = 0; j < i&&pmove; j++)
	{
		pmove = pmove->pnext;
	}
	if (pmove == nullptr)
	{
		cout << "���ݲ���λ�ô��󣬵�����û��ô����" << endl;
	}
	pnode->pnext = pmove->pnext;
	pmove->pnext = pnode;
}

//ɾ���������е�Ԫ��
template <typename Type>
void SingleLinkedList<Type>::Remove(int i = 0) {
	if (i < 0)
	{
		cout << "������һ������0����" << endl;
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


//���ص�������
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

//˳�����
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

//��ӡ�������е���������
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
