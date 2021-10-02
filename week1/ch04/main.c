>C语言实现队列

#include <stdio.h>
#include <malloc.h>

#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void DisposeQueue( Queue Q );
void MakeEmpty( Queue Q );
void Enqueue( int X, Queue Q );
int Front( Queue Q );
void Dequeue( Queue Q );
int FrontAndDequeue( Queue Q );

#endif

#define MinQueueSize ( S )
struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};

int IsEmpty( Queue Q )
{
	return Q->Size == 0;
}

int IsFull( Queue Q )
{
	return Q->Size == (Q->Capacity);
}

Queue CreateQueue( int MaxElements )
{
	Queue Q = (Queue) malloc(sizeof( struct QueueRecord));
	Q->Capacity=MaxElements;
	MakeEmpty( Q );
	return Q;
}

void MakeEmpty( Queue Q )
{
	Q->Size=0;
	Q->Front=1;
	Q->Rear=0;
}

static int Succ( int value,Queue Q )
{
	if( ++value == Q->Capacity )
		value = 0;
	return value;
}

void Enqueue( int X, Queue Q )
{
	if( IsFull(Q) )
		printf( "Full queue" );
	else
	{
		Q->Size++;
		Q->Rear = Succ( Q->Rear, Q );
		Q->Array[ Q->Rear ] =X;
	}
}

int main()
{
	return 0;
}
