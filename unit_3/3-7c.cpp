#include <iostream>
#include <cassert>

// Author a function T(n) such that
//           /
//          (   1             n = 1
//           )
//   T(n) = <
//           )
//          (  T(n - 1) + n   n > 1
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
  for (int j{1}; j < 25; ++j) {
    std::cout << T(j) << std::endl;
  }
  return 0;
}

unsigned int T( unsigned int n ) {
  assert(n >= 1);
  if (n == 1) {
    return 1;
  } else {
    return T(n - 1) + n;
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
    return T( n - 1 ) + n;
  }
}
*/














































// This one may not be so obvious. Here is the
// output (formatted slightly):
// 
//   T(1) =   1
//   T(2) =   3
//   T(3) =   6
//   T(4) =  10
//   T(5) =  15
//   T(6) =  21
//   T(7) =  28
//   T(8) =  36
//   T(9) =  45
//   T(10) = 55
//
// Do you see a pattern? What is the 
// value of 1 + 2 + 3 + 4 + 5 + 6 + 7?
//
// In secondary school, what was the formula you
// learned for the sum of the first 'n' integers?





































// As you hopefully determined, we have that
//
//            n(n + 1)
//    T(n) = ----------
//               2
//
// As this is the formula for adding the digits
//
//      1 + 2 + 3 + 4 + ... + (n - 1) + n
//
// Where does this apply? Recall the problem of
// selction sort, where at the 'k'th step, you
// must:
//   1. Search through 'k' entries to find the
//      largest, and having found it,
//   2. Apply selection sort to the remaining
//      'k - 1' entries at the start of the
//      array.
//
// This formula tells you the number of entries
// that must be compared to find the largest
// over and over again.