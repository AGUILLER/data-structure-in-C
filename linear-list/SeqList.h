#ifndef SEQLIST_H
#define SEQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define true 1
#define false 0
typedef int bool;

typedef struct {
	int *elem;
	int length;
	int listsize;
} SqList;

bool InitList_Sq(SqList *L);
bool ListInsert_Sq(SqList *L, int i, int e); 
bool ListDelete_Sq(SqList *L, int i, int *e); 
void ListPrint_Sq(SqList L);
int GetLength_Sq(SqList L);
int LocatedElem_Sq(SqList L, int e, bool(*compare)(int, int));
int GetElem_Sq(SqList L, int i);
bool compare(int a, int b);
void MergeList_Sq(SqList La, SqList Lb, SqList *Lc);
void Union(SqList *La,SqList Lb);
#endif
