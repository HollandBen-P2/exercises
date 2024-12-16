#include <iostream>

// Function declarations
int main();
void print_binary( int const n );
void print_hexadecimal(int const n);

// Function definitions
int main() {
  for ( int k{-65}; k <= 65; ++k ) {
    std::cout << k << "\t";
    print_hexadecimal( k );
    std::cout << std::endl;
  }

  return 0;
}

// void print_binary( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-11-01
// @version   1.0
// 
// @param n   an integer
//
// @algorithm
// If the argument is negative, print a '-' and recursively
// call this function with '-n'.
//
// If 'n' is either 0 or 1, print that value;
// Otherwise, print out the number without the last
// bit recursively and then print out the last bit.
//
// Exercise:
//   1. What would you do to print a number in octal?
//   2. What would you do to print a number in hexadecimal?

void print_binary( int const n ) {
  if ( n < 0 ) {
    std::cout << "-";
    print_binary( -n );
  } else if ( n <= 1 ) {
    std::cout << n;
  } else {
    // This is equivalent to
    //     print_binary( n/2 );
    //     std::cout << (n%2);
    // but this code uses the bit-shift and
    //  bitwise 'and' operators.
    print_binary( n >> 1 );
    std::cout << (n & 1);
  }
}

void print_hexadecimal(int const n) {
    if (n < 0) {
        std::cout << "-";
        print_hexadecimal(-n);
    } else if (n <= 9) {
        std::cout << n;
    } else if (n == 10) {
        std::cout << "a";
    } else if (n == 11) {
        std::cout << "b";
    } else if (n == 12) {
        std::cout << "c";
    } else if (n == 13) {
        std::cout << "d";
    } else if (n == 14) {
        std::cout << "e";
    } else if (n == 15) {
        std::cout << "f";
    } else {
        print_hexadecimal(n >> 4);
        std::cout << (n & 4);
    }
}