#ifndef QUEUE_H
#define QUEUE_H

//ADT Queue�ı�ʾ��ʵ��
//-----��������------���е���ʽ�洢�ṹ 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0 
typedef int QElemType;

typedef int Status; 

typedef struct QNode {
	QElemType data;
	struct QNode *next;
} QNode, *QueuePtr; 

typedef struct {
	QueuePtr front;  //��ͷָ�� 
	QueuePtr rear;   //��βָ�� 
}*LinkQueue;

Status InitQueue(LinkQueue Q);
Status DestroyQueue(LinkQueue Q);
Status ClearQueue(LinkQueue Q);
Status QueueIsEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QElemType *e);
//����Ԫ��e��ΪQ���µĶ�βԪ�� 
Status EnQueue(LinkQueue Q, QElemType e);
//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR 
Status DeQueue(LinkQueue Q, QElemType *e);
//�Ӷ�ͷ����β���ζԶ���Q�е�����Ԫ�ص���visit���� 
Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType e));
Status visit(QElemType e);
#endif
