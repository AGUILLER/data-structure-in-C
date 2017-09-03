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
	struct SElemType *base;   //��ջ����֮ǰ������֮��base��ֵΪNULL 
	struct SElemType *top;    //ջ��ָ�� 
	int stacksize;     //��ǰ�ѷ���Ĵ洢�ռ�(��ǰ�������)����Ԫ��Ϊ��Ԫ 
}*SqStack, mystack;


//��¼ͨ�������Թ������е�λ�� 
typedef struct Position {
	int x;   //������ 
	int y;   //������ 
} PosType;

typedef struct SElemType {
	int ord;       //ͨ������·���ϵ���� 
	PosType seat;  //ͨ�������Թ��С�����λ�á� 
	int di;        //�Ӵ�ͨ����������һͨ����ġ����� 
}SElemType;

//����һ����ջ 
Status InitStack(SqStack S);
//����ջS 
Status DestroyStack(SqStack S);
//��S��Ϊ��ջ 
Status ClearStack(SqStack S);
//��ջSΪ��ջ������TRUE�����򷵻�FALSE 
Status StackIsEmpty(SqStack S);
//����S��Ԫ�ظ��� 
int StackLength(SqStack S);
//��ջ��Ϊ�գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR 
Status GetTop(SqStack S, SElemType *e);
//����Ԫ��eΪ�µ�ջ��Ԫ�� 
Status Push(SqStack S, SElemType e);
//��ջ���գ���ɾ��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR 
Status Pop(SqStack S, SElemType *e);

Bool Pass(PosType pos);

PosType NextPos(PosType curstep, int di);
//�����㼣 
void FootPrint(PosType p);
//���²���ͨ���ı�� 
void MarkPrint(PosType p);
Status MazePath(PosType start, PosType end);
void conversion();

void LineEdit();

#endif
