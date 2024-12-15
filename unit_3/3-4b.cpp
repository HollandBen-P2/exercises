#include <iostream>
#include <utility>
#include <cassert>

// Author a selection sort that works in the
// reverse order of the selection sort we have
// defined, as follows:
//
// Starting with index 0 and going up,
//    find the smallest entry from the current
//    index to the end of the array, and then
//    swap the entry at the current index and
//    the smallest entry.
//
// You may update or define new member functions,
// as you see fit. You should test your code.

// Function declarations
int main();
void selection_sort( double            array[],
                     std::size_t const capacity );

std::size_t find_max( double      const array[],
                      std::size_t const capacity );

std::size_t is_sorted( double      const array[],
                       std::size_t const capacity );

std::size_t find_min( double const array[], std::size_t const capacity);
void reverse_selection_sort(double array[], std::size_t const capacity);

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

  reverse_selection_sort( data, N );

  assert( is_sorted( data, N ) == N );

  data[7] = -0.3;
  assert( is_sorted( data, N ) == 7 );

  reverse_selection_sort( data, N );

  assert( is_sorted( data, N ) == N );

  data[3] = 12.5;
  assert( is_sorted( data, N ) == 4 );

  reverse_selection_sort( data, N );

  assert( is_sorted( data, N ) == N );

  std::cout << "Finished testing" << std::endl;

  return 0;
}

void selection_sort( double            array[],
                     std::size_t const capacity ) {
  for ( std::size_t k{ capacity - 1 }; k > 0; --k ) {
    std::size_t max_index{ find_max( array, k ) };

    if ( array[max_index] > array[k] ) {
      std::swap( array[max_index], array[k] );
    }
  }

  assert( is_sorted( array, capacity ) == capacity );
}

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

std::size_t is_sorted( double      const array[],
                       std::size_t const capacity ) {
    for ( std::size_t k{ 0 }; k < capacity - 1; ++k ) {
        if ( array[k] > array[k + 1] ) {
            return k + 1;
        }
    }

    return capacity;
}

std::size_t find_min(double const array[], std::size_t const capacity) {
    assert(capacity >= 1);
    std::size_t min_index{0};
    for (std::size_t k{0}; k < capacity; ++k) {
        if (array[k] < array[min_index]) {
            min_index = k;
        }
    }

    return min_index;
}

void reverse_selection_sort(double array[], std::size_t const capacity) {

    for (std::size_t k{1}; k < capacity; ++k) {
        std::size_t min_index{find_min(array, k)};

        if (array[k] < array[min_index]) {
            std::swap(array[min_index], array[k]);
        }
    }
}





































// No solutions for this one: you should be able
// to do this, and if not, talk to a friend and 
// see what that individual did, or see if that
// individual can help you.