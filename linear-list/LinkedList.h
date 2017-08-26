#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define true 1
#define false 0
typedef int bool;

//typedef int ElemType;
typedef struct LNode {
	int data;
	struct LNode *next;
}LNode,*LinkList;


void CreateList_L(LinkList L, int n);//ͷ�巨 
int GetElem_L(LinkList L, int i);
struct LNode *create_list(LNode *first);
bool ListInsert_L(LinkList L, int i, int e);
bool ListDelete_L(LinkList L, int i,int *e);
struct LNode *add_to_list(struct LNode *list, int n);
void print_list(struct LNode *first);
void MergeList_L (LinkList La, LinkList Lb, LinkList Lc); 

#endif
