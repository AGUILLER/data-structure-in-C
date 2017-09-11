#include "ThreadBTree.h"
#include <stdlib.h>

Status InOrderTraverse_Thr(BiThrTree T, Status (*Visit)(TElemType e)) {
	BiThrTree p;
	p = T->lchild;
	while (p != T) { //�������������ʱ��p == T 
		while (p->LTag == Link) p = p->lchild;
		if(!(*Visit)(p->data)) return ERROR;
		while(p->RTag == Thread && p->rchild != T) {
			p = p->rchild;
			(*Visit)(p->data);
		}
		p = p->rchild;
	}
}

Status InOrderThreading(BiThrTree Thrt, BiThrTree T) {
	//�������������T��������������������Thrtָ��ͷ���
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrTree)))) {
		printf("ERROR.\n");
		exit(EXIT_FAILURE);
	} 
	Thrt->LTag = Link;
	Thrt->RTag = Thread;
	Thrt->rchild = Thrt;
	if (!T) Thrt->lchild = Thrt;
	else {
		Thrt->lchild = T;
		pre = Thrt;
		InThreading(T);
		pre->rchild = Thrt;  //���һ����������� 
		pre->RTag = Thread;
		Thrt->lchild = pre;
	}
	return OK;
} 

void InThreading(BiThrTree p) {
	if (p != NULL) {
		InThreading(p->lchild);
		/*�����ѭ����������������������
		���������
		1. p��������Ϊ�գ���ʱpΪҶ�ӽ�� 
		2. p��������ֻ��һ������㣨��p->lchildΪҶ�ӽ�㣩��
		��ʱp->lchild��������ָ����Ϊ��,����ǰ��ΪPre
		����ʹ����ָ��ָ��pre��
		3. p���������ĸ߶�>=2;��ʱ��p���������������ʵ�
		���Ϊ���ҷ��Ľ�㣬�ý��ĺ��ָ��p*/ 
		if (!p->lchild) { //p->lchildΪ�գ���ʱpΪҶ�ӽ�� 
			p->LTag = Thread;
			p->lchild = pre;
		} 
		if (!pre->rchild) {
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild);
	}
} 
