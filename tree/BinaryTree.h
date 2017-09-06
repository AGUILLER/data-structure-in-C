#ifndef BINARYTREE_H
#define BINARYTREE_H 
//----二叉树的二叉链表存储表示 
#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;

typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//按先序遍历次序输入二叉树中结点的值（一个字符），空字符表示空树 
Status CreateBiTree(BiTree T); 
Status PreOrderTraverse(BiTree T, Status (* Visit)(TElemType e));
Status PrintElement(TElemType e);

#endif
