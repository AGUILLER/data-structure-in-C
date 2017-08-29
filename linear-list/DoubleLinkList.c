#include "DoubleLinkList.h"
#include <stdlib.h>
DuLinkList GetElem_DuL(const DuLinkList L, int i){
	if (i < 1) exit(EXIT_FAILURE);
	int j = 1;
	DuLinkList p = L->next;
	while (p != L && j < i){
		p = p->next;
		j++;
	}
	if (j > i || p == L ){
		printf("Error: find fails in GetElemP_DuL.\n");
		return NULL;
	}
	else return p;
}
bool ListInset_DuL(DuLinkList L, int i, ElemType e){
	//��ͷ�ڵ��˫��ѭ�����Ա�L�е�i��λ��ǰ����Ԫ��e
	//i�ĺϷ�ֵΪ1<=i<=��+1
	DuLinkList p,s;
	if (!(p = GetElem_DuL(L, i))) return false;
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode))){
		printf("Error: malloc fails in LinkInsert_DuL.\n");
		exit(EXIT_FAILURE);
	}
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	p->prior = s;
	s->next = p
	return true;
} 

bool ListDelete_DuL(DuLinkList L, int i, ElemType *e){
	//ɾ����ͷ�ڵ��˫��ѭ�����Ա�L�ĵ�i��Ԫ��,i�ĺϷ�ֵΪ1<=i<=��
	DuLinkList *p;
	if(!(p = GetElem_DuL(L, i))) return false;
	*e = p->data;
	p->prior->next = p->next;
	p->next.prior = p->prior;
	free(p);
	return true; 
}
