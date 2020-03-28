#include "Queue.h"

//创建队列
HeadPoint InitQueue()
{
	HeadPoint Head = (HeadPoint)malloc(sizeof(HeadNode));
	Head->QueueSize = 0;
	Head->front = Head->rear = (QueuePoint)malloc(sizeof(QueueNode));
	Head->rear->next = NULL;
	Head->front->ch = 0;
	return Head;
}

//判断队列是否为空
int QueueEmpty(HeadPoint Head)
{
	if (Head->front == Head->rear)
		return 1;
	return 0;
}

//查看队首
char QueuegetFront(HeadPoint Head)
{
	if (QueueEmpty(Head))
	{
		printf("对不起,该队列为空!\n");
		return 0;
	}
	return Head->front->next->ch;
}

//弹出队首
void QueuePop(HeadPoint Head)
{
	QueuePoint p = Head->front;
	if (QueueEmpty(Head))
	{
		printf("对不起,该队列为空!无可出队元素!\n");
		return;
	}
	Head->front = p->next;
	Head->QueueSize--;
	free(p);
	return;
}

//压入队尾
void QueuePush(HeadPoint Head, char ch)
{
	QueuePoint p = (QueuePoint)malloc(sizeof(QueueNode));
	if (p == NULL)
	{
		printf("对不起，系统内存不足!入队失败!\n");
		return;
	}
	p->next = Head->rear->next;
	p->ch = ch;
	Head->rear->next = p;
	Head->rear = p;
	Head->QueueSize++;
	return;
}

//删除队首
void QueueDelete(HeadPoint Head)
{
	while (!QueueEmpty(Head))
		QueuePop(Head);
	free(Head->front);
	return;
}

//int main()
//{
//	char ch;
//	HeadPoint Head = InitQueue();
//	printf("%s\n", QueueEmpty(Head) ? "该队列为空!" : "该队列非空!");
//	while ((ch = getchar()) != '\n')
//		QueuePush(Head, ch);
//	printf("%s\n", QueueEmpty(Head) ? "该队列为空!" : "该队列非空!");
//	while (!QueueEmpty(Head))
//	{
//		printf("%c", QueuegetFront(Head));
//		QueuePop(Head);
//	}
//	printf("\n%s\n", QueueEmpty(Head) ? "该队列为空!" : "该队列非空!");
//	QueueDelete(Head);
//	free(Head);
//	printf("链队列操作结束!\n");
//	return 0;
//}