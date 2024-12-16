#include <iostream>
#include <cassert>

// Author a function T(n) such that
//           /
//          (   1                n = 1
//           )
//   T(n) = <
//           )
//          (  T(n/2) + 1        n > 1
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
  for (int g{1}; g < 35; ++g) {
    std::cout << T(g) << std::endl;
  }
  return 0;
}

unsigned int T( unsigned int n ) {
  assert(n >= 1);
  if (n == 1) {
    return 1;
  } else {
    return T(n/2) + 1;
  }
  
  
  return 1;
}














































// Here is the program, but what is the pattern?
/*
int main() {
  for ( unsigned int k{ 1 }; k <= 20; ++k ) {
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
    return T( n/2 ) + 1;
  }
}
*/














































// This one may not be so obvious. Here is the
// output (formatted slightly):
// 
//   T(1)  = 1
//   T(2)  = 2
//   T(3)  = 2
//   T(4)  = 3
//   T(5)  = 3
//   T(6)  = 3
//   T(7)  = 3
//   T(8)  = 4
//   T(9)  = 4
//   T(10) = 4
//   T(11) = 4
//   T(12) = 4
//   T(13) = 4
//   T(14) = 4
//   T(15) = 4
//   T(16) = 5
//   T(17) = 5
//   T(18) = 5
//   T(19) = 5
//   T(20) = 5



































// You may note that
//    T(1) =  1
//    T(2) =  2
//    T(4) =  3
//    T(8) =  4
//    T(16) = 5
//
// and you may guess that
//    T(32) = 6
//    T(64) = 7
//                              k
// You may remember that log ( 2  ) = k,
//                          2
// but here it seems that
//          k
//      T( 2  ) = k + 1
//
// Next, recall that log ( 3 ) = 1.5850
//                      2
//                   log ( 5 ) = 2.3219
//                      2
//
// Thus, it seems that T(n) = floor( log ( n ) ) + 1
//                                      2
//
// Where does this apply? Recall the binary search,
// where you check the middle element (one look-up),
// and then if you did not find what you are looking
// for, you check either the left half or the right
// half of the array. Thus, if you started by
// searching an array of size 501, then after 
// checking array entry 250 and are unsuccessful,
// then you check either the first 250 or the latter
// 250. In either case, you repeat the same 
// algorithm: check the middle entry and then 
// look at either the first or second half, 
// the largest of which has 125 entries.