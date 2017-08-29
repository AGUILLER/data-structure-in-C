#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>


struct LNode *create_list(LNode *first)
{
	//struct LNode *new_first = NULL;
	int value;
	scanf("%d", &value);
	while (value != 0){
		first = add_to_list(first,value);
		scanf("%d", &value);
	}
	return first; 
}

void CreateList_L(LinkList L, int n){
	struct LNode *new_node;
	int i;
	//L = (LinkList)malloc(sizeof(struct LNode));
	L->next = NULL;
	for (i = n; i > 0; i--){
		new_node = (struct LNode*)malloc(sizeof(struct LNode));
		if (new_node == NULL) {
			printf("Error: malloc failes in CreateList_L.\n");
			exit(EXIT_FAILURE);
			}
		scanf("%d",&(new_node->data));
		new_node->next = L->next;
		L->next = new_node;
	}
}

struct LNode *add_to_list(struct LNode *list, int n){
	struct LNode *new_node;
	new_node = (struct LNode *)malloc(sizeof(struct LNode));
	if (new_node == NULL) {
		printf("Error: malloc failes in add_to_list1\n");
		exit(EXIT_FAILURE);
	}
	new_node->data = n;
	new_node->next = list;
	return new_node;	
}
bool ListInsert_L(LinkList L, int i, int e)
{
	LinkList p;
	int j = 0;
	p = L;
	struct LNode *new_node;
	
	while (p && j < i-1){
		p = p->next;
		j++;
	}
	if (!p || j > i-1) return false;
	new_node = (struct LNode *)malloc(sizeof(struct LNode));
	if (new_node == NULL) {
		printf("Error: malloc fails in add_to_list1\n");
		exit(EXIT_FAILURE);
	}
	new_node->data = e;
	new_node->next = p->next;
	p->next = new_node;
	return true;
}

bool ListDelete_L(LinkList L, int i,int *e){
	//在带头节点的单链表L中，删除第i个元素，并由e返回其值
	LinkList p = L;
	struct LNode *q;
	int j = 0;
	while (p->next && j < i-1){//第i-1个节点 
		p = p->next;
		j++;
	} 
	if (!(p->next) || j > i-1) return false;
	q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q); 
	return true;
}

int GetElem_L(LinkList L, int i){
	//L为带头节点的单链表的头指针
	LinkList p;
	int j = 1;
	p = L->next;
	while (p && j < i){
		p = p->next;
		j++;
	}
	if (!p || j > i){
		exit(EXIT_FAILURE);
	}
	return p->data;	 
}

void print_list(struct LNode *first)
{
	struct LNode *index;
	for (index = first->next; index != NULL; index = index->next){
		printf("%d",index->data);
	}
}

void MergeList_L (LinkList La, LinkList Lb, LinkList Lc){
	//已知单链表线性表La和Lb的元素按非递减排列
	//归并La和Lb得到新的单链表线性表Lc，Lc按值非递减排列
	LinkList pa,pb;
	pa = La->next;pb = Lb->next;
	while (pa && pb){
		if(pa->data <= pb->data){
			Lc->next = pa;
			Lc = Lc->next;
			pa = pa->next;
		}
		else {
			Lc->next = pb;
			Lc = Lc->next;
			pb = pb->next;
		}
	}
	Lc->next = pa?pa:pb;
	free(La);
	free(Lb);
}
