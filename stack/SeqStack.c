#include "SeqStack.h"
#include <stdlib.h>
Status InitStack(SqStack S){
	//printf("11111");
	S->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(S->base == NULL) {
		printf("Error: malloc fails in InitStack.\n");
		exit(EXIT_FAILURE);
	}
	//printf("22222");
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
} 

Status DestroyStack(SqStack S) {
	free(S->base);
	S->base = S->top = NULL;
	S->stacksize = 0;
	return OK;
}

Status ClearStack(SqStack S) {
	S->top = S->base;
	return OK; 
}

Status StackIsEmpty(SqStack S) {
	if (S->base == S->top) return TRUE;
	return FALSE;
}

int StackLength(SqStack S) {
	return S->top - S->base;
} 

Status GetTop(SqStack S, SElemType *e) {
	if (S->base == S->top) return ERROR;
	//非空栈中的栈顶元素始终在栈顶元素的下一个位置上 
	*e = *(S->top-1);
	return OK; 	
} 

Status Push(SqStack S, SElemType e) {
	if ((S->top - S->base) >= S->stacksize) {//栈满，追加存储空间 
		S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (S->base == NULL) {
		printf("Error: malloc fails in Push.\n");
		exit(EXIT_FAILURE);
	}
	S->top = S->base + S->stacksize;
	S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
	return OK;
} 

Status Pop(SqStack S, SElemType *e) {
	if (S->top == S->base) return ERROR;
	*e = *(--S->top);
	return OK; 
}

Status StackTraverse(SqStack S, Status(*visit)(SElemType)) {
	SElemType *p;
	p = S->base;
	while (S->top > p) {
		(*visit)(*p++);
		printf("\n");
	}
	return OK;
}

Status visit(SElemType e) {
	printf("%d", e);
	return OK;
}
