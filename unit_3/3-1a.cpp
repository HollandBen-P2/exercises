#include <iostream>
#include <cassert>

// Function declarations
int main();
std::size_t find( double      const array[],
                  std::size_t const capacity,
                  double      const value );

// Function definitions
int main() {
  std::size_t const N{10};
  double data[N]{ 4.0, 1.9, 0.2, 8.0, 4.3,
                  8.4, 4.1, 9.9, 3.9, 6.8 };

  std::cout << "Starting testing" << std::endl;

  for ( int n{0}; n <= 10; ++n ) {
    // 'n' will be converted to a 'double' when
    // the function 'find' is called.
    std::size_t posn{ find( data, N, n ) };

    if ( posn == N ) {
      std::cout << n << " not found" << std::endl;
    } else {
      // Similarly, 'n' will be converted to a 'double'
      // before 'data[pson]' and 'n' are compared.
      assert( data[posn] == n );

      std::cout << n << " found at position " << posn 
                << std::endl;
    }
  }

  std::cout << "Finished testing" << std::endl;

  return 0;
}

// std::size_t find( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-09-09
// @version   1.0
// 
// @param array    an array of 'double' to be searched
// @param capacity the number of entries in the array
//                 'array'
// @param value    a 'double' to be searched for in the
//                 array 'array' from index 0
//                 index 'capacity - 1'
//
// @returns        if 'value' is not found, 
//                    'capacity' is returned
//                 otherwise,
//                    the first index at which 'value' was
//                    found is returned
//
// @algorithm
// This function performs a linear search. As soon as
// the 'value' is found, the corresponding index is
// returned. Only if the 'value' is not found in any
// entry is 'capacity' returned.

std::size_t find( double      const array[],
                  std::size_t const capacity,
                  double      const value ) {
  for ( std::size_t k{0}; k < capacity; ++k ) {
    // If the value is found,
    //         return the corresponding index
    if ( array[k] == value ) {
      return k;
    }
  }

  // The 'value' was not found in the array
  return capacity;
}