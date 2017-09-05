#ifndef QUEUE_H
#define QUEUE_H

//ADT Queue的表示与实现
//-----单链队列------队列的链式存储结构 
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
	QueuePtr front;  //队头指针 
	QueuePtr rear;   //队尾指针 
}*LinkQueue;

Status InitQueue(LinkQueue Q);
Status DestroyQueue(LinkQueue Q);
Status ClearQueue(LinkQueue Q);
Status QueueIsEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead(LinkQueue Q, QElemType *e);
//插入元素e，为Q的新的队尾元素 
Status EnQueue(LinkQueue Q, QElemType e);
//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR 
Status DeQueue(LinkQueue Q, QElemType *e);
//从队头到队尾依次对队列Q中的所有元素调用visit函数 
Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType e));
Status visit(QElemType e);
#endif
