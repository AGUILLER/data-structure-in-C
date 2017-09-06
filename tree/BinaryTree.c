#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

Status CreateBiTree(BiTree T) {
	TElemType ch;
	scanf("%c", &ch);
	if (ch == 0x32) T = NULL;
	else {
		if ((T = (BiTNode *)malloc(sizeof(BiTNode))) == NULL)
			return ERROR;
		T->data = ch;           //生成根结点 
		CreateBiTree(T->lchild);//构造左子树 
		CreateBiTree(T->rchild);//构造右子树 
	}
	return OK; 
} 
Status PreOrderTraverse(BiTree T, Status (* Visit)(TElemType e)) {
	//先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit 
	if (T != NULL) {
		if((*Visit)(T->data) == OK)
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR; 
	} 
	//若是等于NULL，则空操作 
} 

Status PrintElement(TElemType e) {
	printf("% c", e);
	return OK;
}
