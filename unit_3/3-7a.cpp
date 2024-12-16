#include <iostream>

// Function declarations
int main();
unsigned int factorial( unsigned int n );
unsigned int binomial( unsigned int n, unsigned int k );
unsigned int fibonacci( unsigned int n );
double power( double x, int n );


// Function definitions
int main() {
  std::cout << "5! = " << factorial( 5 ) << std::endl;
  std::cout << "9! = " << factorial( 9 ) << std::endl;

  std::cout << "Choosing from 7 items:" << std::endl
            << "   ";

  for ( int k{0}; k <= 7; ++k ) {
    std::cout << binomial( 7, k ) << " ";
  }

  std::cout << std::endl;

  std::cout << "              F(6) = " << fibonacci( 6 ) << std::endl;
  std::cout << "              F(7) = " << fibonacci( 7 ) << std::endl;
  std::cout << "F(8) = F(7) + F(6) = " << fibonacci( 8 ) << std::endl;

  std::cout << std::endl
            << "1.1 raised to various powers" << std::endl;

  for ( int k{-5}; k <=5; ++k ) {
    std::cout << "   " << k << std::endl;
    std::cout << "1.1   = " << power( 1.1, k ) << std::endl;
  }

  std::cout << "  __" << std::endl
            << "0.90 (0.90 repeating) raised to various powers" << std::endl;

  for ( int k{-5}; k <=5; ++k ) {
    std::cout << "  __" << k << std::endl;
    std::cout << "0.90   = " << power( 0.90909090909090909, k ) << std::endl;
  }

  return 0;
}

unsigned int factorial( unsigned int n ) {
  if ( n <= 1 ) {
    return 1;
  } else {
    unsigned int simpler_result{ factorial( n - 1 ) };
    return n * simpler_result;
  }
}

unsigned int binomial( unsigned int n, unsigned int k ) {
  if ( k > n ) {
    return 0;
  } else if ( (k == 0) || (k == n) ) {
    return 1;
  } else {
    unsigned int result_1{ binomial( n - 1, k ) };
    unsigned int result_2{ binomial( n - 1, k - 1 ) };
    return result_1 + result_2;
  }
}


// Exercise:
//  Implement the recursive definition
//               /         0               n = 0
//              ( 
//               )         1               n = 1 or 2
//       F(n) = <
//               ) F(k)(2F(k + 1) - F(k))  n = 2k
//              (            2       2
//               \   F(k + 1)  - F(k)      n = 2k + 1
//
// Once you have implemented yours, ensure that you are getting
// the correct answers:
//    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
//
// Next, time your implementation versus the implementation below.



unsigned int my_fibonacci(unsigned int n) {
    if (n == 0) {
        return 0;
    } else if (n <= 2) {
        return 1;
    } else {
        unsigned int result1{my_fibonacci(n - 1)};
        unsigned int result2{my_fibonacci(n - 2)};
        return result1 + result2;
    }
}












unsigned int fibonacci( unsigned int n ) {
  if ( n == 0 ) {
    return 0;
  } else if ( n == 1 ) {
    return 1;
  } else {
    unsigned int result_1{ fibonacci( n - 1 ) };
    unsigned int result_2{ fibonacci( n - 2 ) };
    return result_1 + result_2;
  }
}

// Important: Notice that the conditions (n%2 == 0) and 
// (n&1 == 0) are identical: they both identify when the
// integer 'n' is even. However, in this case, we really
// mean that we want to calculate the remainder, and thus
// it is better practice to us 'n%2', rather than being
// clever and using 'n&1'.

double power( double x, int n ) {
  if ( n == 0 ) {
    return 1.0;
  } else if ( n < 0 ) {
    return 1.0/power( x, -n );
  } else if ( (n%2) == 0 ) {
    double result{ power( x, n/2 ) };
    return result*result;
  } else {
    double result{ power( x, n/2 ) };
    return x*result*result;
  }
}

// Exercies:
//  1. The Chebyshev polynomials T are defined as follows:
//        T (x) = 1
//         0
// 
//        T (x) = x
//         1
//
//        T (x) = 2x T   (x) - T   (x)
//         n          n-1       n-2
//
//    Implement T (x) as the function chebyshev_T( unsigned int n, double x )
//               n

double chebyshev_T( unsigned int n, double x );

double chebyshev_T( unsigned int n, double x ) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    } else {
        double result_1{chebyshev_T(n - 1, x)};
        double result_2{chebyshev_T(n - 2, x)};

        return 2*x*result_1 - result_2;
    }
}




//                                             -1
// 2.  Another definition of T (x) is cos( n cos  (x) ) where the inverse
//                            n
//     cosine (or arccosine) is implemented as std::acos in C++ and takes
//     an argument between -1 and 1 inclusive. Implement this as the function
//                                    chebyshev_Ta( unsigned int n, double x )
//     and compare the output of these two functionsfor values of 'x' between
//     -1 and 1, inclusive.
//

double chebyshev_Ta( unsigned int n, double x );

double chebyshev_Ta( unsigned int n, double x ) {

    return std::cos(n*std::acos(x));
}

//  3. The Laguerre polynomials L are defined as follows:
//        L (x) = 1
//         0
// 
//        L (x) = 1 - x
//         1
//                 1   /                                      \
//        L (x) = --- | (2n - 1 - x) L   (x) - (n - 1) L   (x) |
//         n       n   \              n-1               n-2   /
//
//    Implement L (x) as the function laguerre_L( unsigned int n, double x )
//               n
//

double laguerre_L( unsigned int n, double x );

double laguerre_L( unsigned int n, double x ) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1 - x;
    } else {
        return (1.0/n)*((2*n - 1 - x)*laguerre_L(n - 1, x) - (n - 1)*laguerre_L(n - 2, x));
    }
}



// 4.  The Bell numbers B(n) are defined as follows:
//
//       B(0) = 1
//             n - 1
//            -------
//             \
//       B(n) = )      binomial( n - 1, k ) B(k)
//             /
//            -------
//             k = 0
//
//     Implement B(n) as the function bell( unsigned int n )
//





// 5.  The Stirling numbers s(n, k) are defined as
//
//         s(0, 0) = 1
//
//         s(n, 0) = 0        for all n = 1, 2, ...
//
//         s(0, k) = 0        for all k = 1, 2, ...
//
//         s(n, k) = -(n - 1)s(n - 1, k) + s(n - 1, k - 1)
//
//     Implement s(n, k) as stirling( unsigned int n, unsigned int n )
//
// Advanced exercies:
//
// 6.  It is possible in C++ to pass a function identifier as an argument
//     to another function. The parameter must have the same return type
//     and argument types as the function being passed.
//
//     The composite trapezoidal rule for approximately the integral of a
//     function from 'a' to 'b', or
//
//                     / a
//                    |
//                    |  f(x) dx
//                    |
//                   / b
//
//     is defined as follows:
//
//            trapezoidal(0, f, a, b) = 0.5*(f(a) + f(b))*(b - a)
//
//            trapezoidal(n, f, a, b) = trapezoidal(n, f, a, 0.5*(a + b))
//                                       + trapezoidal(n, f, 0.5*(a + b), b)
//
//     Implement this as the function
//         double trapezoidal( unsigned int const n,
//                             double             f(double x),
//                             double       const a,
//                             double       const b );
//
//     and you can test your implementation by finding
//              trapezoidal( 10, std::exp, -4.0, 0.0 )
//
//     Your result should be close to 0.98168436111. As you increase 'n',
//     does your approximation get more exact?