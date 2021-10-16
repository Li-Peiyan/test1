
#ifndef _HashQuad_H 

typedef unsigned int Index;
typedef Index Position;

Index Hash( const char *Key, int TableSize );

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( char* Key, HashTable H );
void Insert( char* Key, HashTable H );
char* Retrieve( Position P );
HashTable Rehash( HashTable H );

#endif
