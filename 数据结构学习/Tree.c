#include "Tree.h"
//约定通过前序遍历创建结点
//每个结点都有左右孩子，孩子不存在为NULL
//生成树
void CreateBiTree(BiTree* tree)
{
	int num;
	scanf_s("%d", &num);
	if (0 == num)
	{
		*tree = NULL;
	}
	else
	{
		*tree = (BiTNode*)malloc(sizeof(BiTNode));
		(*tree)->data = num;
		CreateBiTree(&(*tree)->lchild);//创建左子树
		CreateBiTree(&(*tree)->rchild);//创建右子树
	}
}
/*        递归遍历         */
//模拟操作结点元素的函数，输出结点本身的数值
void displayElem(BiTNode* elem) {
	printf("%d ", elem->data);
}
//先序遍历
void PreOrderTraverse(BiTree T) {
	if (T) {
		displayElem(T);//调用操作结点数据的函数方法
		PreOrderTraverse(T->lchild);//访问该结点的左孩子
		PreOrderTraverse(T->rchild);//访问该结点的右孩子
	}
	//如果结点为空，返回上一层
	return;
}
//中序遍历
void INOrderTraverse(BiTree T) {
	if (T) {
		INOrderTraverse(T->lchild);//遍历左孩子
		displayElem(T);//调用操作结点数据的函数方法
		INOrderTraverse(T->rchild);//遍历右孩子
	}
	//如果结点为空，返回上一层
	return;
}
//后序遍历
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);//遍历左孩子
		PostOrderTraverse(T->rchild);//遍历右孩子
		displayElem(T);//调用操作结点数据的函数方法
	}
	//如果结点为空，返回上一层
	return;
}

/*       非递归遍历         */
//top变量时刻表示栈顶元素所在位置
int top = -1;
//前序遍历使用的进栈函数
void push(BiTNode** a, BiTNode* elem) {
	a[++top] = elem;
}
//弹栈函数
void pop() {
	if (top == -1) {
		return;
	}
	top--;
}
//模拟操作结点元素的函数，输出结点本身的数值
void display_Elem(BiTNode* elem) {
	printf("%d ", elem->data);
}
//拿到栈顶元素
BiTNode* getTop(BiTNode** a) {
	return a[top];
}
//先序遍历非递归算法
void PreOrder_Traverse(BiTree Tree) {
	BiTNode* a[20];//定义一个顺序栈
	BiTNode* p;//临时指针
	push(a, Tree);//根结点进栈
	while (top != -1) {
		p = getTop(a);//取栈顶元素
		pop();//弹栈
		while (p) {
			display_Elem(p);//调用结点的操作函数
			//如果该结点有右孩子，右孩子进栈
			if (p->rchild) {
				push(a, p->rchild);
			}
			p = p->lchild;//一直指向根结点最后一个左孩子
		}
	}
}
//中序遍历非递归算法
void InOrder_Traverse1(BiTree Tree) {
	BiTNode* a[20];//定义一个顺序栈
	BiTNode* p;//临时指针
	push(a, Tree);//根结点进栈
	while (top != -1) {//top!=-1说明栈内不为空，程序继续运行
		while ((p = getTop(a)) && p) {//取栈顶元素，且不能为NULL
			push(a, p->lchild);//将该结点的左孩子进栈，如果没有左孩子，NULL进栈
		}
		pop();//跳出循环，栈顶元素肯定为NULL，将NULL弹栈
		if (top != -1) {
			p = getTop(a);//取栈顶元素
			pop();//栈顶元素弹栈
			display_Elem(p);
			push(a, p->rchild);//将p指向的结点的右孩子进栈
		}
	}
}
//中序遍历实现的另一种方法
void InOrder_Traverse2(BiTree Tree) {
	BiTNode* a[20];//定义一个顺序栈
	BiTNode* p;//临时指针
	p = Tree;
	//当p为NULL或者栈为空时，表明树遍历完成
	while (p || top != -1) {
		//如果p不为NULL，将其压栈并遍历其左子树
		if (p) {
			push(a, p);
			p = p->lchild;
		}
		//如果p==NULL，表明左子树遍历完成，需要遍历上一层结点的右子树
		else {
			p = getTop(a);
			pop();
			display_Elem(p);
			p = p->rchild;
		}
	}
}
//后序遍历非递归算法
//后序遍历使用的进栈函数
void postpush(SNode* a, SNode sdata) {
	a[++top] = sdata;
}
//后序遍历函数
void PostOrder_Traverse(BiTree Tree) {
	SNode a[20];//定义一个顺序栈
	BiTNode* p;//临时指针
	int tag;
	SNode sdata;
	p = Tree;
	while (p || top != -1) {
		while (p) {
			//为该结点入栈做准备
			sdata.p = p;
			sdata.tag = 0;//由于遍历是左孩子，设置标志位为0
			postpush(a, sdata);//压栈
			p = p->lchild;//以该结点为根结点，遍历左孩子
		}
		sdata = a[top];//取栈顶元素
		pop();//栈顶元素弹栈
		p = sdata.p;
		tag = sdata.tag;
		//如果tag==0，说明该结点还没有遍历它的右孩子
		if (tag == 0) {
			sdata.p = p;
			sdata.tag = 1;
			postpush(a, sdata);//更改该结点的标志位，重新压栈
			p = p->rchild;//以该结点的右孩子为根结点，重复循环
		}
		//如果取出来的栈顶元素的tag==1，说明此结点左右子树都遍历完了，可以调用操作函数了
		else {
			display_Elem(p);
			p = NULL;
		}
	}
}