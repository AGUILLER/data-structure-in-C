#include "StaticLinkList.h"

void InitSpace_SL(SLinkList space){
	int i;
	for (i = 0; i < MAXSIZE-1; i++){
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;
}

int Malloc_SL(SLinkList space){
	//这个space为备用的链表
	int i;
	i = space[0].cur;
	if (i) space[0].cur = space[i].cur;
	return i; 
}

void Free_SL(SLinkList space, int k){
	//将下标为k的空闲节点回收到备用链表 
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void difference(SLinkList space, int *S){
	//依次输入集合A和B中的元素，在一维数组space中建立
	//表示集合(A-B)U(B-A)的静态链表，S为其头指针
	//备用空间足够大，space[0].cur为其头指针
	InitSpace_SL(space);//初始化必用空间，刚开始所有空间都没有用因此都是备有空间 
	*S = Malloc_SL(space);
	int r = *S;//r指向存储集合S的当前最后节点
	printf("%d",*S);
	int m,n,j;
	printf("Please input the capacity of Collection A and B:"); 
	scanf("%d%d",&m,&n);
	//建立集合A链表
	printf("A:");
	for (j = 1; j <= m; j++){
		
		int i = Malloc_SL(space);
		scanf("%d",&(space[i].data));
		space[r].cur = i;
		r = i;		
	}
	space[r].cur = 0;
	printf("B:");
	for (j = 1; j <= n; j++){
		
		int b,p,k;
		scanf("%d",&b);
		p = *S;//p记录当前查询到的节点位置的前一个节点 
		k = space[(*S)].cur;//k此时指向集合A中的第一个元素 
		//printf("KK%d\n",k);
		while (k != space[r].cur && space[k].data != b){
			p = k;
			k = space[k].cur;
		}
		if ( k == space[r].cur) {//表明当前表中不存在该元素 
			int i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i; 
			//printf("RRR%d\n",r);
			//printf("IIII%d\n",i);
		}
		else { //该元素已经在表中，删除它 
			space[p].cur = space[k].cur;
			Free_SL(space,k);
			if (r==k) r = p;//若删除的是r所指的节点（即链表最后一个节点），
			//则变跟最后一个节点 
		}		
	}		 
}
int LocateElem_SL(SLinkList S, int e){
	//在静态单链线性表中查找第一个值为e的元素
	int i = S[0].cur;
	while (i && S[i].data != e) {
		i = S[i].cur;
	}
	return i;
}

void PrintOut_SL(LinkList space,const int S){
	int p = space[S].cur;
	while (p != 0) {
		printf("%d ",space[p].data);
		p = space[p].cur;
	}
	printf("\n");
}
