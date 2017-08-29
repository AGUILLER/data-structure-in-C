#include "FinalLinkList.h"

Status ListInsert_L(LinkList L,int i, ElemType e){
	Link h,s;
	if (!LocatePos(len, i-1, h)) return ERROR;
	if (!MakeNode(s, e)) return ERROR;
	//���ڴӵ�i���ڵ㿪ʼ��������i-1���ڵ�������ͷ�ڵ� 
	InsFirst(h, s);
	return OK; 
	
} 

Status MergeList_L(LinkList La, LinkList Lb, LinkList Lc, int (*compare)(ElemType,ElemTupe)){
	Link ha,hb,pa,pb;
	if(!InitList(Lc)) return ERROR;
	ha = GetHead(La);hb = GetHead(Lb);//ha,hb�ֱ�ָ��La��Lb��ͷ�ڵ�
	pa = NextPos(La,ha);pb = NextPos(Lb,hb);//pa,pb�ֱ�ָ��La��Lb�еĵ�ǰ�ȽϽڵ�
	while (pa&&pb){
		ElemType a,b;
		Link q;
		a = GetCurElem(pa);b = GetCurElem(pb);//a,bΪLa,Lb���������ڱȽϵ�Ԫ�� 
		if((*compare)(a,b) <= 0) {
			DelFirst(ha,q);
			Append(Lc,q);
			pa = NextPos(La,ha);
		}
		else {
			DelFirst(hb,q);
			Append(Lc,q);
			pb = NextPos(Lb,hb);
		}
		if (pa) Append(Lc,pa);
		else Append(Lc,pb);
		FreeNode(ha); FreeNode(hb);
		return OK;  	
	}	 	
} 
