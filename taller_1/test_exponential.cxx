#include <cstdlib>
#include <iostream>

#include <chrono>

#include "exponential_functions.h"

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  // Get command line arguments
  if( argc < 2 )
  {
    std::cerr
      << "Usage: " << argv[ 0 ]
      << " base exponential"
      << std::endl;
    return( -1 );

  } // fi
  double a = std::atof( argv[ 1 ] );
  unsigned short n = std::atoi( argv[ 2 ] );

  // Compute exponential (recursive)
  long start_recursive =
    std::chrono::duration_cast< std::chrono::nanoseconds >(
      std::chrono::system_clock::now( ).time_since_epoch( )
      ).count( );
  double result_recursive = exp_recursive( a, n );
  long end_recursive =
    std::chrono::duration_cast< std::chrono::nanoseconds >(
      std::chrono::system_clock::now( ).time_since_epoch( )
      ).count( );
  long time_recursive = end_recursive - start_recursive;

  // Compute exponential (iterative)
  long start_iterative =
    std::chrono::duration_cast< std::chrono::nanoseconds >(
      std::chrono::system_clock::now( ).time_since_epoch( )
      ).count( );
  double result_iterative = exp_iterative( a, n );
  long end_iterative =
    std::chrono::duration_cast< std::chrono::nanoseconds >(
      std::chrono::system_clock::now( ).time_since_epoch( )
      ).count( );
  long time_iterative = end_iterative - start_iterative;

  // Show results
  std::cout
    << n << " "
    << result_recursive << " " << result_iterative << " "
    << time_recursive << " " << time_iterative
    << std::endl;

  return( 0 );
}

// eof - test_exponential.cxx
