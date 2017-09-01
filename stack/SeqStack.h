#ifndef SEQSTACK_H
#define SEQSTACK_H

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
 
typedef int SElemType;
typedef struct SqStack{
	SElemType *base;   //在栈构造之前和销毁之后，base的值为NULL 
	SElemType *top;    //栈顶指针 
	int stacksize;     //当前已分配的存储空间(当前最大容量)，以元素为单元 
}*SqStack, mystack;


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

//从栈底到栈顶依次对栈中的每一个元素调用函数visit() 
Status StackTraverse(SqStack S, Status(*visit)(SElemType));

Status visit(SElemType e);
#endif
