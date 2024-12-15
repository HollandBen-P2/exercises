#include <iostream>
#include <bitset>

// Function declarations
int main();
std::string to_binary( int n );
int ilog2( int n );

// Function definitions

// By directing std::hex to std::cout, this indicates that
// any integer data types (short, int, long) should be printed
// in hexadecimal from that point on, so after directing 
// the next 'k' to std::cout, we go back to printing in
// decimal by directing std::dec to std::cout.
int main() {
  for ( int k{0}; k <= 33; ++k ) {
    std::cout << k << "\t" << std::hex << k << std::dec << std::endl;
  }

  std::cout << 42 << "\t" << std::hex << 42 << std::dec << std::endl;

  while ( true ) {
    int n{};
    std::cout << "Enter a positive integer (0 to quit): ";
    std::cin >> n;

    if ( n == 0 ) {
      break;
    } else if ( n >= 0 ) {
      std::cout << n << "\t" << std::hex << n << std::dec << std::endl;
    } 
  }

  return 0;
}