#include "Slink.h"

//创建一个节点
L* create_node(int data)
{
	//给每个节点分配结构体一样的空间大小
	L* p = malloc(sizeof(L));
	if (NULL == p)
	{
		printf("malloc error!\n");
		return NULL;
	}
	//由于结构体在未初始化的时候一样是脏数据，所以要清
	memset(p, 0, sizeof(L));
	//初始化第一个节点
	p->id = data;
	//将节点的后继指针设置为NULL
	p->next = NULL;
}

//链表的尾插
void tail_insert(L* pH, L* new)
{
	//获取当前的位置
	L* p = pH;
	//如果当前位置的下一个节点不为空
	while (NULL != p->next)
	{
		//移动到下一个节点
		p = p->next;
	}
	//如果跳出以上循环，所以已经到了NULL的这个位置
	//此时直接把新插入的节点赋值给NULL这个位置
	p->next = new;
}

//链表的头插
void top_insert(L* pH, L* new)
{
	L* p = pH;
	new->next = p->next;
	p->next = new;
}

//链表的遍历
void Print_node(L* pH)
{
	//获取当前的位置
	L* p = pH;
	//获取第一个节点的位置
	p = p->next;
	//如果当前位置的下一个节点不为空
	while (NULL != p->next)
	{
		//(1)打印节点的数据
		printf("id:%d\n", p->id);
		//(2)移动到下一个节点,如果条件仍为真，则重复(1)，再(2)
		p = p->next;
	}
	//如果当前位置的下一个节点为空，则打印数据
	//说明只有一个节点
	printf("id:%d\n", p->id);
}

//删除链表中的前驱结点
int detele_front_list_node(L* pH, int data)
{
	//获取当前头节点的位置
	L* p = pH;
	L* prev = NULL;
	//保存当前节点的前一个节点的指针
	prev = p;
	//然后让当前的指针继续往后移动
	p = p->next->next;
	while (NULL != p)
	{
		//判断，找到了要删除的数据
		if (p->id == data)
		{
			free(prev->next);
			prev->next = p;
			return 0;
		}
		prev = prev->next;
		p = p->next;
	}
	printf("没有要删除的数据");
	return -1;
}

//删除非递减有序线性表中重复元素
void detele_same_list_node(L* pH)
{
	//获取当前头节点的位置
	L* p = pH;
	L* prev = NULL;
	//初始化指针
	prev = p->next;
	p = p->next->next->next;
	while (NULL != p)
	{
		//判断，找到了要删除的数据
		if ((p->id) == (prev->next->id))
		{
			free(prev->next);
			prev->next = p;
			//p指针后移，q不动，继续比较
			p = p->next;
		}
		else
		{
			//两指针同时后移，发现重复元素
			prev = prev->next;
			p = p->next;
		}
	}
	printf("删除成功");
}

//删除链表中的节点
int detele_list_node(L* pH, int data)
{
	//获取当前头节点的位置
	L* p = pH;
	L* prev = NULL;
	while (NULL != p->next)
	{
		//保存当前节点的前一个节点的指针
		prev = p;
		//然后让当前的指针继续往后移动
		p = p->next;
		//判断，找到了要删除的数据
		if (p->id == data)
		{
			//两种情况，一种是普通节点，还有一种是尾节点
			if (p->next != NULL)  //普通节点的情况
			{
				prev->next = p->next;
				free(p);
			}
			else //尾节点的情况
			{
				prev->next = NULL; //将这个尾节点的上一个节点的指针域指向空
				free(p);
			}
			return 0;
		}
	}
	printf("没有要删除的节点\n");
	return -1;
}

//倒序链表
void trave_list(L* pH)
{
	//保存第一个节点的位置
	L* p = pH->next;
	L* pBack;
	int i = 0;
	if (p->next == NULL || p == NULL)
		return;

	while (NULL != p->next) //遍历链表
	{
		//保存第一个节点的下一个节点
		pBack = p->next;
		//找到第一个有效节点,其实就是头指针的下一个节点
		if (p == pH->next)
		{
			//第一个有效节点就是最后一个节点，所以要指向NULL
			p->next = NULL;
		}
		else
		{
			/*
			new->next = p->next ;
			p->next = new ;
			*/
			p->next = pH->next; //尾部连接
		}
		pH->next = p; //头部连接
		p = pBack; //走下一个节点
	}
	top_insert(pH, p); //插入最后一个节点
}

//重排链表
void Re_Sort(L* pH, int num) {
	pH = pH->next;
	L* key = pH;
	for (size_t i = 0; i < num / 2; i++)
	{
		for (size_t j = 0; j < num - 2 * i - 1; j++)
		{
			key = key->next;
		}
		key->next = pH->next;
		pH->next = key;
		pH = pH->next->next;
		key = pH;
	}
	pH->next = NULL;
}

//int main()
//{
//	//创建第一个节点
//	int i;
//	L* header = create_node(0);
//	for (i = 1; i < 11; i++)
//	{
//		tail_insert(header, create_node(i));
//	}
//	Print_node(header);
//	Re_Sort(header,10);
//	Print_node(header);
//	return 0;
//}