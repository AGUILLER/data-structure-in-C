#pragma once
#ifndef STACKAPP_H
#define STACKAPP_H

//#include "SeqStack.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int Bool;

#define TRACK 1
#define NOWAY 8 

#define MAZESCALE 10 

extern int Maze[MAZESCALE][MAZESCALE];
typedef enum {
	EAST,
	SOUTH,
	WEST,
	NORTH
} Direction;

//typedef int SElemType;
typedef struct SqStack {
	struct SElemType *base;   //在栈构造之前和销毁之后，base的值为NULL 
	struct SElemType *top;    //栈顶指针 
	int stacksize;     //当前已分配的存储空间(当前最大容量)，以元素为单元 
}*SqStack, mystack;


//记录通道块在迷宫矩阵中的位置 
typedef struct Position {
	int x;   //横坐标 
	int y;   //纵坐标 
} PosType;

typedef struct SElemType {
	int ord;       //通道块在路径上的序号 
	PosType seat;  //通道块在迷宫中“坐标位置” 
	int di;        //从此通道块走向下一通道块的“方向” 
}SElemType;

//构造一个空栈 
Status InitStack(SqStack S);
//销毁栈S 
Status DestroyStack(SqStack S);
//把S置为空栈 
Status ClearStack(SqStack S);
//若栈S为空栈，返回TRUE，否则返回FALSE 
Status StackIsEmpty(SqStack S);
//返回S的元素个数 
int StackLength(SqStack S);
//若栈不为空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR 
Status GetTop(SqStack S, SElemType *e);
//插入元素e为新的栈顶元素 
Status Push(SqStack S, SElemType e);
//若栈不空，则删除栈顶元素，用e返回其值，并返回OK，否则返回ERROR 
Status Pop(SqStack S, SElemType *e);

Bool Pass(PosType pos);

PosType NextPos(PosType curstep, int di);
//留下足迹 
void FootPrint(PosType p);
//留下不能通过的标记 
void MarkPrint(PosType p);
Status MazePath(PosType start, PosType end);
void conversion();

void LineEdit();

#endif
