#include "LinkedList.h"

void init(node * phead)
{
	phead->pNext = NULL;
	phead->data = 0;
}

node * addback(node * phead ,int data) {

	node * pnew = malloc(sizeof(node));
	//ʹ���½ڵ��¼����
	pnew->data = data;
	pnew->pNext = NULL;
	//���½ڵ���ӽ�������
	//1.��ͷָ��Ϊ�գ�������Ϊ�գ�ֱ�ӽ��½�����ַ��ֵ��ͷָ��
	if (phead == NULL)
	{
		phead = pnew;
		return phead;
	}
	else
	{
		//2.��ͷָ�벻Ϊ�գ���˵���������Ѿ��������ݣ���������ȡ�����һ�����ĵ�ַ�������½ڵ�ĵ�ַ����
		//����ͷ���
		node * ptemp = phead;
		//��������,ȡ�����һ�����ĵ�ַ
		while (ptemp->pNext != NULL) {
			ptemp = ptemp->pNext;
		}
		//���½ڵ�ĵ�ַ����
		ptemp->pNext = pnew;

	}
	return phead;

}

node * addhead(node * phead,int data) {

	node * pnew = malloc(sizeof(node));
	//ʹ���½ڵ��¼����
	pnew->data = data;
	pnew->pNext = NULL;
	//���½ڵ���ӽ�������
	//1.��ͷָ��Ϊ�գ�������Ϊ�գ�ֱ�ӽ��½�����ַ��ֵ��ͷָ��
	if (phead == NULL)
	{
		phead = pnew;
		return phead;
	}
	else
	{
		//2.��ͷָ�벻Ϊ�գ���˵���������Ѿ��������ݣ���ͷ����ַ��Ϊ�½ڵ�ĵ�ַ������ԭ����ͷ����ַ�浽�½ڵ��next��
		pnew->pNext = phead;
		phead = pnew;
	}
	return phead;

}
node * deleteByData(node * phead, int data) {
	//���ͷ����е����ݺ���Ҫɾ��������һ�£���ͷ���ɾ��
	if (phead->data == data) {
		phead = phead->pNext;
	}
	//����˫ָ��
	//ָ��1�����ϸ����ĵ�ַ
	node * pbefore = phead;
	//ָ��2���浱ǰ���ĵ�ַ
	node * pnode = phead->pNext;
	while (pnode != NULL) {
		if (pnode ->data != data){
			pbefore = pnode;
			pnode = pnode->pNext;
		}
		else {
			pbefore->pNext = pnode->pNext;
			free(pnode);
			break;
		}
	}
	return phead;

}

node * deleteByData_1(node * phead, int data) {
	//����˫ָ��
	//ָ��1�����ϸ����ĵ�ַ
	node * pbefore = phead;
	//ָ��2���浱ǰ���ĵ�ַ
	node * pnode = phead->pNext;
	//���ͷ���
	//���ͷ����е����ݺ���Ҫɾ��������һ�£���ͷ���ɾ��
	if (phead->data = data) 
	{
		//�ı�ͷ����ַ
		phead = pnode;
	}
	//����ڲ����
	while (pnode->pNext != NULL) {
Next:	if (pnode->data == data) 
		{
			//ͨ���ı��ַ�����ɾ��
			pbefore->pNext = pnode->pNext;
			free(pnode);
			pnode = pbefore->pNext;
			goto Next;
		}
		//ͨ��ָ�뽻�渳ֵ���������ڲ��ƶ�
		pbefore = pnode;
		pnode = pnode->pNext;
	}
	//���β�����
	if (pnode->pNext == NULL && pnode->data == data)
	{
		pbefore->pNext = NULL;
	}
	return phead;

}

void updateByLocation(node * phead, int data,int location) {


}

char search(node * phead, int data) {

	node * ptemp = phead;
	int i = 1;
	while (ptemp != NULL) {
		if (ptemp->data == data) {
			return i;
		}
		i++;
		ptemp = ptemp->pNext;
	}
	return 'F';
}

void showAll(node * phead) {

	printf("\nͷ������� = %d,ͷ����ַ = %p", phead->data, phead);

	node * pnode = phead;
	while (pnode->pNext != NULL)
	{
		pnode = pnode->pNext;
		printf("\n������� = %d,����ַ = %p", pnode->data, pnode);
	}

	printf("\n�������");

}