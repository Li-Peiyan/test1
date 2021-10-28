#ifndef _DisjSet_H

#define NumSets 8
typedef int DisjSet[ NumSets + 1 ];
typedef int SetType;
typedef int ElementType;

void Initilialize( DisjSet S );
void SetUnion( DisjSet S, SetType Root1, SetType Root2 );
SetType Find( ElementType X, DisjSet S );

#endif
