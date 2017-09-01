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

//记录通道块在迷宫矩阵中的位置 
typedef struct Position {
	int x;   //横坐标 
	int y;   //纵坐标 
} PosType;

typedef struct SMazeElemType{
	int ord;       //通道块在路径上的序号 
	PosType seat;  //通道块在迷宫中“坐标位置” 
	int di;        //从此通道块走向下一通道块的“方向” 
}SElemType; 

bool Pass(PosType pos);

PosType Next(PosType curstep, int di);
//留下足迹 
void FootPrint(PosType p);
//留下不能通过的标记 
void MarkPrint(PosType p);
Status MazePath(int **maze, PosType start, PosType end); 
void conversion(); 

void LineEdit(); 

#endif
