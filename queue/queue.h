#pragma once
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
 