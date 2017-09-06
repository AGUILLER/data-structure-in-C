//#include "SeqQueue.h"
//#include <stdlib.h>
//#include <stdio.h>
//Status InitQueue(SqQueue Q) {
//	Q->base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
//	if (Q->base == NULL) {
//		printf("ERROR: malloc fails in InitQueue.\n");
//		exit(EXIT_FAILURE);
//	}
//	Q->front = Q->rear = 0;
//	return OK;
//} 
//
//int QueueLength(SqQueue	Q) {
//	//�����Q->frontΪ60��Q->rearΪ40������������Ҫ����MAXQSIZE 
//	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
//}
//
//Status QueueIsEmpty(SqQueue Q) {
//	if (Q->front == Q->rear) return TRUE;
//	return FALSE;
//}
//
//Status EnQueue(SqQueue Q, QElemType e) {
//	//�����ʱQ->rearΪ99��ʹ��Q->rear+1 == Q->front�жϾͻ���� 
//	if ((Q->rear + 1) % MAXQSIZE == Q->front) return ERROR;//������
//	Q->base[Q->rear] = e; 
//	//��Ȼ�Ƿ�ֹ��99������������������ 
//	Q->rear = (Q->rear + 1) % MAXQSIZE;
//	return OK;
//} 
//
//Status DeQueue(SqQueue Q, QElemType *e) {
//	//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
//	if (Q->front == Q->rear) return ERROR;
//	*e = Q->base[Q->front];
//	//��Q->frontΪ99��ֱ��+1�ͻ���� 
//	Q->front = (Q->front + 1) % MAXQSIZE; 
//}
//
//Status QueueTraverse(SqQueue Q, Status(*visit)(QElemType e)) {
//	int index;
//	index = Q->front;
//	if (QueueIsEmpty(Q)) return ERROR; 
//	while (index != Q->rear) {
//		visit(Q->base[index]);
//		index = (index + 1) % MAXQSIZE; 
//	}
//	return OK; 
//} 
//Status visit(QElemType e) {
//	printf("%d ", e);
//	return OK;
//}
