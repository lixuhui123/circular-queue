#include "queue.h"
#if 0
int main()
{
	//
	Dequeue test;
	dequeueInit(&test);
	system("pause");
	return 0;
}
#endif
#include "queue.h"

int main()
{
	deque test;
	dequeInit(&test);
	dequePush(&test, 1);
	dequePush(&test, 2);
	dequePush(&test, 3);
	printf("%d\n", dequeFront(&test));
	dequePop(&test);
	printf("%d\n", dequeFront(&test));
	dequePop(&test);
	printf("%d\n", dequeFront(&test));
	dequePush(&test, 4);
	dequePush(&test, 5);
	dequePop(&test);
	printf("%d\n", dequeFront(&test));
	dequePush(&test, 6);
	dequePush(&test, 7);
	dequePop(&test);
	printf("%d\n", dequeFront(&test));
	dequePop(&test);
	printf("%d\n", dequeFront(&test));
	printf("%d\n", dequeBack(&test));
	system("pause");
	return 0;
}