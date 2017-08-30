#include "StackApp.h"
#include <stdlib.h>
void conversion() {
	SqStack S = (SqStack)malloc(sizeof(struct SqStack));
	int N, e;
	Status status;
	printf("please input a demical number:");
	
	status = InitStack(S);
	scanf("%d", &N);
	while (N) {
		Push(S, N%8);
		N = N/8;
	}
	printf("converse to octonary number:");
	StackTraverse(S,visit);
	while (!StackIsEmpty(S)) {
		Pop(S, &e);
		printf("%d", e);
	}
	
	DestroyStack(S);
} 

void LineEdit() {
	//利用字符栈S，从终端接收一行传送至调用过程的数据区
	char ch, e;
	SqStack S = (SqStack)malloc(sizeof(struct SqStack));
	InitStack(S);
	ch = getchar();
	while (ch != EOF) {
		while (ch != EOF && ch != '\n') {
			switch (ch) {
				case '#': Pop(S,&e);  break;
				case '@': ClearStack(S); break;
				default: Push(S, ch); break; 
			}
			ch = getchar();
		}
		ClearStack(S);
		if (ch != EOF) ch =getchar();
	}
	DestroyStack(S);
}

