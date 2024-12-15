#include <iostream>

// You are asked to investigate a bug, and you 
// come across the following undocumented function
// that is called. Try to determine what this
// function does, and add appropriate documentation,
// if you wish.
//
// Can you explain what the two smaller conditional
// statements that return 0 do, and why?

// Function declarations
int main();
unsigned int is_sorted( double      const array[],
                        std::size_t const capacity );

// Function declarations
int main() {
  std::size_t const N{ 2 };
  double array[N]{ 1.25, 1.25 };

  std::cout << is_sorted( array, N ) << std::endl;

  return 0;
}

unsigned int is_sorted( double      const array[],
                        std::size_t const capacity ) {
  unsigned int a{ 1 }; //0001
  unsigned int b{ 2 }; //0010

  for ( std::size_t k{ 1 }; k < capacity; ++k ) {
    if ( array[k - 1] < array[k] ) {
      a = 0;

      if ( b == 0 ) {
        return 0;
      }
    }

    if ( array[k - 1] > array[k] ) {
      b = 0;

      if ( a == 0 ) {
        return 0;
      }
    }
  }

  return a | b;
}
















































// This function returns 0 if the array is
// not sorted in either increasing order, or
// in decreasing order. It returns 1 if the
// array is sorted in decreasing order (so,
// from largest to smallest), 2 if the array
// is sorted in increasing order (so from
// smallest to largest), and 3 if the array
// is both increasing and decreasing (that
// is, all entries are the same).