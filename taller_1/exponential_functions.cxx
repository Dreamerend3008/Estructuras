#include "exponential_functions.h"

// -------------------------------------------------------------------------
double exp_recursive( double a, unsigned short n )
{
  if( n == 0 )
    return( double( 1 ) );
  else
    return( exp_recursive( a, n - 1 ) * a );
}

// -------------------------------------------------------------------------
double exp_iterative( double a, unsigned short n )
{
  double e = double( 1 );
  for( unsigned short i = 1; i <= n; ++i )
    e *= a;
  return( e );
}

// eof - exponential_functions.cxx

