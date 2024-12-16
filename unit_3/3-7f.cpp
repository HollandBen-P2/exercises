#include <iostream>
#include <cassert>

// Author a function T(n) such that
//           /
//          (   1                n = 1
//           )
//   T(n) = <
//           )
//          (  2 T(n/2) + n      n > 1
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
  for (int y{1}; y < 45; ++y) {
    std::cout << T(y) << std::endl;
  }
  return 0;
}

unsigned int T( unsigned int n ) {
  assert(n >= 1);
  if (n == 1) {
    return 1;
  } else {
    return 2*T(n/2) + n;
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

  std::cout << std::endl;
  
  for ( unsigned int k{ 1 }; k <= 20; ++k ) {
    std::cout << "T(" << k << ")/" << k << " = "
              << T(k)/(1.0*k) << std::endl;
  }

  return 0;
}

unsigned int T( unsigned int n ) {
  assert( n >= 1 );
  
  if ( n == 1 ) {
    return 1;
  } else {
    return 2*T( n/2 ) + n;
  }
}
*/














































// If you go back to a previous exercies with
// a binary search, we saw that T(n) = floor( log (n) ) + 1
//                                               n
//
// Now, if we look at T(n)/n, we have
//
//   T(1)/1 = 1           <----
//   T(2)/2 = 2           <----
//   T(3)/3 = 1.66667
//   T(4)/4 = 3           <----
//   T(5)/5 = 2.6
//   T(6)/6 = 2.66667
//   T(7)/7 = 2.42857
//   T(8)/8 = 4           <----
//   T(9)/9 = 3.66667
//   T(10)/10 = 3.6
//   T(11)/11 = 3.36364
//   T(12)/12 = 3.66667
//   T(13)/13 = 3.46154
//   T(14)/14 = 3.42857
//   T(15)/15 = 3.26667
//   T(16)/16 = 5         <----
//   T(17)/17 = 4.76471
//   T(18)/18 = 4.66667
//   T(19)/19 = 4.47368
//   T(20)/20 = 4.6
//
// What can you suggest here?


































// You may have noticd that
//      T( n )/n = log ( n ) + 1
//                    2
//
// and therefore
//
//      T( n ) = n * log ( n ) + n
//                       2
//
// Now, where is this applicable? Later in
// this course, we will look at the merge sort
// algorithm. This is an algorithm that 
// creates a sorted list by doing the following:
//
// Let T(n) count the number of comparisons.
//
// To sort an array with 'n' entries, we will
// do the following:
//   1. Apply merge sort to the first half,
//   2. apply merge sort to the second half, and
//   3. merge the two sorted halves.
//
// The number of comparisons depends on 'n', and
// thus, T(n) equals:
//   1. The number of comparisons for the first
//      half, which is T(n/2),
//   2. the number of comparisons for the second
//      half, which is also T(n/2), and
//   3. the number of comparisons to merge is 'n'.
//
// Hence, T(n) = 2*T(n/2) + n
//
// Thus, the number of comparisons is less than
// the number of comparisons for selection sort,
//                          2
// which we saw was T(n) = n .