#pragma once

#include<stdio.h>
#include<stdlib.h>

struct LinkNode
{
	int data;
	struct LinkNode * pNext;
};

//类型别名
typedef struct LinkNode node;

//链表数据结构的函数的声明
//初始化
void init(node * phead);

//在尾部添加数据
node * addback(node * phead , int data);

//在头部添加数据
node * addhead(node * phead,int data);

//删除链表中某一位置的数据
node * deleteByData(node * phead, int data);

//修改链表中某一位置的数据
void update(node * phead, int data);

//查找数据是否存在链表中,若存在，返回该数据的位置信息
char search(node * phead, int data);

//显示所有数据
void showAll(node * phead);

//链表的排序方法
//冒泡排序
node * bubbleSort(node * phead);
