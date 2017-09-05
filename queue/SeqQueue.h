#ifndef SEQQUEUE_H
#define SEQQUEUE_H
/*只凭等式Q->font == Q->rear无法判别队列空间是“空”还是“满”
两种处理方式：
1、 另设一个标志位以区别队列的“空”，“满”
2、 少用一个元素空间，约定以“队列头指针在队列尾指针的下一位置”
（即指环状的下一位置）作为“满”状态标识 
*/
//-----循环队列----队列的顺序存储结构 
#define MAXQSIZE 100
typedef int QElemType; //最大队列长度 
typedef struct {
	QElemType *base;   //初始化的动态分配存储空间
	int front;         //头指针，若队列不为空，则指向队头元素 
	int rear;          //尾指针，若队列不空，指向队尾元素的下一个位置 
} *SqQueue; 

Status InitQueue(SqQueue Q); 
int QueueLength(SqQueue	Q);
Status EnQueue(SqQueue Q, QElemType e);
#endif
