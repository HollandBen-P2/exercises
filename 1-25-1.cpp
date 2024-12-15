#include <iostream>
#include <bitset>

// Function declarations
int main();
std::string to_binary( int n );
int ilog2( int n );

// Function definitions
int main() {
  for ( int k{0}; k <= 33; ++k ) {
    std::cout << k << "\t" << to_binary( k ) << std::endl;
  }

  std::cout << 42 << "\t" << to_binary( 42 ) << std::endl;

  while ( true ) {
    int n{};
    std::cout << "Enter a positive integer (0 to quit): ";
    std::cin >> n;

    if ( n == 0 ) {
      break;
    } else if ( n >= 0 ) {
      std::cout << n << "\t" << to_binary( n ) << std::endl;
    } 
  }

  return 0;
}

// ilog2(...)
//
// @param n      A non-negative integer          m
// @returns      The largest 'm' such that n >= 2
//
// This will return the number of significant
// bits required to store the number 'n'.

int ilog2( int n ) {
  if ( n == 0 ) {
    return 1;
  }

  int count{ 0 };

  while ( n != 0 ) {
    n /= 2;
    ++count;
  }

  return count;
}

// Explaining this function right now is beyond what has
// been covered to this point, but to summarize:
//     Create a bitset object initialized by 'n'
//     std::bitset<32>( n )
//     Convert the object to a string of 32 0s or 1s
//                         .to_string()
//     Extract only those digits up to the most significant 1
//                                     .substr( 32 - log2(n), 31 );

std::string to_binary( int n ) {
  return std::bitset<32>( n ).to_string().substr( 32 - ilog2(n), 31 );
}