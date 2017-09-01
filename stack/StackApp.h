#ifndef STACKAPP_H
#define STACKAPP_H

#include "SeqStack.h"

#define EOF '$' 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define TRACK 1
#define NOWAY -1 
#define MAZESCALE 10 

int Maze[MazeScale][MazeScale]={{2,2,2,2,2,2,2,2,2,2},
								{2,0,0,2,0,0,0,2,0,2},
								{2,0,0,2,0,0,0,2,0,2},
								{2,0,0,0,0,2,2,0,0,2},
								{2,0,2,2,2,0,0,0,0,2},
								{2,0,0,0,2,0,0,0,0,2},
								{2,0,2,0,0,0,2,0,0,2},
								{2,0,2,2,2,0,2,2,0,2},
								{2,2,0,0,0,0,0,0,0,2},
								{2,2,2,2,2,2,2,2,2,2}};

//��¼ͨ�������Թ������е�λ�� 
typedef struct Position {
	int x;   //������ 
	int y;   //������ 
} PosType;

typedef struct SMazeElemType{
	int ord;       //ͨ������·���ϵ���� 
	PosType seat;  //ͨ�������Թ��С�����λ�á� 
	int di;        //�Ӵ�ͨ����������һͨ����ġ����� 
}SElemType; 

bool Pass(PosType pos);

PosType Next(PosType curstep, int di);
//�����㼣 
void FootPrint(PosType p);
//���²���ͨ���ı�� 
void MarkPrint(PosType p);
Status MazePath(int **maze, PosType start, PosType end); 
void conversion(); 

void LineEdit(); 

#endif
