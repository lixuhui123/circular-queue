#if 0
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
	//����У��Ӷ�β��Ӷ�ͷ��
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
	//����������п��Է��֣����ζ��о����ڶ�ȫ��������ʱ���ö��׺Ͷ�βָ��ȫ��ָ��ͷָ��
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
#endif
#include "queue.h"


void dequeInit(deque * qu)
{
	//��ʼ�����ζ���
	//�����е�ͷָ���βָ��ͬʱָ�����鿪ͷ����Ԫ�ص��׵�ַ��
	qu->_head = qu->_tail = qu->_data;
	qu->_size = 0;
}

void dequeEmpty(deque * qu)
{
	//�������
	//��������βָ����ȣ���Ϊ���֮����ʼ�������Ƕ�ָ������ͷ
	qu->_head = qu->_tail;
	qu->_size = 0;
}

int dequePush(deque * qu, DataType x)
{
	//����У����ж϶����Ƿ�������Ȼ��βָ�����
	
	if ( qu->_tail+1==qu->_head||(qu->_tail + 1 - qu->_data == QUEUENUM && qu->_head == qu->_data))
		//���������Ҫ�ж϶����Ƿ��������Ӷ�β�롣
		//����һ�㽫���е����һ��Ԫ�ؿ����������ж϶����Ƿ���������Ϊ��ͷ��β���ʱ
		//�����ж��ǿջ�������
	{
		printf("�����������ܲ���\n");
		return -1;
	}
	*qu->_tail = x;
	qu->_tail++;
	 
	if (qu->_tail - qu->_data == QUEUENUM)
	{
		//���ɻ�
		qu->_tail = qu->_data;
	}
	qu->_size++;
	return 0;
}

int dequePop(deque * qu)
{
	if (dequeIsEmpty(qu))
	{
		//�ж϶����Ƿ�����
		return -1;
	}
	qu->_head++;
	if (qu->_head - qu->_data == QUEUENUM)
	{
		//��������ǵ���һ�γ���ͷָ���ѽ�ָ��������һ��Ԫ��ʱ�������ٳ���ʱ��ͷָ��
		//�ͻ�ָ����Ƴ���ʱ���ŵ����һ��Ԫ�أ���ʱӦ�ý�ͷָ������ָ����Ԫ���׵�ַ��
		//���ɻ�
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
	//��Ϊ��Ӻ���_tail++,����ʵ�ʲ�û�и�ֵ
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


//������*2�Һ���*2+1 2��n+1��-1 ��2��n+1��+1-1,���ף�(n-1)/2,�Ƿ�ΪҶ�ӣ�n+1��/2
//��Ҷ��(n-1)/2
//�������Ҹ�