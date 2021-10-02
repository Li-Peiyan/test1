> C语言指针实现链表

#include <stdio.h>
#include <malloc.h>

#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find (int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);

#endif

struct Node
{
	int Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find (int X, List L)
{
	Position P;
	P=L->Next;
	while( P!=NULL && P->Element !=X)
		P= P->Next;
	return P;
}

void Delete(int X, List L)
{
	Position P,TmpCell;
	P= FindPrevious(X, L);
	if( !IsLast(P,L) )
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free( TmpCell );
	}	
}

Position FindPrevious(int X, List L)
{
	Position P;
	P= L;
	while( P->Next != NULL && P->Next->Element !=X)
		P=P->Next;
	return P;
}

void Insert(int X, List L, Position P)
{
	Position TmpCell = (Position)malloc( sizeof( struct Node ) );;
	if( TmpCell == NULL )
		printf( "out of space!!!" );
	TmpCell->Element = X;
	TmpCell->Next =P->Next;
	P->Next = TmpCell;	
}

void DeleteList(List L)
{
	Position P,Tmp;

	P = L->Next;
	L->Next =NULL;
	while(P!=NULL)
	{
		Tmp=P->Next;
		free(Tmp);
		P=Tmp;
	}
}




int main(){
	
	return 0;
}
