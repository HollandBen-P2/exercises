#include <iostream>
#include <cassert>

// Function declarations
unsigned long* prime_array(unsigned long n);

int main() {
    unsigned long* a_primes = prime_array(1000);
    
    // Ensure there is at least one prime number...
    assert(a_primes != nullptr); // Check if the array is not null
    assert(a_primes[0] != 0); // Ensure the first prime is not zero

    // Print the prime numbers
    std::cout << "Prime numbers up to 1000: ";
    
    for (std::size_t k = 0; a_primes[k] != 0; ++k) {
        std::cout << a_primes[k];
        if (a_primes[k + 1] != 0) { // Check if the next number is not zero before printing a comma
            std::cout << ", ";
        }
    }

    std::cout << std::endl;

    // Deallocate the memory for the array
    delete[] a_primes;
    a_primes = nullptr;
    
    return 0;  
}

unsigned long* prime_array(unsigned long n) {
    // Ensure the number entered is 2 or greater
    if (n < 2) {
        return nullptr;
    }

    // Create an array with boolean values set to true for every number up to and including n
    bool* a_allnums = new bool[n + 1];
    for (std::size_t i = 0; i <= n; ++i) {
        a_allnums[i] = true; // Assume all numbers are prime initially
    }
    a_allnums[0] = a_allnums[1] = false; // 0 and 1 are not prime numbers

    // Follow the prime number algorithm (Sieve of Eratosthenes)
    for (std::size_t k = 2; k * k <= n; ++k) {
        if (a_allnums[k]) {
            for (std::size_t j = k * k; j <= n; j += k) {
                a_allnums[j] = false; // Mark multiples of k as not prime
            }
        }
    }

    // Count how many trues are in the array
    unsigned long prime_count = 0;
    for (std::size_t y = 2; y <= n; ++y) {
        if (a_allnums[y]) {
            ++prime_count; // Increment count for each prime found
        }
    }

    // Create an array to hold the prime numbers
    unsigned long* a_primes = new unsigned long[prime_count + 1]; // +1 for the terminating 0
    unsigned long index = 0;

    // Fill the a_primes array with the prime numbers
    for (unsigned long p = 2; p <= n; ++p) {
        if (a_allnums[p]) {
            a_primes[index] = p;
            ++index;
        }
    }
    a_primes[index] = 0; // Set the last element to 0 to indicate the end

    // Clean up the dynamic array
    delete[] a_allnums;

    return a_primes; // Return the array of prime numbers
}






























// Hint:
//  Create the array as described in
//  the sieve of Eratosthenes
//   - This should be an array of all
//     Boolean values
//
//  Perform the algorithm described 
//  and set all non-primes in the 
//  array to false
//
//  Count the number of primes left
//
//  Create a new array that is one more
//  than the number of primes left
//
//  Walk through the integers, and each
//  time you determine one is prime, copy
//  it to the new array.
//
//  Set the last entry in the array of
//  prime numbers to 0.



















































// Here is one solution:
/*
unsigned long *prime_array(
  unsigned long n
) {
  // This array is locally declared, so the
  // memory is automatically deallocated when
  // the function returns.
  bool a_is_prime[n + 1];

  // Set both array indices 0 and 1 to false
  //  Neither 0 nor 1 is prime.
  a_is_prime[0] = a_is_prime[1] = false;

  // Assume these integers are prime
  // until proven otherwise...
  for ( std::size_t k{ 2 }; k <= n; ++k ) {
    a_is_prime[k] = true;
  }

  // Find all numbers that are not prime
  // according to the algorithm
  // described in the Sieve of
  // Eratosthenes
  std::size_t next_prime{ 2 };

  while ( next_prime*next_prime <= n ) {
    // Find the next prime number
    while ( !a_is_prime[next_prime] ) {
      ++next_prime;
    }

    // If 'p' is determined to be 
    // prime, then starting at
    // p*p, mark that number as
    // not prime, and continue
    // marking p*p + p, p*p + 2p, ...
    // as not being prime until you
    // get past 'n'.
    for (
      std::size_t m{ next_prime*next_prime };
      m <= n;
      m += next_prime
    ) {
      a_is_prime[m] = false;
    }

    ++next_prime;
  }

  // Count the numnber of prime numbers,
  // which is all entries in the array
  // 'a_is_prime' that are still set to
  // 'true'.
  std::size_t prime_count{ 0 };

  for ( std::size_t k{ 2 }; k <= n; ++k ) {
    if ( a_is_prime[k] ) {
      ++prime_count;
    }
  }

  std::cout << prime_count << std::endl;
  
  // The last entry will be zero...
  unsigned long *a_primes{
    new unsigned long[prime_count + 1]
  };

  for (
    std::size_t k{ 0 }, prime_index{ 2 };
    k < prime_count;
    ++prime_index
  ) {
    if ( a_is_prime[prime_index] ) {
      a_primes[k] = prime_index;
      ++k;
    }
  }
  
  std::cout << "*" << std::endl;
  
  a_primes[prime_count] = 0;

  return a_primes;
}
*/