#include "Stack.h"

void Stackpush(Stack* ps, int data)
{
	//创建新节点并初始化
	Node* pn = (Node*)malloc(sizeof(Node));
	pn->data = data;
	pn->next = NULL;
	//插入新节点
	pn->next = ps->head;
	ps->head = pn;
	ps->cnt++;
}

void Stacktravel(Stack* ps)
{
	printf("堆栈中的元素有：\n");
	Node* p = ps->head;
	//判断堆栈为不为空
	while (p != NULL)
	{
		printf("%d ", p->data);
		//指向下一个节点
		p = p->next;
	}
	printf("\n");
}

int Stackpop(Stack* ps)
{
	//判断为不为空
	if (NULL == ps->head)
		return NULL;
	//保存要删除的节点地址
	Node* p = ps->head;
	//头指针指向下一个节点
	ps->head = ps->head->next;
	ps->cnt--;
	//存储要删除的节点元素值
	int tmp = p->data; //释放内存完毕后就没有元素值了
	free(p); //释放内存
	p = NULL; //置为空指针
	return tmp;
}

int Stacktop(Stack* ps)
{
	//判断堆栈是否为空
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
//	printf("%s\n", Stackempty(&stack) ? "堆栈为空" : "堆栈未空");
//	/*printf("出栈元素是：%d\n", Stackpop(&stack));
//	printf("堆栈中元素的个数为：%d\n", Stacksize(&stack));
//	printf("--------------------------\n");*/
//	Stackpush(&stack, 11); //11
//	Stackpush(&stack, 22); //22 11
//	Stackpush(&stack, 33); //33 22 11
//	Stackpush(&stack, 44); //44 33 22 11
//	Stacktravel(&stack); //44 33 22 11
//	//printf("出栈元素是：%d\n", Stackpop(&stack));
//	//Stacktravel(&stack); //33 22 11
//	printf("--------------------------\n");
//	//printf("栈顶元素为：%d\n", Stacktop(&stack));
//	//printf("%s\n", Stackfull(&stack) ? "堆栈为满" : "堆栈未满");
//	//printf("%s\n", Stackempty(&stack) ? "堆栈为空" : "堆栈未空");
//	int data = StackButtom(&stack);
//	printf("栈底元素为%d", data);
//	printf("\n--------------------------\n");
//	printf("堆栈中元素的个数为：%d\n", Stacksize(&stack));
//	return 0;
//}