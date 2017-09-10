#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	BiTree T = NULL;
	CreateBiTree(&T);
	PreOrderTraverse(T, PrintElement);
	return 0;
}
