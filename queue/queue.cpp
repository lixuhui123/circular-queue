#include "queue.h"
void dequeueInit(Dequeue * qu)
{
	//初始化
	qu->_head = qu->_tail = qu->_data;//头和尾都指向数组的首元素的首地址
	qu->_size = 0;
}
void dequeueIEmpty(Dequeue * qu)
{
	//清空
	qu->_head = qu->_tail;
	qu->_size = 0;
}
int dequeuePush(Dequeue * qu, DataType X)
{
	//在循环队列中，尾巴上留一个不存数据的空间来检测队列是否已满
    //环形队列当中出队从对头出入队从队尾入
	*qu->_tail = X;
	if (qu->_tail + 1 == qu->_head || (qu->_tail + 1 - qu->_data == QUEUENUM && qu->_head == qu->_tail))
	{
     //此种情况下队列已满不能再插入,第二个+1是元素有100个到99就会满所以减的时候要+1
		return -1;
	}
	qu->_tail++;//尾指针后移
	if (qu->_tail - qu->_data == QUEUENUM)
	{
		//此时队列中的元素已经存到下标为100所以要重新初始化队列
		qu->_tail = qu->_data;
	}
	qu->_size++;
}
void dequeuePop(Dequeue * qu)
{
	//出队列，头指针后移
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