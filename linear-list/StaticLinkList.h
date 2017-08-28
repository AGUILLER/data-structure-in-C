#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#define MAXSIZE 100
typedef struct {
	int data;
	int cur;
}component, SLinkList[MAXSIZE];

/*
为了辨明数组中哪些分量未被使用，解决的办法是将所有未被使用过的
以及被删除的分量用游标链成一个备用的链表，每当进行插入时便可以
从备用链表上取得第一个节点作为待插入的新节点；反之，删除时将从
链表中删除下来的节点链接到备用链表上。 
*/

void InitSpace_SL(SLinkList space);
int Malloc_SL(SLinkList space);
void Free_SL(SLinkList space, int k);
void difference(SLinkList space, int *S); 
int LocateElem_SL(SLinkList S, int e);
void PrintOut_SL(SLinkList space,const int S); 

#endif
