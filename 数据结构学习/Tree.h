#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TElemType int

//������Ľṹ��
typedef struct BiTNode {
	TElemType data;//������
	struct BiTNode* lchild, * rchild;//���Һ���ָ��
}BiTNode, * BiTree;
typedef struct SNode {
	BiTree p;
	int tag;
}SNode;
//������
void CreateBiTree(BiTree* tree);
/*        �ݹ����         */
//ģ��������Ԫ�صĺ����������㱾�����ֵ
void displayElem(BiTNode* elem);
//�������
void PreOrderTraverse(BiTree T);
//�������
void INOrderTraverse(BiTree T);
//�������
void PostOrderTraverse(BiTree T);
/*       �ǵݹ����         */
//ǰ�����ʹ�õĽ�ջ����
void push(BiTNode** a, BiTNode* elem);
//��ջ����
void pop();
//ģ��������Ԫ�صĺ����������㱾�����ֵ
void display_Elem(BiTNode* elem);
//�õ�ջ��Ԫ��
BiTNode* getTop(BiTNode** a);
//��������ǵݹ��㷨
void PreOrder_Traverse(BiTree Tree);
//��������ǵݹ��㷨
void InOrder_Traverse1(BiTree Tree);
//�������ʵ�ֵ���һ�ַ���
void InOrder_Traverse2(BiTree Tree);
//��������ǵݹ��㷨
//�������ʹ�õĽ�ջ����
void postpush(SNode* a, SNode sdata);
//�����������
void PostOrder_Traverse(BiTree Tree);
