#include <stdio.h>
#include <stdlib.h>
//#include "SeqQueue.h" 
#include "Queue.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, e;
	//SqQueue Q = (SqQueue)malloc(sizeof(SqQueue));
	LinkQueue Q = (LinkQueue)malloc(sizeof(LinkQueue));
	printf("Start:");
	InitQueue(Q);

	for (i = 0; i < 15; i++){
		EnQueue(Q, i);
	}
	QueueTraverse(Q, visit);
	printf("\n");
	for (i = 0; i < 10; i++){
		DeQueue(Q, &e);
	}
	
	QueueTraverse(Q, visit);
	printf("\n");
	for (i = 15; i < 25; i++) {
		EnQueue(Q, i);
	}
	QueueTraverse(Q, visit);
	printf("\n");
    DestroyQueue(Q);
	free(Q);
	return 0;
}
