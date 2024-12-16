#include <iostream>
#include <utility>
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
// @date      2020-11-01
// @version   1.0
// 
// @param array    an array of 'double' to be checked
//                 to see if it is sorted
// @param capacity the number of entries in the array
//                 'array'
// @param value    the value to be searched for
//
// @returns        if the value is not found, 
//                    'capacity' is returned
//                 otherwise,
//                    the index at which the value
//                    was found is returned.
//
// @algorithm
// This function performs a recursive binary search on
// the array:
//   - If there are two or few items on the array, we
//     simply do a linear search and either return 
//     the index where the value was found, or the capacity
//     if thevalue was not found.
//   - Otherwise, we check the middle entry, and if
//     we did not find it there, do a recursive binary
//     search on either the first half or the second
//     half of the array as appropriate.

std::size_t binary_search( double      const array[],
                           std::size_t const capacity,
                           double      const value ) {
  if ( capacity <= 2 ) { 
    for ( std::size_t k{0}; k < capacity; ++k ) {
      if ( array[k] == value ) {
        return k;
      }
    }

    return capacity;
  } else {
    std::size_t middle_index{ capacity/2 };

    if ( array[middle_index] == value ) {
      return middle_index;
    } else if ( value < array[middle_index] ) {
      std::size_t returned_index{
        binary_search( array, middle_index, value )
      };

      if ( returned_index == middle_index ) {
        return capacity;
      } else {
        return returned_index;
      }
    } else {
      return binary_search( array + middle_index + 1,
                            capacity - middle_index - 1,
                            value ) + middle_index + 1;
    }
  }
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