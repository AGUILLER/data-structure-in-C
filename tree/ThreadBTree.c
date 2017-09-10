#include "ThreadBTree.h"
#include <stdlib.h>

Status InOrderTraverse_Thr(BiThrTree T, Status (*Visit)(TElemType e));

Status InOrderThreading(BiThrTree Thrt, BiThrTree T);

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
		���Ϊ�����·���Ҷ�ӽ�㣬��Ҷ�ӽ��ĺ��ָ��p*/ 
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
