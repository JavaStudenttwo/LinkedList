#include "LinkedList.h"

void init(node * phead)
{
	phead->pNext = NULL;
	phead->data = 0;
}

node * addback(node * phead ,int data) {

	node * pnew = malloc(sizeof(node));
	//使用新节点记录数据
	pnew->data = data;
	pnew->pNext = NULL;
	//将新节点添加进链表中
	//1.若头指针为空，即链表为空，直接将新建结点地址赋值给头指针
	if (phead == NULL)
	{
		phead = pnew;
		return phead;
	}
	else
	{
		//2.若头指针不为空，则说明链表中已经存在数据，遍历链表，取出最后一个结点的地址，并将新节点的地址连接
		//备份头结点
		node * ptemp = phead;
		//遍历链表,取出最后一个结点的地址
		while (ptemp->pNext != NULL) {
			ptemp = ptemp->pNext;
		}
		//将新节点的地址连接
		ptemp->pNext = pnew;

	}
	return phead;

}

node * addhead(node * phead,int data) {

	node * pnew = malloc(sizeof(node));
	//使用新节点记录数据
	pnew->data = data;
	pnew->pNext = NULL;
	//将新节点添加进链表中
	//1.若头指针为空，即链表为空，直接将新建结点地址赋值给头指针
	if (phead == NULL)
	{
		phead = pnew;
		return phead;
	}
	else
	{
		//2.若头指针不为空，则说明链表中已经存在数据，将头结点地址改为新节点的地址，并将原来的头结点地址存到新节点的next中
		pnew->pNext = phead;
		phead = pnew;
	}
	return phead;

}
node * deleteByData(node * phead, int data) {
	//如果头结点中的数据和需要删除的数据一致，则将头结点删除
	if (phead->data == data) {
		phead = phead->pNext;
	}
	//定义双指针
	//指针1保存上个结点的地址
	node * pbefore = phead;
	//指针2保存当前结点的地址
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
	//定义双指针
	//指针1保存上个结点的地址
	node * pbefore = phead;
	//指针2保存当前结点的地址
	node * pnode = phead->pNext;
	//检查头结点
	//如果头结点中的数据和需要删除的数据一致，则将头结点删除
	if (phead->data = data) 
	{
		//改变头结点地址
		phead = pnode;
	}
	//检查内部结点
	while (pnode->pNext != NULL) {
Next:	if (pnode->data == data) 
		{
			//通过改变地址将结点删除
			pbefore->pNext = pnode->pNext;
			free(pnode);
			pnode = pbefore->pNext;
			goto Next;
		}
		//通过指针交替赋值，向链表内部移动
		pbefore = pnode;
		pnode = pnode->pNext;
	}
	//检查尾部结点
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

	printf("\n头结点数据 = %d,头结点地址 = %p", phead->data, phead);

	node * pnode = phead;
	while (pnode->pNext != NULL)
	{
		pnode = pnode->pNext;
		printf("\n结点数据 = %d,结点地址 = %p", pnode->data, pnode);
	}

	printf("\n链表结束");

}