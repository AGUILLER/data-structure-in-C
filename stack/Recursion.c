#include "Recursion.h"
#include <stdio.h>
void hanoi(int n, char x, char y, char z) {
	//将塔座x上按直径由小到大且自上而下编号为1至n的n个圆盘
	//按规则搬到z上，y可以作为辅助塔座
	//搬动操作move(x,n,z)c是初值为0的全局变量，对搬动计数，
	//
	if (n == 1) {
		move(x, 1, z);
	} 
	else {
		hanoi(n-1, x, z, y);
		move(x, n, z);
		hanoi(n-1, y, x, z);
	}
} 

void move(char start, int n, char end) {
	printf("%d.Move disk %d from %c to %c.\n",++c, n, start, end);
}
