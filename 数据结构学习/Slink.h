#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct slist
{
	int id;
	struct slist* next;
}L;
//创建一个节点
L* create_node(int data);
//链表的尾插
void tail_insert(L* pH, L* new);
//链表的头插
void top_insert(L* pH, L* new);
//链表的遍历
void Print_node(L* pH);
//删除链表中的前驱结点
int detele_front_list_node(L* pH, int data);
//删除非递减有序线性表中重复元素
void detele_same_list_node(L* pH);
//删除链表中的节点
int detele_list_node(L* pH, int data);
//倒序链表
void trave_list(L* pH);
//重排链表
void Re_Sort(L* pH, int num);
