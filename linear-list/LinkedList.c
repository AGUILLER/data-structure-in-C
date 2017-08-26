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
		printf("Error: malloc failes in add_to_list1\n");
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
	int j = 0;
	while (p->next && j < i-1){
		p = p->next;
		j++;
	} 
	if (!(p->next) || j > i-1) return false;
	e = p->next->data;
	p->next = p->next->next;
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
	for (index = first; index != NULL; index = index->next){
		printf("%d",index->data);
	}
}
