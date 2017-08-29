#ifndef FINALLINKLIST_H
#define FINALLINKLIST_H

#define OK 1
#define ERROR 0
typedef int Status;
 
typedef int ElemType;
typedef struct LNode {   //节点类型 
	ElemType data;       //数据域 
	struct LNode *next;  //指针域 
}*Link, *Position;

typedef struct {         //链表类型 
	Link head, tail;     //分别指向线性表中的头结点和最后一个节点 
	int len;             //指示线性表中数据元素的个数 
}*LinkList;

//分配节点空间，使指针p指向这个空间，其数据域值为e，若成功，则返回OK；否则返回ERROR 
Status MakeNode(Link p, ElemType e);

//释放p所指节点
void FreeNode(Link p);

//构造一个空的线性链表
Status InitList(LinkList L); 

//将指针s所指（彼此以指针相链）的一串节点链接在线性表L的最后一个节点之后
//并改变链表L的尾指针tail指向新的尾节点 
Status Append(LinkList L, Link s);

//已知h指向线性链表的头节点，删除链表中的第一个节点并以q返回
Status DelFirst(Link h, Link q); 

//已知h指向线性链表的头结点（不是第一个节点），将s所指节点插入在第一个节点之前 
Status InsFirst(Link h, Link s); 

//在带头节点的单链线性表L的第i个元素之前插入元素e
Status ListInsert_L(LinkList L,int i, ElemType e);

//返回线性链表L中第i个节点给指针p，若成功返回OK，否则返回ERROR 
Status LocatePos(LinkList L, int i, Link p);

//已知p指向线性链表L中的一个节点，返回p所指节点的直接后继 
Position NextPos(LinkList L, Link p); 

//已知单链表La和Lb的元素按值非递减排列。
//归并La和Lb得到新的单链表Lc，Lc的元素也按值非递减排列 
Status MergeList_L(LinkList La, LinkList Lb, LinkList Lc, int (*compare)(ElemType,ElemTupe)); 
#endif
