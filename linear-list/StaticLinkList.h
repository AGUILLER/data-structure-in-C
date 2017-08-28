#ifndef STATICLINKLIST_H
#define STATICLINKLIST_H

#define MAXSIZE 100
typedef struct {
	int data;
	int cur;
}component, SLinkList[MAXSIZE];

/*
Ϊ�˱�����������Щ����δ��ʹ�ã�����İ취�ǽ�����δ��ʹ�ù���
�Լ���ɾ���ķ������α�����һ�����õ�����ÿ�����в���ʱ�����
�ӱ���������ȡ�õ�һ���ڵ���Ϊ��������½ڵ㣻��֮��ɾ��ʱ����
������ɾ�������Ľڵ����ӵ����������ϡ� 
*/

void InitSpace_SL(SLinkList space);
int Malloc_SL(SLinkList space);
void Free_SL(SLinkList space, int k);
void difference(SLinkList space, int *S); 
int LocateElem_SL(SLinkList S, int e);
void PrintOut_SL(SLinkList space,const int S); 

#endif
