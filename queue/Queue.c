#include "Queue.h"
#include <stdlib.h>

Status InitQueue(LinkQueue Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (Q->front == NULL) {
		printf("ERROR: malloc fails in InitQueue.\n");
		exit(EXIT_FAILURE);
	}
	Q->front->next = NULL;
	return OK;
}

Status ClearQueue(LinkQueue Q) {
	QueuePtr p,q;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next == NULL;
	while(p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	return OK;
} 

Status DestroyQueue(LinkQueue Q) {
	//释放一块内存要注意两点
	//1.使用free释放指向它的指针
	//2.修改该指针指向 
	while (Q->front != NULL) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status QueueIsEmpty(LinkQueue Q) {
	if (Q->front == Q->rear) return TRUE;
	else return FALSE;
}

int QueueLength(LinkQueue Q) {
	int i = 0;
	QueuePtr p;
	p = Q->front;
	while (p != Q->rear) {
		i++;
		p = p->next;
	} 
	return i;
}

Status GetHead(LinkQueue Q, QElemType *e) {
	QueuePtr p;
	if (Q->front == Q->rear) return ERROR;
	p = Q->front->next;
	*e = p->data;
	return OK;
}

Status EnQueue(LinkQueue Q, QElemType e) {
	//插入元素e，为Q的新的队尾元素  
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (p == NULL) {
		printf("ERROR: malloc fails in InitQueue.\n");
		exit(EXIT_FAILURE);
	}
	p->data = e;
	p->next = NULL;
	Q->rear->next = P;
	return OK;
} 

Status DeQueue(LinkQueue Q, QElemType *e) {
	//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK，否则返回ERROR 
	QueuePtr p;
	if (Q->front == Q->rear) return ERROR; 
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	//一般情况下，删除队列头元素时仅需修改头结点中的指针
	//但当队列中的最后一个元素被删除后，队列的尾指针也丢失了
	//因此要将尾指针重新指向头结点 
	if (Q->rear == p) Q->rear = Q->front;
	free(p);
	return OK;
}

Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType e)) {
	QueuePtr p;
	p = Q->front;
	while (p != Q->rear) {
		visit(p->next->data);
		p = p->next;
	}
	printf("\n");
	return OK;
} 

Status visit(QElemType e) {
	printf("%d ", e);
	return OK;
}
