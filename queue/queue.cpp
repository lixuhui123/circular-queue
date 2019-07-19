#include "queue.h"
void dequeueInit(Dequeue * qu)
{
	//��ʼ��
	qu->_head = qu->_tail = qu->_data;//ͷ��β��ָ���������Ԫ�ص��׵�ַ
	qu->_size = 0;
}
void dequeueIEmpty(Dequeue * qu)
{
	//���
	qu->_head = qu->_tail;
	qu->_size = 0;
}
int dequeuePush(Dequeue * qu, DataType X)
{
	//��ѭ�������У�β������һ���������ݵĿռ����������Ƿ�����
    //���ζ��е��г��ӴӶ�ͷ����ӴӶ�β��
	*qu->_tail = X;
	if (qu->_tail + 1 == qu->_head || (qu->_tail + 1 - qu->_data == QUEUENUM && qu->_head == qu->_tail))
	{
     //��������¶������������ٲ���,�ڶ���+1��Ԫ����100����99�ͻ������Լ���ʱ��Ҫ+1
		return -1;
	}
	qu->_tail++;//βָ�����
	if (qu->_tail - qu->_data == QUEUENUM)
	{
		//��ʱ�����е�Ԫ���Ѿ��浽�±�Ϊ100����Ҫ���³�ʼ������
		qu->_tail = qu->_data;
	}
	qu->_size++;
}
void dequeuePop(Dequeue * qu)
{
	//�����У�ͷָ�����
	qu->_head++;
	if (qu->_head - qu->_data == QUEUENUM-1)
	{
		qu->_head = qu->_data;
	}
	qu->_size--;
}
DataType DequeueFront(Dequeue * qu)
{
	 return *qu->_head;
}
DataType DequeueBack(Dequeue * qu)
{
	if (qu->_tail==qu->_data)
	{
		return qu->_data[QUEUENUM - 1];
	}
	return *qu->_tail;
}
int dequeueIsEmpty(Dequeue * qu)
{
	return qu->_head == qu->_tail;
}