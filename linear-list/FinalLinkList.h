#ifndef FINALLINKLIST_H
#define FINALLINKLIST_H

#define OK 1
#define ERROR 0
typedef int Status;
 
typedef int ElemType;
typedef struct LNode {   //�ڵ����� 
	ElemType data;       //������ 
	struct LNode *next;  //ָ���� 
}*Link, *Position;

typedef struct {         //�������� 
	Link head, tail;     //�ֱ�ָ�����Ա��е�ͷ�������һ���ڵ� 
	int len;             //ָʾ���Ա�������Ԫ�صĸ��� 
}*LinkList;

//����ڵ�ռ䣬ʹָ��pָ������ռ䣬��������ֵΪe�����ɹ����򷵻�OK�����򷵻�ERROR 
Status MakeNode(Link p, ElemType e);

//�ͷ�p��ָ�ڵ�
void FreeNode(Link p);

//����һ���յ���������
Status InitList(LinkList L); 

//��ָ��s��ָ���˴���ָ����������һ���ڵ����������Ա�L�����һ���ڵ�֮��
//���ı�����L��βָ��tailָ���µ�β�ڵ� 
Status Append(LinkList L, Link s);

//��֪hָ�����������ͷ�ڵ㣬ɾ�������еĵ�һ���ڵ㲢��q����
Status DelFirst(Link h, Link q); 

//��֪hָ�����������ͷ��㣨���ǵ�һ���ڵ㣩����s��ָ�ڵ�����ڵ�һ���ڵ�֮ǰ 
Status InsFirst(Link h, Link s); 

//�ڴ�ͷ�ڵ�ĵ������Ա�L�ĵ�i��Ԫ��֮ǰ����Ԫ��e
Status ListInsert_L(LinkList L,int i, ElemType e);

//������������L�е�i���ڵ��ָ��p�����ɹ�����OK�����򷵻�ERROR 
Status LocatePos(LinkList L, int i, Link p);

//��֪pָ����������L�е�һ���ڵ㣬����p��ָ�ڵ��ֱ�Ӻ�� 
Position NextPos(LinkList L, Link p); 

//��֪������La��Lb��Ԫ�ذ�ֵ�ǵݼ����С�
//�鲢La��Lb�õ��µĵ�����Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����� 
Status MergeList_L(LinkList La, LinkList Lb, LinkList Lc, int (*compare)(ElemType,ElemTupe)); 
#endif
