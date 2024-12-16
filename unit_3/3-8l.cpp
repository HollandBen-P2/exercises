#include <iostream>
#include <cassert>

// Function declarations
int main();
void merge_sort( double array[], std::size_t capacity );
void merge( double array[], std::size_t cap_1,
                            std::size_t cap_2 );
std::size_t is_sorted( double      const array[],
                       std::size_t const capacity );

// Function definitions
int main() {
  double data[20]{ 0.912, 0.464, 0.853, 0.168, 0.858,
                   0.316, 0.527, 0.701, 0.356, 0.774,
                   0.154, 0.375, 0.620, 0.844, 0.155,
                   0.332, 0.464, 0.801, 0.294, 0.451};
  merge_sort( data, 20 );

  for ( std::size_t k{0}; k < 20; ++k ) {
    std::cout << data[k] << " ";
  } 

  return 0;
}

void merge_sort( double array[], std::size_t capacity ) {
  // If the capacity is less than or equal to 1,
  //     the array is sorted, so we are done.
  // Otherwise,
  //  - Split the array into two approximately equal parts
  //  - Call merge sort recursively on each part
  //  - Merge the two parts back together again
  if ( capacity <= 1 ) {
    return;
  } else {
    std::size_t capacity_1{ capacity/2 };
    std::size_t capacity_2{ capacity - capacity_1 };

    merge_sort( array, capacity_1 );
    merge_sort( array + capacity_1, capacity_2 );

    merge( array, capacity_1, capacity_2 );
  }
}

void merge( double array[], std::size_t cap_1,
                            std::size_t cap_2 ) {
  assert( is_sorted( array, cap_1 ) == cap_1 );
  assert( is_sorted( array + cap_1, cap_2 ) == cap_2 );

  // Not all C++11 compilers allow initialization of
  // variable length arrays, and thus for this compiler
  // we do not initialize this array.
  //  - Fortunately, we will be overwriting all the entries
  //    that are already there, but it is is never-the-less
  //    good practice to initalize all arrays regardless.
  // double tmp_array[cap_1 + cap_2]{};
  double tmp_array[cap_1 + cap_2];

  std::size_t k1{0};
  std::size_t k2{cap_1};
  std::size_t kt{0};

  // As long as not everything in each half is not
  // copied over, copy the next smallest entry into the
  // temporary array.
  while ( (k1 < cap_1) && (k2 < cap_1 + cap_2 ) ) {
    if ( array[k1] <= array[k2] ) {
      tmp_array[kt] = array[k1];
      ++k1;
    } else { 
      tmp_array[kt] = array[k2];
      ++k2;
    }

    ++kt;
  }

  // Copy all entries left from the left half (if any)
  // to the temporary array.
  while ( k1 < cap_1 ) {
    tmp_array[kt] = array[k1];
    ++k1;
    ++kt;
  }

  // Copy all entries left from the right half (if any)
  // to the temporary array.
  while ( k2 < cap_1 + cap_2 ) {
    tmp_array[kt] = array[k2];
    ++k2;
    ++kt;
  }

  // Copy all the entries back to the original array.
  for ( std::size_t k{0}; k < (cap_1 + cap_2); ++k ) {
    array[k] = tmp_array[k];
  }

  assert( is_sorted( array, cap_1 + cap_2 ) == (cap_1 + cap_2) );
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