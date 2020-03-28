#include "Queue.h"

//��������
HeadPoint InitQueue()
{
	HeadPoint Head = (HeadPoint)malloc(sizeof(HeadNode));
	Head->QueueSize = 0;
	Head->front = Head->rear = (QueuePoint)malloc(sizeof(QueueNode));
	Head->rear->next = NULL;
	Head->front->ch = 0;
	return Head;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(HeadPoint Head)
{
	if (Head->front == Head->rear)
		return 1;
	return 0;
}

//�鿴����
char QueuegetFront(HeadPoint Head)
{
	if (QueueEmpty(Head))
	{
		printf("�Բ���,�ö���Ϊ��!\n");
		return 0;
	}
	return Head->front->next->ch;
}

//��������
void QueuePop(HeadPoint Head)
{
	QueuePoint p = Head->front;
	if (QueueEmpty(Head))
	{
		printf("�Բ���,�ö���Ϊ��!�޿ɳ���Ԫ��!\n");
		return;
	}
	Head->front = p->next;
	Head->QueueSize--;
	free(p);
	return;
}

//ѹ���β
void QueuePush(HeadPoint Head, char ch)
{
	QueuePoint p = (QueuePoint)malloc(sizeof(QueueNode));
	if (p == NULL)
	{
		printf("�Բ���ϵͳ�ڴ治��!���ʧ��!\n");
		return;
	}
	p->next = Head->rear->next;
	p->ch = ch;
	Head->rear->next = p;
	Head->rear = p;
	Head->QueueSize++;
	return;
}

//ɾ������
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
//	printf("%s\n", QueueEmpty(Head) ? "�ö���Ϊ��!" : "�ö��зǿ�!");
//	while ((ch = getchar()) != '\n')
//		QueuePush(Head, ch);
//	printf("%s\n", QueueEmpty(Head) ? "�ö���Ϊ��!" : "�ö��зǿ�!");
//	while (!QueueEmpty(Head))
//	{
//		printf("%c", QueuegetFront(Head));
//		QueuePop(Head);
//	}
//	printf("\n%s\n", QueueEmpty(Head) ? "�ö���Ϊ��!" : "�ö��зǿ�!");
//	QueueDelete(Head);
//	free(Head);
//	printf("�����в�������!\n");
//	return 0;
//}