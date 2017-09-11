#ifndef THREADBTREE_H
#define THREADBTREE_H

#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;

//----线索二叉树---- 

//Link == 0:指针；Thread == 1：线索 
typedef enum PointerTag {
	Link;
	Thread;
};

typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode *lchild;
	struct BiThrNode *rchild;
	PointerTag LTag;
	PointerTag RTag;
} BiThrNode, *BiThrTree; 

BiThrTree pre;

Status InOrderTraverse_Thr(BiThrTree T, Status (*Visit)(TElemType e));

Status InOrderThreading(BiThrTree Thrt, BiThrTree T);
//中序遍历进行中序线索化 
void InThreading(BiThrTree p);

#endif 
