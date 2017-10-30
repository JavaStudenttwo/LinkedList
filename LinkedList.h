#pragma once

#include<stdio.h>
#include<stdlib.h>

struct LinkNode
{
	int data;
	struct LinkNode * pNext;
};

//���ͱ���
typedef struct LinkNode node;

//�������ݽṹ�ĺ���������
//��ʼ��
void init(node * phead);

//��β���������
node * addback(node * phead , int data);

//��ͷ���������
node * addhead(node * phead,int data);

//ɾ��������ĳһλ�õ�����
node * deleteByData(node * phead, int data);

//�޸�������ĳһλ�õ�����
void update(node * phead, int data);

//���������Ƿ����������,�����ڣ����ظ����ݵ�λ����Ϣ
char search(node * phead, int data);

//��ʾ��������
void showAll(node * phead);

//��������򷽷�
//ð������
node * bubbleSort(node * phead);
