#include <iostream>
#include <utility>
#include <cassert>

// Function declarations
int main();
void selection_sort( double            array[],
                     std::size_t const capacity );

std::size_t find_max( double      const array[],
                      std::size_t const capacity );

std::size_t is_sorted( double      const array[],
                       std::size_t const capacity );

// Function definitions
int main() {
  std::size_t const N{10};
  double data[N]{ 4.0, 1.9, 0.2, 8.0, 4.3,
                  8.4, 4.1, 9.9, 3.9, 6.8 };
  
  // Starting with an unsorted array, use selection
  // sort to sort it. Then change entries to make
  // the resulting array unsorted again, and sort it
  // again.

  std::cout << "Starting testing" << std::endl;

  selection_sort( data, N );

  assert( is_sorted( data, N ) == N );

  data[7] = -0.3;
  assert( is_sorted( data, N ) == 7 );

  selection_sort( data, N );

  assert( is_sorted( data, N ) == N );

  data[3] = 12.5;
  assert( is_sorted( data, N ) == 4 );

  selection_sort( data, N );

  assert( is_sorted( data, N ) == N );

  std::cout << "Finished testing" << std::endl;

  return 0;
}

// void selection_sort( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-09-09
// @version   1.0
// 
// @param array    an array of 'double' which is to
//                 be sorted
// @param capacity the number of entries in the array
//                 'array'
//
// @algorithm
// An index 'k' starting at the last index of the array
// and working back to the second index of the array,
//   - Find the maximum entry in the array up to,
//     but not including the entry at 'k'
//   - If the maximum entry is greater than the
//     entry at index 'k', swap the two entries.

void selection_sort( double            array[],
                     std::size_t const capacity ) {
  for ( std::size_t k{ capacity - 1 }; k > 0; --k ) {
    // Find the maximum entry between 0 and 'k'
    std::size_t max_index{ find_max( array, k ) };

    // If the entry at 'max_index' is greater than
    // the last entry, swap them;
    if ( array[max_index] > array[k] ) {
      std::swap( array[max_index], array[k] );
    }
  }

  assert( is_sorted( array, capacity ) == capacity );
}

// std::size_t find_max( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-09-09
// @version   1.0
// 
// @param array    an array of 'double' in which we are
//                 to find the maximum entry
// @param capacity the number of entries in the array
//                 'array'; this must be positive
//
// @returns        the first index at which the maximum
//                 entry of the array is found
//
// @algorithm
// Assume the maximum entry is at index zero.
//
// Step through the array from the second entry to the
// last entry, and if ever an entry is found greater
// than the current maximum, update that index.
//
// It is nonsensical to ask what is the maximum
// entry of an empty array, so we will assert that
// the capacity is greater than or equal to 1.

std::size_t find_max( double      const array[],
                      std::size_t const capacity ) {
  assert( capacity >= 1 );

  std::size_t max_index{ 0 };

  for ( std::size_t k{ 1 }; k < capacity; ++k ) {
    if ( array[k] > array[max_index] ) {
      max_index = k;
    }
  }

  return max_index;
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
    for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
        if ( array[k] > array[k + 1] ) {
            return k + 1;
        }
    }

    return capacity;
}