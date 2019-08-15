#if 0
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
	//入队列，从对尾入从队头出
	//在循环队列中，尾巴上留一个不存数据的空间来检测队列是否已满
    //环形队列当中出队从队头出入队从队尾入
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
	//从这个做法中可以发现，环形队列就是在队全部列满的时候让队首和队尾指针全部指向头指针
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
#endif
#include "queue.h"


void dequeInit(deque * qu)
{
	//初始化环形队列
	//将队列的头指针和尾指针同时指向数组开头（首元素的首地址）
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

void dequeEmpty(deque * qu)
{
	//队列清空
	//将对列收尾指针相等，因为清空之后会初始化将他们都指向数组头
	qu->_head = qu->_tail;
	qu->_size = 0;
}

int dequePush(deque * qu, DataType x)
{
	//入队列，先判断队列是否已满，然后尾指针后移
	
	if ( qu->_tail+1==qu->_head||(qu->_tail + 1 - qu->_data == QUEUENUM && qu->_head == qu->_data))
		//入队列首先要判断队列是否已满，从队尾入。
		//我们一般将队列的最后一个元素空下来用来判断对列是否已满，因为当头和尾相等时
		//不能判断是空还是已满
	{
		printf("队列已满不能插入\n");
		return -1;
	}
	*qu->_tail = x;
	qu->_tail++;
	 
	if (qu->_tail - qu->_data == QUEUENUM)
	{
		//来成环
		qu->_tail = qu->_data;
	}
	qu->_size++;
	return 0;
}

int dequePop(deque * qu)
{
	if (dequeIsEmpty(qu))
	{
		//判断队列是否已满
		return -1;
	}
	qu->_head++;
	if (qu->_head - qu->_data == QUEUENUM)
	{
		//此种情况是当上一次出队头指针已将指到倒数第一个元素时紧接着再出队时，头指针
		//就会指向设计程序时空着的最后一个元素，此时应该将头指针重新指向首元素首地址。
		//来成环
		qu->_head = qu->_data;
	}
	qu->_size--;
	return 0;
}

DataType dequeFront(deque * qu)
{
	return *qu->_head;
}


DataType dequeBack(deque * qu)
{
	if (qu->_tail == qu->_data)
	{
		return qu->_data[QUEUENUM - 1];
	}
	//因为入队后有_tail++,但是实际并没有赋值
	return qu->_tail[-1];
}


int dequeIsEmpty(deque * qu)
{
	return qu->_head == qu->_tail;
}

size_t dequeSize(deque * qu)
{
	return qu->_size;
}


//找左孩子*2右孩子*2+1 2（n+1）-1 ，2（n+1）+1-1,父亲：(n-1)/2,是否为叶子（n+1）/2
//非叶子(n-1)/2
//后序左右根