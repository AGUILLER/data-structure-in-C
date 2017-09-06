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
		T->data = ch;           //���ɸ���� 
		CreateBiTree(T->lchild);//���������� 
		CreateBiTree(T->rchild);//���������� 
	}
	return OK; 
} 
Status PreOrderTraverse(BiTree T, Status (* Visit)(TElemType e)) {
	//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit 
	if (T != NULL) {
		if((*Visit)(T->data) == OK)
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR; 
	} 
	//���ǵ���NULL����ղ��� 
} 

Status PrintElement(TElemType e) {
	printf("% c", e);
	return OK;
}
