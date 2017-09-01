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
	SElemType *base;   //��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType *top;    //ջ��ָ�� 
	int stacksize;     //��ǰ�ѷ���Ĵ洢�ռ�(��ǰ�������)����Ԫ��Ϊ��Ԫ 
}*SqStack, mystack;


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

//��ջ�׵�ջ�����ζ�ջ�е�ÿһ��Ԫ�ص��ú���visit() 
Status StackTraverse(SqStack S, Status(*visit)(SElemType));

Status visit(SElemType e);
#endif
