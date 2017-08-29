#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H

#define true 1
#define false 0
typedef int bool;
typedef int ElemType;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
	
}DuLNode, *DuLinkList;

DuLinkList GetElem_DuL(const DuLinkList L, int i);
bool ListInset_DuL(DuLinkList L, int i, ElemType e);
bool ListDelete_DuL(DuLinkList L, int i, ElemType *e);

#endif
