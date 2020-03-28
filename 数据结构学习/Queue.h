#pragma once
#include<stdio.h>
#include<stdlib.h>

//******�������ݽṹ******
typedef struct node
{
	char ch;
	struct node* next;
}QueueNode, * QueuePoint;

typedef struct
{
	int QueueSize;
	QueuePoint front;
	QueuePoint rear;
}HeadNode, * HeadPoint;
//��������
HeadPoint InitQueue();
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(HeadPoint Head);
//�鿴����
char QueuegetFront(HeadPoint Head);
//��������
void QueuePop(HeadPoint Head);
//ѹ���β
void QueuePush(HeadPoint Head, char ch);
//ɾ������
void QueueDelete(HeadPoint Head);
