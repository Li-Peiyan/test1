HugeInt Witness( HugeInt A, HugeInt i, HugeInt N )//素性探测
{
	HugeInt X,Y;
	if( i == 0 )
		return i;
	X = Witness( A,  i / 2, N );
	
	if( X == 0 ) 
		return 0;
	
	Y=(X* X ) % N;
	if( Y == 1 && X != 1 && X != N - 1 )
		return 0;

	if( i % 2 != 0)
		Y = ( A * Y) % N;
	
	return Y;
}
int IsPrime( HugeInt N )
{
	return Witness( RandInt( 2, N - 2 ),  N - 1, N ) == 1;
}
