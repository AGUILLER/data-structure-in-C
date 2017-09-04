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

Status DestroyQueue(LinkQueue Q) {
	while (Q->front != NULL) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
