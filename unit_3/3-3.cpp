#include <iostream>
#include <cassert>

// Function declarations
int main();
std::size_t binary_search( double      const array[],
                           std::size_t const capacity,
                           double      const value );

std::size_t is_sorted( double      const array[],
                       std::size_t const capacity );

// Function definitions
int main() {
  // A sorted array
  std::size_t const N{10};
  double data[N]{ 0.2, 1.9, 3.9, 4.0, 4.1,
                    4.3, 6.9, 8.0, 8.4, 9.9 };

  std::cout << "Starting testing" << std::endl;

  for ( int n{0}; n <= 10; ++n ) {
    // 'n' will be converted to a 'double' when
    // the function 'find' is called.
    std::size_t posn{ binary_search( data, N, n ) };

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

  for ( std::size_t k{0}; k < N; ++k ) {
    assert( binary_search( data, N, data[k] ) == k );
  }

  std::cout << "Finished testing" << std::endl;

  return 0;
}




// std::size_t binary_search( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-09-09
// @version   1.0
// 
// @param array    a sorted array of 'double' to be searched
//                 for the given value
// @param capacity the number of entries in the array
//                 'array'
// @param value    the value to be searched for
//
// @returns        if the value is found, the index
//                    at which it is found is returned;
//                 otherwise,
//                    'capacity' is returned
//
// @algorithm
// Algorithm has bounds the entries of the array on which
// the value may be found, inspects the middle entry 
// to determine which half of the array should be searched
// in the case that middle entry is not the entry containing
// the value being searched for.

std::size_t binary_search( double      const array[],
                           std::size_t const capacity,
                           double      const value ) {
  assert( is_sorted( array, capacity ) == capacity );

  std::size_t lower_index{0};
  std::size_t upper_index{capacity - 1};

  while ( (lower_index <= upper_index) && (upper_index < capacity) ) {
    std::size_t average_index{ (lower_index + upper_index)/2 };

    if ( array[average_index] == value ) {
      return average_index;
    } else if ( array[average_index] < value ) {
      lower_index = average_index + 1;
    } else {
      upper_index = average_index - 1;
    }
  }

  return capacity;
}

// std::size_t is_sorted( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-09-09
// @version   1.0
// 
// @param array    an array of 'double' to be checked
//                 to see if it is sorted
// @param capacity the number of entries in the array
//                 'array'
//
// @returns        if the array is sorted, 
//                    'capacity' is returned
//                 otherwise,
//                    the first index at which the entry
//                    is out of order (less than the
//                    previous value) is returned
//
// @definition
// An array is 'sorted' if array[i] <= array[j]
// whenever i <= j.
//
// @algorithm
// This function performs a linear walk through the
// array comparing each pair of entries. As soon as
// an entry less than the previous entry is found,
// the corresponding index is returned. Only if
// each pair of consecutive entries is compared and
// found to be in order is 'capacity' returned.

std::size_t is_sorted( double      const array[],
                       std::size_t const capacity ) {
  for ( std::size_t k{0}; k < capacity - 1; ++k ) {
    if ( array[k] > array[k + 1] ) {
      return k + 1;
    }
  }

  return capacity;
}