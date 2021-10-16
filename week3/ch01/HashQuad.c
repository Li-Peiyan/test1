#include<stdio.h>
#include<stdlib.h>
#include "HashQuad.h" 


int MinTableSize = 20;

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry
{
	char * Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
	int TableSize;
	Cell *TheCells;
};

Index Hash( const char *Key, int TableSize )
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

	H->TheCells = (Cell *) malloc( sizeof( Cell ) * H->TableSize );
	if( H->TheCells == NULL)
		printf( "out of space ! ! !" );


	for( i =0; i < H->TableSize; i++ )
		H->TheCells[i].Info = Empty;

	return H;
}

void DestroyTable( HashTable H )
{
	free( H->TheCells );
	free( H );	
}

Position Find( char* Key, HashTable H )
{
	Position CurrentPos;
	int CollisionNum;
	CollisionNum = 0;
	CurrentPos = Hash( Key, H->TableSize );
	while( H->TheCells[ CurrentPos ].Info != Empty && H->TheCells[ CurrentPos ].Element !=Key )
	{
		CurrentPos += 2 * ++CollisionNum - 1;//平方探测法
		if( CurrentPos >= H->TableSize )
			CurrentPos -=H->TableSize;
	}
	return CurrentPos ;
}

void Insert( char* Key, HashTable H )
{
	Position Pos;
	Pos = Find( Key, H );
	if( H->TheCells[ Pos ].Info != Legitimate )
	{
		H->TheCells[ Pos ].Info = Legitimate;
		H->TheCells[ Pos ].Element = Key ;
	}
}

HashTable Rehash( HashTable H )
{
	int i, OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable( 2*OldSize );
	for( i=0; i<OldSize; i++ )
		if( OldCells[ i ].Info == Legitimate )
			Insert( OldCells[ i ].Element, H );

	free( OldCells );

	return H;
}

int main()
{
	return 0;
}
