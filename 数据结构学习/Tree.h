#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TElemType int

//构造结点的结构体
typedef struct BiTNode {
	TElemType data;//数据域
	struct BiTNode* lchild, * rchild;//左右孩子指针
}BiTNode, * BiTree;
typedef struct SNode {
	BiTree p;
	int tag;
}SNode;
//生成树
void CreateBiTree(BiTree* tree);
/*        递归遍历         */
//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode* elem);
//先序遍历
void PreOrderTraverse(BiTree T);
//中序遍历
void INOrderTraverse(BiTree T);
//后序遍历
void PostOrderTraverse(BiTree T);
/*       非递归遍历         */
//前序遍历使用的进栈函数
void push(BiTNode** a, BiTNode* elem);
//弹栈函数
void pop();
//模拟操作结点元素的函数，输出结点本身的数值
void display_Elem(BiTNode* elem);
//拿到栈顶元素
BiTNode* getTop(BiTNode** a);
//先序遍历非递归算法
void PreOrder_Traverse(BiTree Tree);
//中序遍历非递归算法
void InOrder_Traverse1(BiTree Tree);
//中序遍历实现的另一种方法
void InOrder_Traverse2(BiTree Tree);
//后序遍历非递归算法
//后序遍历使用的进栈函数
void postpush(SNode* a, SNode sdata);
//后序遍历函数
void PostOrder_Traverse(BiTree Tree);
