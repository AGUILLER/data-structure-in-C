#include "StackApp.h"
#include <stdlib.h>
#include <stdio.h>
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

bool Pass(PosType pos) {
	if (Maze[pos.x][pos.y] == 0) {
		return TRUE;
	}
	return FALSE;
}

PosType NextPos(PosType curstep, int di) { //顺时针 
	PosType next;
	int x,y;
	x = curstep.x;
	y = curstep.y;
	switch(di) {
		case 1: { //东 
			next.x = x + 1;
			next.y = y; 
			break;
		}
		case 2: {//南 
			next.x = x;
			next.y = y + 1;
			break;
		}
		case 3: {//西 
			next.x = x - 1;
			next.y = y; 
			break;
		}
		case 4: {
			next.x = x;
			next.y = y - 1
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

Status MazePath(int **maze, PosType start, PosType end) {
	MyStack S;
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
			Push(&S, e);
			if (curpos == end)
				return TRUE;
			curpos = NextPos(curpos, 1);
			curstep++;
		}
		else {
			if (!StackIsEmpty) {
				Pop(S, &e);
				while (e.di == 4 && !StackIsEmpty(S)) {
					MarkPrint(e.seat);
					Pop(S, &e)  //取出新栈顶元素 
				}
				if (e.di < 4) {
					e.di++;
					Push(S, e);
					curpos = NextPos(e.seat, e.di);
				}
			}
		}
	} while(!StackIsEmpty(S));
	return FALSE;
}
