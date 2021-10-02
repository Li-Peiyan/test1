>C语言指针实栈

#include <stdio.h>
#include <malloc.h>

#ifndef _stack_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack ;

int IsEmpty( Stack S);
Stack CreateStack( void );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( int X, Stack S);
int Top( Stack S );
void Pop( Stack S );

#endif

struct Node
{
	int Element;
	PtrToNode Next;
};

int IsEmpty( Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack( void )
{
	Stack S;
	S = (Stack) malloc( sizeof( struct Node ) );
	if( S == NULL )
		printf( "out of space! ! ! " );
	S->Next = NULL;
	MakeEmpty( S );
	return S;
}

void MakeEmpty( Stack S )
{
	if( S == NULL )
		printf( "Must use CreateStack first" );
	else
	{
		while( !IsEmpty( S ) )
			Pop( S );
	}
}

void Push( int X,Stack S )
{
	PtrToNode TmpCell;

	TmpCell = (PtrToNode) malloc( sizeof( struct Node ) );
	if( TmpCell == NULL )
		printf( "out of space! ! !" );
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

int Top(Stack S)
{
	if( !IsEmpty(S))
		return S->Next->Element;
	printf("empty stack");
	return 0;
}

void Pop( Stack S )
{
	PtrToNode FirstCell;
	if( IsEmpty( S ) )
		printf( "Empty stack");
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free( FirstCell ) ;
	}
}

int mian()
{
	return 0;
}

