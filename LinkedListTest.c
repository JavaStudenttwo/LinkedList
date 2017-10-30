#include "LinkedList.h"

node * testAdd(node * phead);
node * testDelete(node * phead);
void testSearch(node * phead ,int data);
void testSrot_1(phead);

int main(void) {
	

	node * phead = NULL;

	phead = testAdd(phead);
	testSearch(phead,833);
	testSearch(phead,383);

	phead = testDelete(phead);
	testSrot_1(phead);

	system("pause");
	return 0;
}

node * testAdd(node * phead) {

	phead = addback(phead, 199);
	phead = addback(phead, 833);
	phead = addback(phead, 195);
	phead = addback(phead, 194);
	phead = addback(phead, 193);

	phead = addhead(phead, 192);
	phead = addhead(phead, 444);

	showAll(phead);

	return phead;
}

node * testDelete(node * phead) {

	phead = deleteByData(phead, 199);
	phead = deleteByData(phead, 444);
	phead = deleteByData(phead, 195);

	showAll(phead);

	return phead;
}

void testSearch(node * phead,int data) {

	char result = search(phead, data);
	if (result != 'F')
	{
		printf("\n该数据在链表中的第%d个结点中\n",(int)result);
		goto END;
	}
	else
	{
		printf("\n该链表中不存在该数据\n");
	}
END:printf("检索结束");

}

void testSrot_1(phead) {

	phead = bubbleSort(phead);
	showAll(phead);
}