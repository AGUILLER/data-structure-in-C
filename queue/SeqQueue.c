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
//	//如出现Q->front为60，Q->rear为40的情况，因此需要加上MAXQSIZE 
//	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
//}
//
//Status QueueIsEmpty(SqQueue Q) {
//	if (Q->front == Q->rear) return TRUE;
//	return FALSE;
//}
//
//Status EnQueue(SqQueue Q, QElemType e) {
//	//如果此时Q->rear为99，使用Q->rear+1 == Q->front判断就会出错 
//	if ((Q->rear + 1) % MAXQSIZE == Q->front) return ERROR;//队列满
//	Q->base[Q->rear] = e; 
//	//依然是防止在99的情况，其它情况正常 
//	Q->rear = (Q->rear + 1) % MAXQSIZE;
//	return OK;
//} 
//
//Status DeQueue(SqQueue Q, QElemType *e) {
//	//若队列不空，则删除Q的队头元素，用e返回其值
//	if (Q->front == Q->rear) return ERROR;
//	*e = Q->base[Q->front];
//	//若Q->front为99，直接+1就会出错 
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
