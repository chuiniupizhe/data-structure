#pragma once
//基于链式存储结构的堆栈实现
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data; //存放的具体元素
	struct Node* next; //存放下一个节点地址
}Node;

typedef struct
{
	int cnt;
	Node* head;
}Stack;
//入栈操作
void Stackpush(Stack* ps, int data);
//遍历操作
void Stacktravel(Stack* ps);
//出栈操作
int Stackpop(Stack* ps);
//查看栈顶元素
int Stacktop(Stack* ps);
//判断堆栈是否为空
int Stackempty(Stack* ps);
//判断堆栈是否为满
int Stackfull(Stack* ps);
//查看堆栈元素个数
int Stacksize(Stack* ps);
//返回栈底元素
int StackButtom(Stack* ps);