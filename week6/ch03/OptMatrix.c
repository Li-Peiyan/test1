void OptMatrix( const long C[], int N, TwoDimArray M, TwoDimArray LastChange )
{
  
  int i, k, Left, Right; 
  long ThisM;
  for( Left= l; Left <= N; Left++) 
     M[ Left ][ Left ] =0;
   for( k = i; k< N; k++) 
    for( Left = 1; Left<= N - k; Leftr++)
    {
      Right = Left+ k ;
      M[ Left ][ Right ] = Infinity;
      for( i =Left; i < Right; i++ )
      {
        ThisM = M[Left ][ i]+M[i +1 ][ Right +C[ Left - 1]* C[ i ]*C[ Right ];                   
        if( ThisM 之 M[ Left ][ Right ] )  
        {
          M[Left ][ Right ] = ThisM;
          LastChange[ Left j[ Right ] = i;
         }
                     
       }
                     
      }
 }
