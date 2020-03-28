#pragma once
#include<stdio.h>
#include<stdlib.h>

//******声明数据结构******
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
//创建队列
HeadPoint InitQueue();
//判断队列是否为空
int QueueEmpty(HeadPoint Head);
//查看队首
char QueuegetFront(HeadPoint Head);
//弹出队首
void QueuePop(HeadPoint Head);
//压入队尾
void QueuePush(HeadPoint Head, char ch);
//删除队首
void QueueDelete(HeadPoint Head);
