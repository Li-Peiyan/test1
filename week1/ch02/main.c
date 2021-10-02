>C语言游标实现链表

#include <stdio.h>

#ifndef _cursor_H

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace( void );

List MakeEmpty( List L );
int IsEmpty( const List L );
int IsLast( const Position P, const List L );
Position Find( int X, const List L );
void Delete( int x,List L);
Position FindPrevious( int x,const List L );
void Insert( int x,List L, Position P );
void DeleteList( List L );
Position Header( const List L);
Position First( const List L);
Position Advance( const Position P );
int Retrieve( const Position P );

#endif

struct Node
{
	int Element;
	Position Next;
};

struct Node CursorSpace[ 100 ];

static Position CursorAlloc( void )
{
	Position P;
	P= CursorSpace[ 0 ].Next;
	CursorSpace[ 0 ].Next = CursorSpace[ P ]. Next;
	return P;
}

static void	CursorFree( Position P )
{
	CursorSpace[ P ].Next = CursorSpace[ 0 ]. Next;
	CursorSpace[ 0 ].Next = P;
}

int IsEmpty( List L)
{
	return CursorSpace[ L ].Next ==0;
}

int	IsLast( Position P, List L)
{
	return CursorSpace[ P ].Next == 0;
}

Position Find( int X,List L)
{
	Position P;
	P = CursorSpace[ L].Next;
	while( P && CursorSpace[ P ].Element != X )
		P = CursorSpace[ P ].Next;
	return P;
}

void Delete( int X, List L)
{
	Position P,TmpCell;
	P = FindPrevious( X,L );
	if( !IsLast( P, L))
	{
		TmpCell = CursorSpace[ P ].Next;
		CursorSpace[ P ].Next = CursorSpace[ TmpCell ].Next;
		CursorFree( TmpCell );
	}
}

void Insert( int X,List L,Position P )
{
	Position TmpCell;
	TmpCell = CursorAlloc( );
	if( TmpCell == 0 )
		printf( "Out of space! !!");
	CursorSpace[ TmpCell ].Element = X;
	CursorSpace[ TmpCell ].Next = CursorSpace[ P ].Next;
	CursorSpace[ P ].Next = TmpCell ;
}

int main()
{
	return 0;
}
