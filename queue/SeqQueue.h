#ifndef SEQQUEUE_H
#define SEQQUEUE_H
/*ֻƾ��ʽQ->font == Q->rear�޷��б���пռ��ǡ��ա����ǡ�����
���ִ���ʽ��
1�� ����һ����־λ��������еġ��ա���������
2�� ����һ��Ԫ�ؿռ䣬Լ���ԡ�����ͷָ���ڶ���βָ�����һλ�á�
����ָ��״����һλ�ã���Ϊ������״̬��ʶ 
*/
//-----ѭ������----���е�˳��洢�ṹ 
#define MAXQSIZE 100
typedef int QElemType; //�����г��� 
typedef struct {
	QElemType *base;   //��ʼ���Ķ�̬����洢�ռ�
	int front;         //ͷָ�룬�����в�Ϊ�գ���ָ���ͷԪ�� 
	int rear;          //βָ�룬�����в��գ�ָ���βԪ�ص���һ��λ�� 
} *SqQueue; 

Status InitQueue(SqQueue Q); 
int QueueLength(SqQueue	Q);
Status EnQueue(SqQueue Q, QElemType e);
#endif
