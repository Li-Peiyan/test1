#include<stdio.h>
#include<stdlib.h>

void Initilialize( DisjSet S )
{
	int i;

	for( i = NumSets; i>0; i-- )
		S[ i ] = 0;
}

void SetUnion( DisjSet S, SetType Root1, SetType Root2 )
{//浅的树成为深的树的子树
	if( S[ Root2 ] < S[ Root1 ] )
		S[ Root1 ] = Root2 ;
	else
	{
		if( S[ Root1 ] == S[ Root2 ] )
			S[ Root1 ]--;
		S[ Root2 ] = Root1;
	}
}

SetType Find( ElementType X, DisjSet S )
{
	if( S[ X ] <= 0 )
		return X;
	else return S[X] = Find( S[X], S );//路径压缩
}


int main()
{
	DisjSet S;
	Initilialize( S );
	
	return 0;
}
