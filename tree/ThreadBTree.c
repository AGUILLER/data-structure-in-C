#include "ThreadBTree.h"
#include <stdlib.h>

Status InOrderTraverse_Thr(BiThrTree T, Status (*Visit)(TElemType e)) {
	BiThrTree p;
	p = T->lchild;
	while (p != T) { //空树或遍历结束时，p == T 
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
	//中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
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
		pre->rchild = Thrt;  //最后一个结点线索化 
		pre->RTag = Thread;
		Thrt->lchild = pre;
	}
	return OK;
} 

void InThreading(BiThrTree p) {
	if (p != NULL) {
		InThreading(p->lchild);
		/*从这个循环出来：线索化完左子树
		三种情况：
		1. p的左子树为空，此时p为叶子结点 
		2. p的左子树只含一个根结点（即p->lchild为叶子结点），
		此时p->lchild结点的左右指针域为空,则其前驱为Pre
		即，使其左指针指向pre；
		3. p的左子树的高度>=2;此时在p的左子树中最后访问的
		结点为最右方的结点，该结点的后继指向p*/ 
		if (!p->lchild) { //p->lchild为空，此时p为叶子结点 
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
