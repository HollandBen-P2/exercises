#include <iostream>

// Here are seven functions that purport (claim) to
// determine if an array with 'capacity' entries 
// is sorted or not. Recall that the return value
// is:
//    1. 'capacity' if the array is sorted, or
//    2. the index of the first entry that is
//       out of order (a value between '0' and
//       'capacity - 1').
//
// Not all of these functions work correctly.
// Inspect each function and determine which
// work and which do not, and explain or give
// a counter-example as to why those that do not
// work don't actually work.

// Function declarations
int main();
std::size_t is_sorted_1( double      const array[],       
                         std::size_t const capacity );
std::size_t is_sorted_2( double      const array[],       
                         std::size_t const capacity );
std::size_t is_sorted_3( double      const array[],       
                         std::size_t const capacity );
std::size_t is_sorted_4( double      const array[],       
                         std::size_t const capacity );
std::size_t is_sorted_5( double      const array[],       
                         std::size_t const capacity );
std::size_t is_sorted_6( double      const array[],       
                         std::size_t const capacity );
std::size_t is_sorted_7( double      const array[],       
                         std::size_t const capacity );

// Function definitions
int main() {
  std::size_t const N{ 1 };
  double data[N]{ 6.0 };
  // std::size_t const N{ 10 };
  //double data[N]{ 0.1, 1.2, 2.3, 3.4, 4.5,
  //                 5.6, 6.7, 7.8, 8.9, 9.0 };

  std::cout << is_sorted_1( data, N ) << std::endl;
  std::cout << is_sorted_2( data, N ) << std::endl;
  std::cout << is_sorted_3( data, N ) << std::endl;
  std::cout << is_sorted_4( data, N ) << std::endl;
  std::cout << is_sorted_5( data, N ) << std::endl;
  std::cout << is_sorted_6( data, N ) << std::endl;
  std::cout << is_sorted_7( data, N ) << std::endl;

  return 0;
}

//works as intended
std::size_t is_sorted_1( double      const array[],             
                         std::size_t const capacity ) {
  for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
    if ( array[k] > array[k + 1] ) {
      return k + 1;
    }
  }
  
  return capacity;
} 

//works as intended
std::size_t is_sorted_2( double      const array[],             
                         std::size_t const capacity ) {
  for ( std::size_t k{1}; k < capacity; ++k ) {
    if ( array[k - 1] - array[k] > 0 ) {
      return k;
    }
  }
  
  return capacity;
}

//not incrementing k, also cannot ever return capacity
std::size_t is_sorted_3( double      const array[],       
                         std::size_t const capacity ) {
  std:size_t k{ 1 };

  while ( k < capacity ) {
   if ( array[k - 1] > array[k] ) {
     break;
   } 
  }

  return k;
}

//encounters an error when you k = capacity - 1, since you cannot access array[k + 1]
std::size_t is_sorted_4( double      const array[],             
                         std::size_t const capacity ) {
  for ( std::size_t k{ 0 }; k < capacity; ++k ) {
    if ( array[k] > array[k + 1] ) {
      return k + 1;
    }
  }
  
  return capacity;
}

//the current number is allowed to be equal to the next one so this is incorrect, also the comparison is backwards
std::size_t is_sorted_5( double      const array[],             
                         std::size_t const capacity ) {
  for ( std::size_t k{ 1 }; k < capacity; ++k ) {
    if ( array[k] <= array[k - 1] ) {
      return k + 1;
    }
  }
  
  return capacity;
}

//the current number is allowed to be equal to the next one so this is incorrect
std::size_t is_sorted_6( double      const array[],             
                         std::size_t const capacity ) {
  for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
    if ( array[k] >= array[k + 1] ) {
      return k + 1;
    }
  }
  
  return capacity;
} 

//should return k + 1
std::size_t is_sorted_7( double      const array[],             
                         std::size_t const capacity ) {
  for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
    if ( array[k] > array[k + 1] ) {
      return k;
    }
  }
  
  return capacity;
} 






















































// Examples 1 and 2 work.
// Example 3 works unless 'capacity == 0' (why?)
// Example 4 fails because it compares 
//    array[capacity - 1] and array[capacity]
// as the final step, but the entries of the array
// only go from 0 to capacity - 1. Thus, if the
// array is sorted, we end up looking at an
// entry that is not in the array.
// Example 5 fails because the comparison does
// not work correctly.
// Example 6 fails if any two entries in the
// array have the same value, in which case,
// it suggests the array is not sorted at that
// location.
// Example 7 fails as it returns the last
// sorted entry, not the entry that is the
// first entry that is not sorted.