#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#ifndef _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty( AvlTree T ) ;
Position Find( int x, AvlTree T );
Position FindMin( AvlTree T );
Position FindMax ( AvlTree T );
AvlTree Insert( int x, AvlTree T );
AvlTree Delete( int x, AvlTree T );
int Retrieve( Position P );

#endif 

struct AvlNode
{
	int Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

AvlTree MakeEmpty( AvlTree T )
{
	if( T != NULL )
	{
		MakeEmpty( T->Left );
		MakeEmpty( T->Right);
		free( T );
	}
	return NULL;
}

Position Find( int X, AvlTree T )
{
	if( T == NULL )
		return NULL;
	if(X< T->Element )
		return Find( X, T->Left );
	else if(X >T->Element )
		return Find( X, T->Right );
	else
		return T;
}

Position FindMin( AvlTree T )
{
	if( T == NULL )
		return NULL;
	else if( T->Left == NULL )
		return T;
	else
		return FindMin( T->Left );
}

Position FindMax( AvlTree T )
{
	if( T != NULL )
		while( T->Right != NULL)
			T=T->Right;
	return T;
}

static int Height( Position P )
{
	if( P=NULL )
		return -1;
	else
		return P->Height;
}

static int Max( int P1, int P2 )
{
	if( P1 < P2 )return P2;
	else return P1;
}

static Position SingleRotateWithLeft( Position K2 )
{
	Position K1;

	K1=K2->Left;
	K2->Left=K1->Right;
	K1->Right=K2;

	K2->Height= Max(Height( K2->Left), Height(K2->Right) )+1;
	K1->Height= Max(Height( K1->Left), Height(K1->Right) )+1;

	return K1;
}

static Position SingleRotateWithRight( Position K2 )
{
	Position K1;

	K1=K2->Right;
	K2->Right=K1->Left;
	K1->Left=K2;

	K2->Height= Max(Height( K2->Left), Height(K2->Right) )+1;
	K1->Height= Max(Height( K1->Left), Height(K1->Right) )+1;

	return K1;
}


static Position DoubleRotateWithLeft( Position K3 )
{
	K3->Left=SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft( K3 );
}

static Position DoubleRotateWithRight( Position K3 )
{
	K3->Left=SingleRotateWithLeft(K3->Right);
	return SingleRotateWithRight( K3 );
}


AvlTree Insert( int X, AvlTree T )
{
	if( T=NULL )
	{
		T= (AvlTree) malloc( sizeof( struct AvlNode ) );
		if( T==NULL )
			printf("Out of space!!!");
		else
		{
			T->Element=X;
			T->Height=0;
			T->Left=T->Right=NULL;
		}
	}
	else if( X < T->Element )
	{
		T->Left=Insert( X, T->Left);
		if( Height( T->Left ) - Height( T->Right ) == 2 )
		{
			if( X < T->Left->Element )
				T = SingleRotateWithLeft( T );
			else
				T = DoubleRotateWithLeft( T );
		}
	}
	else if( X > T->Element )
	{
		T->Right=Insert( X, T->Right);
		if( Height( T->Right ) - Height( T->Left ) == 2 )
		{
			if( X > T->Right->Element )
				T = SingleRotateWithRight( T );
			else
				T = DoubleRotateWithRight( T );
		}
	}
	T -> Height = Max( Height(T->Left), Height(T->Right) ) + 1;
	return T;
}

int main()
{
	return 0;
}
