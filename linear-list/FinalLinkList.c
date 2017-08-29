#include "FinalLinkList.h"

Status ListInsert_L(LinkList L,int i, ElemType e){
	Link h,s;
	if (!LocatePos(len, i-1, h)) return ERROR;
	if (!MakeNode(s, e)) return ERROR;
	//对于从第i个节点开始的链表，第i-1个节点是它的头节点 
	InsFirst(h, s);
	return OK; 
	
} 

Status MergeList_L(LinkList La, LinkList Lb, LinkList Lc, int (*compare)(ElemType,ElemTupe)){
	Link ha,hb,pa,pb;
	if(!InitList(Lc)) return ERROR;
	ha = GetHead(La);hb = GetHead(Lb);//ha,hb分别指向La和Lb的头节点
	pa = NextPos(La,ha);pb = NextPos(Lb,hb);//pa,pb分别指向La和Lb中的当前比较节点
	while (pa&&pb){
		ElemType a,b;
		Link q;
		a = GetCurElem(pa);b = GetCurElem(pb);//a,b为La,Lb两表中正在比较的元素 
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
