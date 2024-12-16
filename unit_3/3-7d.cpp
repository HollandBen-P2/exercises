#include <iostream>
#include <cassert>

// Author a function T(n) such that
//           /
//          (   0                n = 1
//           )
//   T(n) = <
//           )
//          (  n T(n - 1) + n    n > 1
//           \
//
// asserting that n >= 1.
//
// In your program, write a loop that calculates
// the value of T(n) for values of n and try to
// describe how quickly T(n) grows with a formula.

// Function declarations
int main();
unsigned int T( unsigned int n );

// Function definitions
int main() {
  
  for (int k{1}; k < 11; ++k) {
    std::cout << T(k) << std::endl;
  }
  return 0;
}

unsigned int T( unsigned int n ) {
  assert(n >= 1);
  if (n == 1) {
    return 0;
  } else {
    return n*T(n - 1) + n;
  }
  
  
  return 0;
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
    return 0;
  } else {
    return n*T( n - 1 ) + n;
  }
}
*/














































// This one may not be so obvious. Here is the
// output (formatted slightly):
// 
//                                      n!
//   T(1)  =       0 =       0          1
//   T(2)  =       2 =     2*0 + 2      2
//   T(3)  =       9 =     3*2 + 3      6
//   T(4)  =      40 =     4*9 + 4     24 
//   T(5)  =     205 =    5*40 + 5    120
//   T(6)  =    1236 =   6*205 + 6    720
//   T(7)  =    8659 =  7*1236 + 7   5040
//   T(8)  =   69280 =  8*8659 + 8
//   T(9)  =  623529
//   T(10) = 6235300



































// There is a complex formula, but it involves not
// on the factorial, but the derivative of the
// factorial. Thus, it is beyond the scope of this
// course. However, we note that:
//
//    T(n) > n! for n >= 3
//
// Where does this apply? One horrible algorithm
// called a "co-factor expansion" for calculating
// the determinant of an n x n matrix has you do
// the following:
//
// Let A be an n x n matrix, and let A    be that
//                                    i,j
// (n - 1) x (n - 1) matrix that has Row i and
// Column j removed. On the other hand, the entries
// of A are represented by a   .  Then
//                          i,j
//
//   det( A ) = a  x det(A   ) - a   x det(A   )
//               1,1      1,1     2,2       2,2
//                                   n
//    + a    x det(A   ) + ... + (-1) a    x det(A  )
//       3,3        3,3                n,n        n,n
//
// This formula above calculates the number of
// multiplications required for such a calculation.
//
// How many multiplications would be required to
// calculate the determinant of a 30 x 30 matrix?
// If you could perform one qunitillion floating-
// point operations (multiplications) per second
// (one petaflop), could you calculate such a
// determinant in the age of the universe?
// 
// Hint: 455779168962082450381327904693700 is 4%
//                      32
// larger than 4.35 x 10  .
//
// Given that the optimal algorithm for calculating
// such a determinant requires fewer than 30^3 = 27000
// multiplications, would you ever use the method of
// co-factor expansion to calculate the determinant?