#pragma once
#if 0
#include<stdio.h>
#include<stdlib.h>
//用数组实现的循环队列
#define  QUEUENUM 100
typedef int DataType;
typedef struct  
{
	DataType _data[QUEUENUM];//这是一个数组
	DataType *_head;
	DataType *_tail;
	size_t _size;
}Dequeue;//结构体类型
void dequeueInit(Dequeue * qu);
 
void dequeueIEmpty(Dequeue * qu);
 
int dequeuePush(Dequeue * qu, DataType X);
#endif
#pragma once

#include <stdio.h>
#include <stdlib.h>
#define QUEUENUM 10
typedef int DataType;

typedef struct {
	DataType _data[QUEUENUM];
	DataType * _head;
	DataType * _tail;
	size_t _size;
}deque;
/*所谓环形队列是一种抽象的数组，只是说重复利用这段数组的空间，我们还是应该把它想象成
一段数组，在队头出队在队尾入队，先进先出，维护这段队列要注意的是，队头和尾指针不能越界
不能交叉*/
DataType dequeFront(deque * qu);
void dequeInit(deque * qu);
void dequeEmpty(deque * qu);
int dequePush(deque * qu, DataType x);
int dequePop(deque * qu);
DataType dequeBack(deque * qu);
size_t dequeSize(deque * qu);
int dequeIsEmpty(deque * qu);
size_t dequeSize(deque * qu);


 