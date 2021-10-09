#include<stdio.h>
#include<malloc.h>

#ifndef _SearchTree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree T ) ;
Position Find( int x, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax ( SearchTree T );
SearchTree Insert( int x, SearchTree T );
SearchTree Delete( int x, SearchTree T );
int Retrieve( Position P );

#endif 

struct TreeNode
{
	int Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty( SearchTree T )
{
	if( T != NULL )
	{
		MakeEmpty( T->Left );
		MakeEmpty( T->Right);
		free( T );
	}
	return NULL;
}

Position Find( int X, SearchTree T )
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

Position FindMin( SearchTree T )
{
	if( T == NULL )
		return NULL;
	else if( T->Left == NULL )
		return T;
	else
		return FindMin( T->Left );
}

Position FindMax( SearchTree T )
{
	if( T != NULL )
		while( T->Right != NULL)
			T=T->Right;
	return T;
}

SearchTree Insert( int X, SearchTree T )
{
	if( T == NULL )
	{
		T = (SearchTree)malloc( sizeof( struct TreeNode ) );
		if( T == NULL )
			printf( "Out of space! !!");
		else
		{
			T->Element = X;
			T->Left =T->Right = NULL;
		}
	}
	else if( X < T->Element )
		T->Left = Insert( X, T->Left );
	else if( X > T->Element )
		T->Right = Insert( X, T->Right );
	return T;
}

SearchTree Delete( int x, SearchTree T)
{ 
	Position TmpCell;
	if( T == NULL)
		printf( "Eement not found" );
	else if( x < T->Element )T->Left = Delete( x, T->Left );
	else if( x > T->Element ) T->Right = Delete( x, T->Left );
	else if( T->Left && T->Right )
	{
		TmpCell = FindMin( T->Right );
		T->Element = TmpCell->Element;
		T->Right = Delete( T->Element, T->Right );
	}
	else
	{
		TmpCell = T;
		if( T->Left == NULL ) T =T->Right;
		else if( T->Right == NULL )T= T->Left;
		free( TmpCell );
	
	}
	return T;
}

int main()
{

	return 0;
}
