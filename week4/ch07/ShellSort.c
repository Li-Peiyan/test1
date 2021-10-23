#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

void ShellSort(ElementType A[], int N)
{
	int i, j, Increment;
	ElementType Tmp;

	for( Increment = N/2; Increment >0 ; Increment /= 2 )
		for( i = Increment; i<N; i++)
		{
			Tmp = A[i];
			for( j=i; j >= Increment; j -= Increment)
				if( Tmp < A[j-Increment] )
					A[ j ] = A[ j-Increment ];
				else
					break;
			A[j]=Tmp;
		}
}

int main()
{
	int A[10] ={5,3,0,4,9,7,8,6,1,2};
	ShellSort( A, 10 );
	for(int i=0; i<10; i++ )
		printf("%d\n", A[i] );
	return 0;
}
