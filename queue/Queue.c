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
	//�ͷ�һ���ڴ�Ҫע������
	//1.ʹ��free�ͷ�ָ������ָ��
	//2.�޸ĸ�ָ��ָ�� 
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
	//����Ԫ��e��ΪQ���µĶ�βԪ��  
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
	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR 
	QueuePtr p;
	if (Q->front == Q->rear) return ERROR; 
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	//һ������£�ɾ������ͷԪ��ʱ�����޸�ͷ����е�ָ��
	//���������е����һ��Ԫ�ر�ɾ���󣬶��е�βָ��Ҳ��ʧ��
	//���Ҫ��βָ������ָ��ͷ��� 
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
