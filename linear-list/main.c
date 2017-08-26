#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "SeqList.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct LNode *first = NULL;
	bool flag;
	int e;
	first = create_list(first);
	print_list(first);
	flag = ListDelete_L(first, 4, &e);
	print_list(first);
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
