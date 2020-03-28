#pragma once
//������ʽ�洢�ṹ�Ķ�ջʵ��
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data; //��ŵľ���Ԫ��
	struct Node* next; //�����һ���ڵ��ַ
}Node;

typedef struct
{
	int cnt;
	Node* head;
}Stack;
//��ջ����
void Stackpush(Stack* ps, int data);
//��������
void Stacktravel(Stack* ps);
//��ջ����
int Stackpop(Stack* ps);
//�鿴ջ��Ԫ��
int Stacktop(Stack* ps);
//�ж϶�ջ�Ƿ�Ϊ��
int Stackempty(Stack* ps);
//�ж϶�ջ�Ƿ�Ϊ��
int Stackfull(Stack* ps);
//�鿴��ջԪ�ظ���
int Stacksize(Stack* ps);
//����ջ��Ԫ��
int StackButtom(Stack* ps);