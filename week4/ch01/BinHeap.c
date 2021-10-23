#include<stdio.h>
#include<stdlib.h>


typedef int ElementType;
int MinPQSize = 20;
int MinDate = 13;


struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};

PriorityQueue Initialize( int MaxElements )
{
	PriorityQueue H;

	if( MaxElements < MinPQSize )
		printf("Priority queue is too small");

	H = (PriorityQueue) malloc( sizeof ( struct HeapStruct ));
	H->Elements = (int *)malloc( MaxElements +1 * sizeof( ElementType ));
	if(H->Elements == NULL )
		printf("Out of space!!!");

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinDate;

	return H;
}

void Destroy( PriorityQueue H )
{
	free(H->Elements);
	free(H);
}

void MakeEmpty( PriorityQueue H)
{
	H->Size = 0;
}

void Insert( ElementType X, PriorityQueue H )
{
	int i;
	if( IsFull( H ) )
	{
		printf("Priority is full ");
		return;
	}

	for( i= ++H->Size; H->Elements[ i/2 ] > X; i/=2)
	{
		H->Elements[ i ] = H->Elements[ i/2 ];
	}
	H->Elements[ i ] = X;
}

ElementType DeleteMin( PriorityQueue H )
{
	int i,Child;
	ElementType MinElement, LastElement;

	if( IsFull( H ) )
	{
		printf("Priority is full ");
		return H->Elements[ 0 ];
	}

	MinElement = H->Elements[ 1 ];
	LastElement = H->Elements[ H->Size-- ];

	for( i = 1; i*2 <= H->Size; i=Child )
	{
		Child = i*2;
		if( Child != H->Size && H->Elements[ Child + 1 ] < H->Elements[ Child ] )
			Child++;
		if( LastElement > H->Elements[ Child ])
			H->Elements[ i ] = H->Elements[ Child ];
		else
			H->Elements[ i ] = LastElement;
			break;
	}
	return MinElement;
}

ElementType FindMin( PriorityQueue H)
{
	return H->Elements[ 1 ];
}


int IsEmpty( PriorityQueue H )
{
	return H->Size == 0 ;
}

int IsFull( PriorityQueue H )
{
	return H->Size == H->Capacity;
}


int main()
{
	return 0;
}
