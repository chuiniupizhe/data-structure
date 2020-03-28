#include "Tree.h"
int NodeCount(BiTree T) {
	if (T == NULL) {
		return 0;
	}
	if (T->lchild == NULL && T->rchild != NULL || T->rchild == NULL && T->lchild != NULL) {
		return 1 + NodeCount(T->lchild) + NodeCount(T->rchild);
	}
	return NodeCount(T->lchild) + NodeCount(T->rchild);
}

int main() {
	BiTree Tree;
	CreateBiTree(&Tree);
	int num = NodeCount(Tree);
	printf("��Ϊ1�Ľڵ��У�%d�� \n", num);
}