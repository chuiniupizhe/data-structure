#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct slist
{
	int id;
	struct slist* next;
}L;
//����һ���ڵ�
L* create_node(int data);
//�����β��
void tail_insert(L* pH, L* new);
//�����ͷ��
void top_insert(L* pH, L* new);
//����ı���
void Print_node(L* pH);
//ɾ�������е�ǰ�����
int detele_front_list_node(L* pH, int data);
//ɾ���ǵݼ��������Ա����ظ�Ԫ��
void detele_same_list_node(L* pH);
//ɾ�������еĽڵ�
int detele_list_node(L* pH, int data);
//��������
void trave_list(L* pH);
//��������
void Re_Sort(L* pH, int num);
