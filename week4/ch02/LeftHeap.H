#ifndef _LeftHeap_H

typedef int ElementType;
int MaxElements = 20 ;

struct TreeNode ;
typedef struct TreeNode *PriorityQueue;

PriorityQueue Initialize( void );
PriorityQueue BuildHead( PriorityQueue H );
ElementType FindMin( PriorityQueue H );
int IsEmpty( PriorityQueue H );
void SwapChild(PriorityQueue H);

PriorityQueue Merge( PriorityQueue H1, PriorityQueue H2 );
PriorityQueue Mergel( PriorityQueue H1, PriorityQueue H2 );

#define Insert(X, H) (H = Insertl( ( X ), H ) )

PriorityQueue Insertl( ElementType X, PriorityQueue H );
PriorityQueue DeleteMinl( PriorityQueue H );

#endif
