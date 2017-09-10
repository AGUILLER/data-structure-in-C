#include "ThreadBTree.h"
#include <stdlib.h>

Status InOrderTraverse_Thr(BiThrTree T, Status (*Visit)(TElemType e));

Status InOrderThreading(BiThrTree Thrt, BiThrTree T);

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
		结点为最有下方的叶子结点，该叶子结点的后继指向p*/ 
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
