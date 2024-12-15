#include <iostream>

// This code does not work for some
// values of 'n' and 'k'. Add logging to try
// to determine the problem. You don't have
// to fix the problem. For example,
//     13 choose 1
// should equal 13.

// Function declarations
int main();
long long factorial( long long n );

// Function defintions
int main() {
  long long n{};
  std::cout << "Enter a positive integer: ";
  std::cin >> n;

  int k{};
  std::cout << "Enter another positive integer: ";
  std::cin >> k;

  if ( (n < 0) || (k < 0) || (k > n) ) {
    return 0;
  }

  long long nf{ factorial( n ) };

  long long kf{ factorial( k ) };
  std::cout << nf << std::endl;
  std::cout << kf << std::endl;
  long long nkf{ factorial( n - k ) };
  
  std::cout << n << " choose " << k
            << " = " << nf/kf/nkf << std::endl;

  return 0;
}

long long factorial( long long n ) {
  long long result{ 1 };

  for ( int k{ 1 }; k <= n; ++k ) {
    result *= k;
  }

  return result;
}

//so the problem was int doesnt have enough memory to store all of 13!, causing integer overflow