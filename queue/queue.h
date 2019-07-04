#pragma once
#include<stdio.h>
#include<stdlib.h>
#define  QUEUENUM 100
typedef int DataType;
typedef struct  
{
	DataType _data[QUEUENUM];
	DataType *_head;
	DataType *_tail;
	size_t _size;
}Dequeue;
void dequeueInit(Dequeue * qu);
 
void dequeueIEmpty(Dequeue * qu);
 
int dequeuePush(Dequeue * qu, DataType X);
 