#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

void Swap( ElementType *a, ElementType *b)
{
	ElementType c = *a;
	*a = *b;
	*b = c;
}

void InsertionSort(ElementType A[], int N)
{
	int j,p;

	ElementType Tmp;
	for( p=1; p<N; p++ )
	{
		Tmp = A[p];
		for( j =p; j > 0 && A[j-1] > Tmp; j-- )
			A[j] = A[j-1];
		A[j]=Tmp;
	}
}

ElementType Median3( ElementType A[ ], int Left, int Right )
{
	int Center = ( Left + Right ) / 2;
	
	if( A[ Left ] > A[ Center ] )
		Swap( &A[ Left ], &A[ Center ] );
	if( A[ Left ] > A[ Right])
		Swap( &A[ Left ], &A[ Right ] );
	if( A[ Center ] > A[ Right ])
		Swap( &A[ Center ], &A[ Right ] );

	Swap( &A[ Center ], &A[ Right - 1 ]);
	return A[ Right - 1 ];
}

#define Cutoff ( 3 )
void Qsort( ElementType A[ ], int Left, int Right )
{
	int i, j;
	ElementType Pivot;
	if( Left + Cutoff <= Right )
	{
		Pivot = Median3( A, Left, Right );
		i = Left;
		j = Right - 1;
		for( ; ;)
		{
			while( A[ ++i ] < Pivot ){}
			while( A[ --j ] > Pivot ){}
			if( i < j )
				Swap( &A[ i ], &A[j ] );
			else
				break;
		}
		Swap( &A[ i ], &A[ Right - 1 ]);
		Qsort( A, Left, i - 1 );
		Qsort( A, i + i, Right );
	}
	else
		InsertionSort( A + Left, Right - Left +1 );	
}

void Quicksort( ElementType A[], int N )
{
	Qsort( A, 0, N-1 );
}

int main()
{
	int A[10] ={5,3,0,4,9,7,8,6,1,2};
	Quicksort( A, 10 );
	for(int i=0; i<10; i++ )
		printf("%d\n", A[i] );
	return 0;
}
