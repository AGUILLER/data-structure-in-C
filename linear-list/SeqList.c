#include "SeqList.h"
#include <stdlib.h>
#include <stdio.h>

bool InitList_Sq(SqList *L)
{
	L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (L->elem == NULL) return false;
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return true;
}

bool ListInsert_Sq(SqList *L, int i, int e)
{
	int index;
	if (i < 1 || i > L->length + 1) return false;
	if (L->length >= L->listsize) {
		int * newbase;
		newbase = (int *)realloc(L->elem,(L->listsize + LISTINCREMENT)*sizeof(int));
		if (newbase == NULL) exit(EXIT_FAILURE);
		L->elem = newbase;
		L->listsize += LISTINCREMENT;		
	}
	for (index = L->length - 1; index >= i - 1; index--)
		L->elem[index+1] = L->elem[index];
	L->elem[i-1] = e;
	L->length++;
	return true;
}

bool ListDelete_Sq(SqList *L, int i, int *e)
{
	//在顺序线性表中删除第i个元素，并用e返回其值
	if (i < 1 || i > L->length) return false;
	*e = L->elem[i-1];
	for(;i <= L->length;i++)
		L->elem[i-1] = L->elem[i];
	L->length--;
	/*
	int *p,*q;
	p = &(L->elem[i-1]);
	*e = *p;
	q = L->elem + L->length - 1;
	for (; p < q; p++)
		*p = *(p+1);
	*/
	return true; 
}

void ListPrint_Sq(SqList L){
	int len, i;
	len = GetLength_Sq(L);
	for (i = 0; i < len; i++){
		printf("%d",L.elem[i]);	
	}
}

int LocatedElem_Sq(SqList L, int e, bool(*compare)(int, int))
{
//	//在顺序线性表L中查找第1个值与e满足compare()的元素的序位
	int *p,i;
	i = 0;
	p = L.elem;
	while (i < L.length && !(*compare)(p[i],e)) i++;
	if (i < L.length) return i + 1;
	else return 0; 
}

bool compare(int a, int b)
{
	if (a != b) return false;
	else return true;	
}

void MergeList_Sq(SqList La, SqList Lb, SqList *Lc)
{
	//O(La.length + Lb.length)
	int *pa,*pb,*pc,i,j,k;
	i = j = k = 0;
	pa = La.elem;
	pb = Lb.elem;
	Lc->listsize = La.length + Lb.length;
	pc = Lc->elem = (int *)malloc(Lc->listsize * sizeof(int));
	if (!Lc->elem) exit(EXIT_FAILURE);	
	while (i < La.length && j < Lb.length){
		if(pa[i] <= pb[j]) pc[k++] = pa[i++];
		else pc[k++] = pb[j++];
	}
	while (i < La.length) pc[k++] = pa[i++];
	while (j < Lb.length) pc[k++] = pb[j++];
}

int GetLength_Sq(SqList L) {
	return L.length;
}

int GetElem_Sq(SqList L, int i){  
	return L.elem[i-1];
}
void Union(SqList *La,SqList Lb)
{
	//O(La.length x Lb.length)
	int La_len, Lb_len, i;
	La_len = GetLength_Sq(*La);
	Lb_len = GetLength_Sq(Lb);
	for (i = 1; i <= Lb_len; i++){
		int value = GetElem_Sq(Lb,i);
		if (!LocatedElem_Sq(*La, value, compare))
			if(!ListInsert_Sq(La, ++La_len, value)){
				exit(EXIT_FAILURE);
			}		
	}
}

