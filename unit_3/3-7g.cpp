#include <iostream>
#include <cassert>

// The Ackermann function is related to the
// run-time of a particularly efficient 
// implementation of a data structure
// called a 'disjoint set'. 
//
// You read up on the Ackermann function on
// Wikipedia, and you see that
//         A(n) = A(n,n)
// where the bivariate Ackermann function is
// defined as:
//
//             A(0, n) = n + 1
//         A(m + 1, 0) = A(m, 1)
//     A(m + 1, n + 1) = A(m, A(m + 1, n ))
//
// Implement these functions.
//
// References:
//   https://en.wikipedia.org/wiki/Ackermann_function

// Function declarations
int main();
unsigned long Ackermann(
  unsigned long n
);
unsigned long Ackermann(
  unsigned long m,
  unsigned long n
);

// Function definitions
int main() {
  for ( unsigned long n{ 0 }; n <= 3; ++n ) {
    std::cout << "A(" << n << ") = "
              << Ackermann( n ) << std::endl;
  }

  for ( unsigned long m{ 0 }; m <= 3; ++m ) {
    for ( unsigned long n{ 0 }; n <= 6; ++n ) {
      std::cout << Ackermann( m, n )
                << "\t";
    }

    std::cout << std::endl;
  }

  // The last one below, A(4, 1), which equals
  //                  2
  //                 2
  //                2
  //     A(4, 1) = 2  - 3,
  //
  // takes a few seconds to calculate
  //  - Don't even try to calculate
  //                    2
  //                   2
  //                  2
  //                 2
  //      A(4, 2) = 2     - 3
  //
  //    or
  //                      2
  //                     2
  //                    2
  //                   2
  //                  2
  //                 2
  //      A(4, 4) = 2     - 3
  
  for ( unsigned long n{ 0 }; n <= 1; ++n ) {
    std::cout << Ackermann( 4, n )
              << "\t";
  }
  
  std::cout << std::endl;

  return 0;
}
/* 
unsigned long Ackermann(
  unsigned long n
) {
  return Ackermann(n, n);
}
 */
//
//             A(0, n) = n + 1
//         A(m + 1, 0) = A(m, 1)
//     A(m + 1, n + 1) = A(m, A(m + 1, n ))
//
/* 
unsigned long Ackermann(
  unsigned long m,
  unsigned long n
) {
  if (m == 0) {
    return n + 1;
  } else if (n == 0) {
    return Ackermann(m - 1, 1);
  } else {
    return Ackermann(m - 1, Ackermann(m + 1, n));
  }

}

 */







// Hint:
// 
// The instructions:
//
//             A(0, n) = n + 1
//         A(m + 1, 0) = A(m, 1)
//     A(m + 1, n + 1) = A(m, A(m + 1, n ))
//
// can be translated into:
//
//             /
//            (   n + 1                m = 0
//             )
//  A(m, n) = <   A(m - 1, 1)          n = 0
//             )
//            (  A(m - 1, A(m, n - 1)) otherwise
//             \



















// Here is one solution

unsigned long Ackermann(
  unsigned long n
) {
  return Ackermann( n, n );
}

unsigned long Ackermann(
  unsigned long m,
  unsigned long n
) {
  if ( m == 0 ) {
    return n + 1;
  } else if ( n == 0 ) {
    return Ackermann( m - 1, 1 );
  } else {
     std::cout << "[" << m << "," << n << "], ";
     return Ackermann(
       m - 1, Ackermann( m, n - 1 )
    );
  }
}
