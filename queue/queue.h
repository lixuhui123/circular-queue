#pragma once
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
 