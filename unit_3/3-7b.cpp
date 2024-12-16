#include <iostream>
#include <cassert>

// Author a function T(n) such that
//           /
//          (   1             n = 1
//           )
//   T(n) = <
//           )
//          (  T(n - 1) + 1   n > 1
//           \
//
// asserting that n >= 1.
//
// In your program, write a loop that calculates
// the value of T(n) for values of n until you
// can determine a formula for T(n).

// Function declarations
int main();
unsigned int T( unsigned int n );

// Function definitions
int main() {
  for (unsigned int x{1}; x < 25; ++x) {
    std::cout << T(x) << std::endl;
  }
  return 0;
}

unsigned int T( unsigned int n ) {
  assert(n >= 1);
  if (n == 1) {
    return 1;
  } else {
    return T(n - 1) + 1;
  }
}














































// Here is the program, but what is the pattern?
/*
int main() {
  for ( unsigned int k{ 1 }; k <= 10; ++k ) {
    std::cout << "T(" << k << ") = " << T(k)
              << std::endl;
  }

  return 0;
}

unsigned int T( unsigned int n ) {
  assert( n >= 1 );
  if ( n == 1 ) {
    return 1;
  } else {
    return T( n - 1 ) + 1;
  }
}
*/














































// This one is straight-forward:
//   T(n) = n
//
// You may wonder, however, why anyone cares.
//
// How many additions are required if you add 'n' 
// numbers? Well, if you have 'n' numbers, the amount
// of additions required is adding the first number
// plus the number of additions required to add
// the remaining 'n - 1' numbers.
//
// This should be obvious, but go onto the next two
// problems. You might want to cut-and-paste your
// code from this one, and then make small 
// modifications.