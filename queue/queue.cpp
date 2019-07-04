#include "queue.h"
void dequeueInit(Dequeue * qu)
{
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}
void dequeueIEmpty(Dequeue * qu)
{
	qu->_head = qu->_tail;
	qu->_size = 0;
}
int dequeuePush(Dequeue * qu, DataType X)
{
	*qu->_tail = X;
	if (qu->_tail + 1 == qu->_head || (qu->_tail + 1 - qu->_data == QUEUENUM && qu->_head == qu->_tail))
	{
		return -1;
	}
	qu->_tail++;
	if (qu->_tail - qu->_data == QUEUENUM)
	{
		qu->_tail = qu->_data;
	}
	qu->_size++;
}
void dequeuePop(Dequeue * qu)
{
	qu->_head++;
	if (qu->_head - qu->_data == QUEUENUM)
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