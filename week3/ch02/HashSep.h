#ifndef _HashSep_H 

typedef unsigned int Index;
Index Hash( const char *Key, int TableSize );

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );
Position Find( char* Key, HashTable H );
void Insert( char* Key, HashTable H );
char* Retrieve( Position P );

#endif
