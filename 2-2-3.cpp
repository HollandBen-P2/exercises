#include <iostream>
#include <cassert>

// Previously, you wrote a function that
// calculates the sum of the divisors of
// a given integer, each raised to a
// power 'k'. 
//
// Suppose instead we wanted to calculate 
// all such sums for all integers from
// 0 to n. We could call the function
// n + 1 times, but this would require
// a lot of work at each step:
//
// Instead, we could have an array, and
// then go through the integers from 1 to
// 'n' and add this number raised to the
// power 'k' for each integer multiple
// of that number.
//
// This function would have to allocate
// an appropriately sized array, populate
// that array, and then return it.
//
// The calling funciton would have to 
// delete it.

// Function declarations
int main();
unsigned long *sigma_array(
  unsigned long n,
  unsigned long k = 1
);

long pow( long m, unsigned long n );

int main() {
  unsigned long *a_sigma{
    sigma_array( 40, 0 )
  };
  
  for ( int m{ 0 }; m <= 40; ++m ) {
    std::cout << "sigma(" << m << ", 0) = "
              << a_sigma[m] << std::endl;
  }

  std::cout << std::endl;
  // After deleting the array, we're
  // immediately overwriting it
  delete[] a_sigma;
  a_sigma = sigma_array( 40, 1 );
  
  for ( int m{ 0 }; m <= 40; ++m ) {
    std::cout << "sigma(" << m << ", 1) = "
              << a_sigma[m] << std::endl;
  }

  delete[] a_sigma;
  a_sigma = nullptr;

  return 0;  
}

unsigned long *sigma_array(
  unsigned long n,
  unsigned long k
) {
  
  unsigned long *a_nums{new unsigned long[n + 1]};
  
  for (std::size_t i{0}; i <= n; ++i) {
    a_nums[i] = 0;
  }

  for (unsigned int divisor{1}; divisor <= n; ++divisor) {
    for (unsigned long i{1}; i*divisor <= n; ++i) {
        a_nums[i*divisor] += pow(divisor, k);
    }
  }
  
  return a_nums;
}

long pow( long n, unsigned long m ) {
  long product{ 1 };
  long n_to_power_of_2{ n };
  unsigned long power_of_2{ 1 };

  while ( power_of_2 <= m ) {
    if ( (m & power_of_2) == power_of_2 ) {
      product *= n_to_power_of_2;
    }

    // Square the the previous
    // square of 'n' and multiply
    // the power by 2.
    n_to_power_of_2 *= n_to_power_of_2;
    power_of_2 <<= 1;
  }

  return product;
}









// Here is one solution:


/* unsigned long *sigma_array(
  unsigned long n,
  unsigned long k
) {
  unsigned long *a_values{
    new unsigned long[n + 1]
  };

  for ( std::size_t k{ 0 }; k <= n; ++k ) {
    a_values[k] = 0;
  }

  for (
    unsigned int divisor{ 1 };
    divisor <= n;
    ++divisor
  ) {
    for (
      unsigned long m{ 1 };
      m*divisor <= n;
      ++m
    ) {
      a_values[m*divisor] += pow( divisor, k );
    }
  }

  return a_values;
} */
