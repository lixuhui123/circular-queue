#pragma once
#if 0
#include<stdio.h>
#include<stdlib.h>
//������ʵ�ֵ�ѭ������
#define  QUEUENUM 100
typedef int DataType;
typedef struct  
{
	DataType _data[QUEUENUM];//����һ������
	DataType *_head;
	DataType *_tail;
	size_t _size;
}Dequeue;//�ṹ������
void dequeueInit(Dequeue * qu);
 
void dequeueIEmpty(Dequeue * qu);
 
int dequeuePush(Dequeue * qu, DataType X);
#endif
#pragma once

#include <stdio.h>
#include <stdlib.h>
#define QUEUENUM 5
typedef int DataType;

typedef struct {
	DataType _data[QUEUENUM];
	DataType * _head;
	DataType * _tail;
	size_t _size;
}deque;
DataType dequeFront(deque * qu);
void dequeInit(deque * qu);
void dequeEmpty(deque * qu);
int dequePush(deque * qu, DataType x);
int dequePop(deque * qu);
DataType dequeBack(deque * qu);
size_t dequeSize(deque * qu);
int dequeIsEmpty(deque * qu);
size_t dequeSize(deque * qu);


 