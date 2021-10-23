#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

#define LeftChild( i ) ( 2* ( i ) +1 )

void PercDown( ElementType A[ ], int i, int N )
{
	int Child;
	ElementType Tmp;
	for( Tmp = A[ i ]; LeftChild( i ) < N; i = Child )
	{
		Child = LeftChild( i );
		if( Child != N - 1 && A[ Child +1 ] > A[ Child ] ) 
			Child++;
		if( Tmp < A[ Child ] )
			A[ i ] =A[ Child ];
		else
			break;
	}
	A[ i ] = Tmp;
}

void Swap( ElementType *a, ElementType *b)
{
	ElementType c = *a;
	*a = *b;
	*b = c;
}

void HeapSort( ElementType A[ ], int N )
{
	int i;
	for( i = N/ 2; i>= 0; i-- )
		PercDown( A, i, N );
	for( i = N - 1; i > 0; i-- ){
		Swap( &A[ 0 ], &A[ i ]);
		PercDown( A, 0, i );
	}
}

int main()
{
	int A[10] ={5,3,0,4,9,7,8,6,1,2};
	HeapSort( A, 10 );
	for(int i=0; i<10; i++ )
		printf("%d\n", A[i] );
	return 0;
}
