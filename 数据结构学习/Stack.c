#include "Stack.h"

void Stackpush(Stack* ps, int data)
{
	//�����½ڵ㲢��ʼ��
	Node* pn = (Node*)malloc(sizeof(Node));
	pn->data = data;
	pn->next = NULL;
	//�����½ڵ�
	pn->next = ps->head;
	ps->head = pn;
	ps->cnt++;
}

void Stacktravel(Stack* ps)
{
	printf("��ջ�е�Ԫ���У�\n");
	Node* p = ps->head;
	//�ж϶�ջΪ��Ϊ��
	while (p != NULL)
	{
		printf("%d ", p->data);
		//ָ����һ���ڵ�
		p = p->next;
	}
	printf("\n");
}

int Stackpop(Stack* ps)
{
	//�ж�Ϊ��Ϊ��
	if (NULL == ps->head)
		return NULL;
	//����Ҫɾ���Ľڵ��ַ
	Node* p = ps->head;
	//ͷָ��ָ����һ���ڵ�
	ps->head = ps->head->next;
	ps->cnt--;
	//�洢Ҫɾ���Ľڵ�Ԫ��ֵ
	int tmp = p->data; //�ͷ��ڴ���Ϻ��û��Ԫ��ֵ��
	free(p); //�ͷ��ڴ�
	p = NULL; //��Ϊ��ָ��
	return tmp;
}

int Stacktop(Stack* ps)
{
	//�ж϶�ջ�Ƿ�Ϊ��
	if (Stackempty(ps))
		return NULL;
	return ps->head->data;
}

int Stackempty(Stack* ps)
{
	return NULL == ps->head;
}

int Stackfull(Stack* ps)
{
	return 0;
}

int Stacksize(Stack* ps)
{
	return ps->cnt;
}

int StackButtom(Stack* ps)
{
	Stack stack;
	stack.head = 0;
	stack.cnt = 0;
	int num = Stacksize(ps) - 1;
	for (size_t i = 0; i < num; i++)
	{
		Stackpush(&stack, Stacktop(ps));
		Stackpop(ps);
	}
	int data = Stacktop(ps);
	for (size_t i = 0; i < num; i++)
	{
		Stackpush(ps, Stacktop(&stack));
		Stackpop(&stack);
	}
	return data;
}

//int main(void)
//{
//	Stack stack;
//	stack.head = 0;
//	stack.cnt = 0;
//	printf("%s\n", Stackempty(&stack) ? "��ջΪ��" : "��ջδ��");
//	/*printf("��ջԪ���ǣ�%d\n", Stackpop(&stack));
//	printf("��ջ��Ԫ�صĸ���Ϊ��%d\n", Stacksize(&stack));
//	printf("--------------------------\n");*/
//	Stackpush(&stack, 11); //11
//	Stackpush(&stack, 22); //22 11
//	Stackpush(&stack, 33); //33 22 11
//	Stackpush(&stack, 44); //44 33 22 11
//	Stacktravel(&stack); //44 33 22 11
//	//printf("��ջԪ���ǣ�%d\n", Stackpop(&stack));
//	//Stacktravel(&stack); //33 22 11
//	printf("--------------------------\n");
//	//printf("ջ��Ԫ��Ϊ��%d\n", Stacktop(&stack));
//	//printf("%s\n", Stackfull(&stack) ? "��ջΪ��" : "��ջδ��");
//	//printf("%s\n", Stackempty(&stack) ? "��ջΪ��" : "��ջδ��");
//	int data = StackButtom(&stack);
//	printf("ջ��Ԫ��Ϊ%d", data);
//	printf("\n--------------------------\n");
//	printf("��ջ��Ԫ�صĸ���Ϊ��%d\n", Stacksize(&stack));
//	return 0;
//}