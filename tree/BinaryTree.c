#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

Status CreateBiTree(BiTree *T) {
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '.') *T = NULL;
	else {
		if ((*T = (BiTNode *)malloc(sizeof(BiTNode))) == NULL){
			printf("making:\n");
			return ERROR;	
		}
		(*T)->data = ch;           //���ɸ���� 
		CreateBiTree(&((*T)->lchild));//���������� 
		CreateBiTree(&((*T)->rchild));//���������� 
	}
	return OK; 
} 
Status PreOrderTraverse(BiTree T, Status (* Visit)(TElemType e)) {
	//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit 
	if (T != NULL) {
		//printf("fuck:\n");
//		if((*Visit)(T->data) == OK)
//			if (PreOrderTraverse(T->lchild, Visit))
//				if (PreOrderTraverse(T->rchild, Visit)) return OK;
//		return ERROR; 
		(*Visit)(T->data);
		PreOrderTraverse(T->lchild, Visit);
		PreOrderTraverse(T->rchild, Visit);
	} 
	//���ǵ���NULL����ղ��� 
	return 	OK;
} 

Status PrintElement(TElemType e) {
	//printf("next:\n");
	printf("%c", e);
	return OK;
}
