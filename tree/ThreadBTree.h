#ifndef THREADBTREE_H
#define THREADBTREE_H

#define OK 1
#define ERROR 0

typedef int Status;
typedef int TElemType;

//----����������---- 

//Link == 0:ָ�룻Thread == 1������ 
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
//��������������������� 
void InThreading(BiThrTree p);

#endif 
