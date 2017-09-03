#include <stdio.h>
#include <stdlib.h>
#include "StackApp.h" 
#include "Recursion.h" 

int c = 0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//定义墙元素为2 可走路径为0 已知路径为curStep 不能够通过的路径为-1 
int Maze[MAZESCALE][MAZESCALE] = {{ 2,2,2,2,2,2,2,2,2,2 },
								  { 2,0,0,2,0,0,0,2,0,2 },
								  { 2,0,0,2,0,0,0,2,0,2 },
								  { 2,0,0,0,0,2,2,0,0,2 },
								  { 2,0,2,2,2,0,0,0,0,2 },
								  { 2,0,0,0,2,0,0,0,0,2 },
								  { 2,0,2,0,0,0,2,0,2,2 },
								  { 2,0,0,0,0,0,0,0,0,2 },
								  { 2,2,2,2,2,2,2,2,0,2 },
								  { 2,2,2,2,2,2,2,2,2,2 }};

int main(int argc, char *argv[]) {
	//conversion();
//	PosType start = { 1,1 };
//	PosType end = { 8,8 };
//	printf("%d %d\n", end.x, end.y);
//
//	MazePath(start, end);
//	printf("OUT...\n");
//	int i, j;
//	//打印出结果迷宫矩阵 
//	for (i = 0;i<MAZESCALE;i++)
//	{
//		for (j = 0;j<MAZESCALE;j++)
//		{
//			printf("%d   ", Maze[i][j]);
//		}
//		printf("\n");
//	}
//	printf("OUT...\n");
    char a,b,c;
	a = 'a';
	b = 'b';
	c = 'c'; 
    hanoi(3, a, b, c);
	system("pause");
	return 0;
}
