#include<stdio.h>
#include<stdlib.h>
//#include "HashSep.h"

int MinTableSize = 20;

struct ListNode
{
	char* Element;
	Position Next;
};

typedef Position List;

struct HashTbl
{
	int TableSize;
	List *TheLists;
};

Index Hash( const char *Key, int TableSize)
{
/*	Index HashVal = 0;
	
	while( *Key != '\0' )
		HashVal += *Key++;
		
	return HashVal % TableSize; */        //方式一


/*	return( Key[0] + 27*Key[1] + 729*Key[2] ) % TableSize;*/    //方式二

	Index HashVal = 0;

	while( *Key != '\0' )
		HashVal = ( HashVal << 5 ) + *Key++;
	
	return HashVal % TableSize;     //方式三
}

HashTable InitializeTable( int TableSize )
{
	HashTable H;
	int i;

	if( TableSize < MinTableSize )
	{
		printf("Table ins too small");
		return NULL;
	}

	H = (HashTable) malloc( sizeof( struct HashTbl ) );
	if( H=NULL )
		printf("Out of space ! ! !");

	
	H->TheLists = (List *)malloc( sizeof( struct ListNode ) * H->TableSize );
	if( H->TheLists == NULL)
		printf( "out of space ! ! !" );
		
	for( i =0; i < H->TableSize; i++ )
	{
		//H->TheLists[ i ]= (List) malloc( sizeof( struct ListNode ) );
		if( H->TheLists[ i ]== NULL )
			printf( "out of space ! ! !" );
		else
			H->TheLists[ i ]->Next = NULL;
	}
	return H;

}

void DestroyTable( HashTable H )
{
	Position P2,P1;
	for( int i =0; i < H->TableSize; i++ )
		P1 = H->TheLists[ i ]->Next ;
		while(P1 != NULL )
		{
			P2 = P1;
		    P1 = P2 -> Next;
			free( P2 );
		}

	free( H );	
}

Position Find( char* Key, HashTable H )
{
	Position P;
	List L;
	L = H->TheLists[ Hash( Key, H->TableSize ) ];
	P = L->Next;
	while( P != NULL && P->Element != Key ) 
		P = P->Next;
	return P;
}

void Insert( char* Key, HashTable H )
{
	Position Pos, NewCell;
	List L;

	Pos = Find( Key, H );
	if( Pos ==NULL )
	{
		NewCell = (Position) malloc( sizeof (struct  ListNode ) );
		if( NewCell == NULL)
			printf( "out of space ! ! !" );
		else
		{
			L = H->TheLists[ Hash( Key, H->TableSize ) ];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}

int main()
{
	return 0;
}
