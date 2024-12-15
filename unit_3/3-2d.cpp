#include <iostream>

// An array is sorted in increasing order if
// next entry is always greater than or equal
// to the previous entry.
//
// An array is sorted in strict increasing
// order if the next entry is always greater
// than the previous entry.
//
// Update the is-sorted funtion to take a
// third argument that is a Boolean value,
// which, if true, requires that array is
// strictly increasing.
//
// Test your funciton.

// Function declarations
int main();
std::size_t is_sorted(
  double      const array[],       
  std::size_t const capacity,
  bool        const strictly_increasing = false
);

// Function definitions
int main() {
  std::size_t const N{ 2 };
  double data[N]{ 6.0, 6.0 };
  // std::size_t const N{ 10 };

  std::cout << is_sorted( data, N, false ) << std::endl;
  std::cout << is_sorted( data, N, true )  << std::endl;

  return 0;
}

std::size_t is_sorted(
  double      const array[],             
  std::size_t const capacity,
  bool        const strictly_inceasing
) {
  for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
    if ( array[k] > array[k + 1] ) {
      return k + 1;
    } else if (strictly_inceasing == true && array[k] == array[k + 1]) {
        return k + 1;
    }
  }
  
  return capacity;
} 





















































// Here is one possible solution
/*
std::size_t is_sorted(
  double      const array[],             
  std::size_t const capacity,
  bool        const strictly_inceasing
) {
  for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
    if ( array[k] > array[k + 1] ) {
      return k + 1;
    } else if ( strictly_inceasing
            && (array[k] == array[k + 1]) ) {
      return k + 1;
    }
  }
  
  return capacity;
}
*/

// Here is another that only checks the flag once:
/*
std::size_t is_sorted(
  double      const array[],             
  std::size_t const capacity,
  bool        const strictly_inceasing
) {
  if ( strictly_increasing ) {
    for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
      if ( array[k] >= array[k + 1] ) {
        return k + 1;
      }
    }
  } else {
    for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
      if ( array[k] > array[k + 1] ) {
        return k + 1;
      }
    }
  }

  return capacity;
}
*/
