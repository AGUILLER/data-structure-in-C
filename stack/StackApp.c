#include "StackApp.h"
#include <stdlib.h>
#include <stdio.h>

Status InitStack(SqStack S) {
	S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (S->base == NULL) {
		printf("Error: malloc fails in InitStack.\n");
		exit(EXIT_FAILURE);
	}
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
	*e = *(S->top - 1);
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

//void conversion() {
//	SqStack S = (SqStack)malloc(sizeof(struct SqStack));
//	int N, e;
//	Status status;
//	printf("please input a demical number:");
//	
//	status = InitStack(S);
//	scanf("%d", &N);
//	while (N) {
//		Push(S, N%8);
//		N = N/8;
//	}
//	printf("converse to octonary number:");
//	StackTraverse(S,visit);
//	while (!StackIsEmpty(S)) {
//		Pop(S, &e);
//		printf("%d", e);
//	}
//	
//	DestroyStack(S);
//} 

//void LineEdit() {
//	//利用字符栈S，从终端接收一行传送至调用过程的数据区
//	char ch, e;
//	SqStack S = (SqStack)malloc(sizeof(struct SqStack));
//	InitStack(S);
//	ch = getchar();
//	while (ch != EOF) {
//		while (ch != EOF && ch != '\n') {
//			switch (ch) {
//				case '#': Pop(S,&e);  break;
//				case '@': ClearStack(S); break;
//				default: Push(S, ch); break; 
//			}
//			ch = getchar();
//		}
//		ClearStack(S);
//		if (ch != EOF) ch =getchar();
//	}
//	DestroyStack(S);
//}

Bool Pass(PosType pos) {
	if (Maze[pos.x][pos.y] == 0) {
		return TRUE;
	}
	return FALSE;
}

PosType NextPos(PosType curstep, int di) { //顺时针 
	PosType next;
	int x, y;
	x = curstep.x;
	y = curstep.y;
	switch (di) {
	case 1: { //东 
		next.x = x;
		next.y = y + 1;
		break;
	}
	case 2: {//南 
		next.x = x + 1;
		next.y = y;
		break;
	}
	case 3: {//西 
		next.x = x;
		next.y = y - 1;
		break;
	}
	case 4: {
		next.x = x - 1;
		next.y = y;
		break;
	}
	default: break;
	}
	return next;
}

void FootPrint(PosType p) {
	Maze[p.x][p.y] = TRACK;
}

void MarkPrint(PosType p) {
	Maze[p.x][p.y] = NOWAY;
}

Status MazePath(PosType start, PosType end) {
	SqStack S = (SqStack)malloc(sizeof(struct SqStack));
	SElemType e;
	PosType curpos = start;
	int curstep = 1;
	InitStack(S);
	
	do {
		if (Pass(curpos)) {
			FootPrint(curpos); //留下足迹，已走过 
			e.ord = curstep;
			e.seat = curpos;
			e.di = 1;
			Push(S, e);
			printf("%d %d\n", curpos.x, curpos.y);
			printf("%d %d\n", end.x, end.y);
			if ((curpos.x == end.x) && (curpos.y == end.y)) return TRUE;
			curpos = NextPos(curpos, 1);
			curstep++;
			
		}
		else {
			if (!StackIsEmpty(S)) {
				Pop(S, &e);
				while (e.di == 4 && !StackIsEmpty(S)) {
					MarkPrint(e.seat);
					Pop(S, &e);  //取出新栈顶元素 
				}
				if (e.di < 4) {
					e.di++;
					Push(S, e);
					curpos = NextPos(e.seat, e.di);
				}
			}
		}
	} while (!StackIsEmpty(S)/*&& (curpos.x < MAZESCALE - 1) && (curpos.y < MAZESCALE - 1)*/);
	printf("OUT...\n");
	int i, j;
	//打印出结果迷宫矩阵 
	for (i = 0;i<MAZESCALE;i++)
	{
		for (j = 0;j<MAZESCALE;j++)
		{
			printf("%d   ", Maze[i][j]);
		}
		printf("\n");
	}
	return FALSE;
}
