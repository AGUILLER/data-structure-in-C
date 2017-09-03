#include "Recursion.h"
#include <stdio.h>
void hanoi(int n, char x, char y, char z) {
	//������x�ϰ�ֱ����С���������϶��±��Ϊ1��n��n��Բ��
	//������ᵽz�ϣ�y������Ϊ��������
	//�ᶯ����move(x,n,z)c�ǳ�ֵΪ0��ȫ�ֱ������԰ᶯ������
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
