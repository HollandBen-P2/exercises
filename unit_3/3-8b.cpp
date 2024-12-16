#include <iostream>
#include <utility>
#include <cassert>

// Function declarations
int main();
void insertion_sort( double            array[],
                     std::size_t const capacity );

void insert( double            array[],
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

  insertion_sort( data, N );

  assert( is_sorted( data, N ) == N );

  data[7] = -0.3;
  assert( is_sorted( data, N ) == 7 );

  insertion_sort( data, N );

  assert( is_sorted( data, N ) == N );

  data[3] = 12.5;
  assert( is_sorted( data, N ) == 4 );

  insertion_sort( data, N );

  assert( is_sorted( data, N ) == N );

  std::cout << "Finished testing" << std::endl;

  return 0;
}

// void insertion_sort( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-11-01
// @version   1.0
// 
// @param array    an array of 'double' which is to
//                 be sorted
// @param capacity the number of entries in the array
//                 'array'
//
// @algorithm
// If the capacity is less than or equal to one,
//      the array is sorted, so just return;
// Otherwise,
//   - Recursively call insertion sort on the first
//     'capacity - 1' entries.
//   - Insert the last entry into what is now a sorted
//     array of 'capacity - 1' entries.


void insertion_sort( double            array[],
                     std::size_t const capacity ) {
    if ( capacity <= 1 ) {
        return;
    } else {
        insertion_sort( array, capacity - 1 );
        insert( array, capacity );
        // Not required, but just to make sure this is working
        assert( is_sorted( array, capacity ) == capacity );
    }
}


// void insert( ... )
//
// @author    Douglas Wilhelm Harder
// @date      2020-09-09
// @version   1.0
// 
// @param array    an array of 'double' in which all but
//                 the last entry is assumed to be sorted
//                 and the last entry is to be inserted
//                 into the correct location in that array
// @param capacity the number of entries in the array
//                 'array'
//
// @algorithm
// Assume the first 'capacity - 1' entries are sorted.
//
// Store the last entry in a temporary variable 'value',
// and move all entries greater than this 'value' one
// location to the right. This will create an empty
// entry where we can insert the 'value'.
// 
// This is done by starting at the last entry, and
// continuining to the left until either we are at
// the start of the array, or the previous entry
// is less than the 'value'. While these conditions
// are not met, move the previous value to the right
// by one, and continue to the left.

void insert( double            array[],
             std::size_t const capacity ) {
  assert( is_sorted( array, capacity - 1 )
                                == (capacity - 1) );

  double value{ array[capacity - 1] };

  std::size_t k{};

  for ( k = capacity - 1;
     (k > 0) && (array[k - 1] > value); --k ) {
    array[k] = array[k - 1];
  }

  array[k] = value;
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