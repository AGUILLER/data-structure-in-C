#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "SeqList.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	LinkList first,second,third;
	//bool flag;
	int e;
	first = (LinkList)malloc(sizeof(struct LNode));
    second = (LinkList)malloc(sizeof(struct LNode));
    third = (LinkList)malloc(sizeof(struct LNode));
	//first = create_list(first);
	CreateList_L(first, 6);
	print_list(first);
	printf("\n"); 
	CreateList_L(second, 4);
	//flag = ListDelete_L(first, 4, &e);
	//print_list(first);
	printf("\n");
	MergeList_L (first, second, third); 
	print_list(third);
	//printf("1111111\n");
	//printf("%d",e);
//    SqList la;
//    bool flag;
//    flag = InitList_Sq(&la);
//	int i; 
//    for (i = 1; i <= 10; i++){
//    	ListInsert_Sq(&la, i, i);
//	}
//	ListPrint_Sq(la);
	return 0;

}
