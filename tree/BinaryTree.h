#ifndef BINARYTREE_H
#define BINARYTREE_H 
//----�������Ķ�������洢��ʾ 
#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//�����������������������н���ֵ��һ���ַ��������ַ���ʾ���� 
Status CreateBiTree(BiTree T); 
Status PreOrderTraverse(BiTree T, Status (* Visit)(TElemType e));
Status PrintElement(TElemType e);

#endif
