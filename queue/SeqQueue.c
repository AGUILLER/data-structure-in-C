#include "SeqQueue.h"
#include <stdlib.h>
Status InitQueue(SqQueue Q) {
	Q->base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if (Q->base == NULL) {
		printf("ERROR: malloc fails in InitQueue.\n");
		exit(EXIT_FAILURE);
	}
	Q->front = Q->rear = 0;
	return OK;
} 

int QueueLength(SqQueue	Q) {
	return (Q->rear - Q->front + MAXQSIZE) % MAXQSIZE;
}

int QueueLength(SqQueue	Q) {
	if ((Q->rear + 1) % MAXQSIZE == Q->front) return ERROR;//¶ÓÁÐÂú
	Q->base[Q.rear] = e; 
	Q
}
