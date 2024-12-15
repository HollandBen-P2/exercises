#include <iostream>
#include <cassert>

// Function declarations
int main();
std::size_t is_sorted( double      const array[],
                       std::size_t const capacity );

// Function definitions
int main() {
  // A sorted array
  std::size_t const N{10};
  double data[N]{ 0.2, 1.9, 3.9, 4.0, 4.1,
                    4.3, 6.9, 8.0, 8.4, 9.9 };

  std::cout << "Starting testing" << std::endl;

  assert( is_sorted( data, N ) == N );

  // Assign three entries in the array to make the
  // array entry there less than the previous entry,
  // thus making the array not sorted.
  data[7] = -0.3;
  assert( is_sorted( data, N ) == 7 );

  data[5] = 0.0;
  assert( is_sorted( data, N ) == 5 );

  data[1] = 0.1;
  assert( is_sorted( data, N ) == 1 );

  std::cout << "Finished testing" << std::endl;

  return 0;
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
//                    the first index at which the entry //                    is out of order (less than the
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
//
// Exercises:
//  1. A slightly more elegant loop would have one
//     start at 1 and go to 'k < capacity'. This
//     results in code that has slightly fewer arithmetic
//     operations and is therefore easier to view.
//     Implement this solution, updating the body
//     as appropriate.

std::size_t is_sorted( double      const array[],
                       std::size_t const capacity ) {
  for ( std::size_t k{1}; k < capacity; ++k ) {
    if ( array[k] < array[k - 1] ) {
      return k;
    }
  }

  return capacity;
}

//previous version:
/*
std::size_t is_sorted( double      const array[],
                       std::size_t const capacity ) {
  for ( std::size_t k{0}; k < capacity - 1; ++k ) {
    if ( array[k] > array[k + 1] ) {
      return k + 1;
    }
  }

  return capacity;
}
*/