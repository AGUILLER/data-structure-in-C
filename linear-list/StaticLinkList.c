#include "StaticLinkList.h"

void InitSpace_SL(SLinkList space){
	int i;
	for (i = 0; i < MAXSIZE-1; i++){
		space[i].cur = i+1;
	}
	space[MAXSIZE-1].cur = 0;
}

int Malloc_SL(SLinkList space){
	//���spaceΪ���õ�����
	int i;
	i = space[0].cur;
	if (i) space[0].cur = space[i].cur;
	return i; 
}

void Free_SL(SLinkList space, int k){
	//���±�Ϊk�Ŀ��нڵ���յ��������� 
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void difference(SLinkList space, int *S){
	//�������뼯��A��B�е�Ԫ�أ���һά����space�н���
	//��ʾ����(A-B)U(B-A)�ľ�̬����SΪ��ͷָ��
	//���ÿռ��㹻��space[0].curΪ��ͷָ��
	InitSpace_SL(space);//��ʼ�����ÿռ䣬�տ�ʼ���пռ䶼û������˶��Ǳ��пռ� 
	*S = Malloc_SL(space);
	int r = *S;//rָ��洢����S�ĵ�ǰ���ڵ�
	printf("%d",*S);
	int m,n,j;
	printf("Please input the capacity of Collection A and B:"); 
	scanf("%d%d",&m,&n);
	//��������A����
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
		p = *S;//p��¼��ǰ��ѯ���Ľڵ�λ�õ�ǰһ���ڵ� 
		k = space[(*S)].cur;//k��ʱָ�򼯺�A�еĵ�һ��Ԫ�� 
		//printf("KK%d\n",k);
		while (k != space[r].cur && space[k].data != b){
			p = k;
			k = space[k].cur;
		}
		if ( k == space[r].cur) {//������ǰ���в����ڸ�Ԫ�� 
			int i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i; 
			//printf("RRR%d\n",r);
			//printf("IIII%d\n",i);
		}
		else { //��Ԫ���Ѿ��ڱ��У�ɾ���� 
			space[p].cur = space[k].cur;
			Free_SL(space,k);
			if (r==k) r = p;//��ɾ������r��ָ�Ľڵ㣨���������һ���ڵ㣩��
			//�������һ���ڵ� 
		}		
	}		 
}
int LocateElem_SL(SLinkList S, int e){
	//�ھ�̬�������Ա��в��ҵ�һ��ֵΪe��Ԫ��
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
