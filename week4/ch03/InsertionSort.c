#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

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

int main()
{
	int A[10] ={5,3,0,4,9,7,8,6,1,2};
	InsertionSort( A, 10 );
	for(int i=0; i<10; i++ )
		printf("%d\n", A[i] );
	return 0;
}
