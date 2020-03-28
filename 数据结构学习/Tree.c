#include "Tree.h"
//Լ��ͨ��ǰ������������
//ÿ����㶼�����Һ��ӣ����Ӳ�����ΪNULL
//������
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
		CreateBiTree(&(*tree)->lchild);//����������
		CreateBiTree(&(*tree)->rchild);//����������
	}
}
/*        �ݹ����         */
//ģ��������Ԫ�صĺ����������㱾�����ֵ
void displayElem(BiTNode* elem) {
	printf("%d ", elem->data);
}
//�������
void PreOrderTraverse(BiTree T) {
	if (T) {
		displayElem(T);//���ò���������ݵĺ�������
		PreOrderTraverse(T->lchild);//���ʸý�������
		PreOrderTraverse(T->rchild);//���ʸý����Һ���
	}
	//������Ϊ�գ�������һ��
	return;
}
//�������
void INOrderTraverse(BiTree T) {
	if (T) {
		INOrderTraverse(T->lchild);//��������
		displayElem(T);//���ò���������ݵĺ�������
		INOrderTraverse(T->rchild);//�����Һ���
	}
	//������Ϊ�գ�������һ��
	return;
}
//�������
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);//��������
		PostOrderTraverse(T->rchild);//�����Һ���
		displayElem(T);//���ò���������ݵĺ�������
	}
	//������Ϊ�գ�������һ��
	return;
}

/*       �ǵݹ����         */
//top����ʱ�̱�ʾջ��Ԫ������λ��
int top = -1;
//ǰ�����ʹ�õĽ�ջ����
void push(BiTNode** a, BiTNode* elem) {
	a[++top] = elem;
}
//��ջ����
void pop() {
	if (top == -1) {
		return;
	}
	top--;
}
//ģ��������Ԫ�صĺ����������㱾�����ֵ
void display_Elem(BiTNode* elem) {
	printf("%d ", elem->data);
}
//�õ�ջ��Ԫ��
BiTNode* getTop(BiTNode** a) {
	return a[top];
}
//��������ǵݹ��㷨
void PreOrder_Traverse(BiTree Tree) {
	BiTNode* a[20];//����һ��˳��ջ
	BiTNode* p;//��ʱָ��
	push(a, Tree);//������ջ
	while (top != -1) {
		p = getTop(a);//ȡջ��Ԫ��
		pop();//��ջ
		while (p) {
			display_Elem(p);//���ý��Ĳ�������
			//����ý�����Һ��ӣ��Һ��ӽ�ջ
			if (p->rchild) {
				push(a, p->rchild);
			}
			p = p->lchild;//һֱָ���������һ������
		}
	}
}
//��������ǵݹ��㷨
void InOrder_Traverse1(BiTree Tree) {
	BiTNode* a[20];//����һ��˳��ջ
	BiTNode* p;//��ʱָ��
	push(a, Tree);//������ջ
	while (top != -1) {//top!=-1˵��ջ�ڲ�Ϊ�գ������������
		while ((p = getTop(a)) && p) {//ȡջ��Ԫ�أ��Ҳ���ΪNULL
			push(a, p->lchild);//���ý������ӽ�ջ�����û�����ӣ�NULL��ջ
		}
		pop();//����ѭ����ջ��Ԫ�ؿ϶�ΪNULL����NULL��ջ
		if (top != -1) {
			p = getTop(a);//ȡջ��Ԫ��
			pop();//ջ��Ԫ�ص�ջ
			display_Elem(p);
			push(a, p->rchild);//��pָ��Ľ����Һ��ӽ�ջ
		}
	}
}
//�������ʵ�ֵ���һ�ַ���
void InOrder_Traverse2(BiTree Tree) {
	BiTNode* a[20];//����һ��˳��ջ
	BiTNode* p;//��ʱָ��
	p = Tree;
	//��pΪNULL����ջΪ��ʱ���������������
	while (p || top != -1) {
		//���p��ΪNULL������ѹջ��������������
		if (p) {
			push(a, p);
			p = p->lchild;
		}
		//���p==NULL������������������ɣ���Ҫ������һ�����������
		else {
			p = getTop(a);
			pop();
			display_Elem(p);
			p = p->rchild;
		}
	}
}
//��������ǵݹ��㷨
//�������ʹ�õĽ�ջ����
void postpush(SNode* a, SNode sdata) {
	a[++top] = sdata;
}
//�����������
void PostOrder_Traverse(BiTree Tree) {
	SNode a[20];//����һ��˳��ջ
	BiTNode* p;//��ʱָ��
	int tag;
	SNode sdata;
	p = Tree;
	while (p || top != -1) {
		while (p) {
			//Ϊ�ý����ջ��׼��
			sdata.p = p;
			sdata.tag = 0;//���ڱ��������ӣ����ñ�־λΪ0
			postpush(a, sdata);//ѹջ
			p = p->lchild;//�Ըý��Ϊ����㣬��������
		}
		sdata = a[top];//ȡջ��Ԫ��
		pop();//ջ��Ԫ�ص�ջ
		p = sdata.p;
		tag = sdata.tag;
		//���tag==0��˵���ý�㻹û�б��������Һ���
		if (tag == 0) {
			sdata.p = p;
			sdata.tag = 1;
			postpush(a, sdata);//���ĸý��ı�־λ������ѹջ
			p = p->rchild;//�Ըý����Һ���Ϊ����㣬�ظ�ѭ��
		}
		//���ȡ������ջ��Ԫ�ص�tag==1��˵���˽�������������������ˣ����Ե��ò���������
		else {
			display_Elem(p);
			p = NULL;
		}
	}
}