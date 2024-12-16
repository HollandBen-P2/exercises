#include <iostream>
#include <cassert>

// Function declarations
int main();
void selection_sort_1( double            array[],
                       std::size_t const capacity );
void selection_sort_2( double            array[],
                       std::size_t const capacity );
void selection_sort_3( double            array[],
                       std::size_t const capacity );
void selection_sort_4( double            array[],
                       std::size_t const capacity );
void selection_sort_5( double            array[],
                       std::size_t const capacity );

std::size_t find_max( double      const array[],
                      std::size_t const capacity );
void copy_array( double      const source[],
                 double            destination[],
                 std::size_t const capacity );
void print_array( double      const array[],
                  std::size_t const capacity );

int main() {
  std::size_t const N{ 10 };
  double array[N]{ 2.8, 8.4, 6.2, 6.5, 1.9,
                   7.5, 0.9, 2.0, 9.9, 6.3 };

  double unsorted_array[N];

  copy_array( array, unsorted_array, N );
  selection_sort_1( unsorted_array, N );
  print_array( unsorted_array, N );

  copy_array( array, unsorted_array, N );
  selection_sort_2( unsorted_array, N );
  print_array( unsorted_array, N );

  copy_array( array, unsorted_array, N );
  selection_sort_3( unsorted_array, N );
  print_array( unsorted_array, N );

  copy_array( array, unsorted_array, N );
  selection_sort_4( unsorted_array, N );
  print_array( unsorted_array, N );

  copy_array( array, unsorted_array, N );
  selection_sort_5( unsorted_array, N );
  print_array( unsorted_array, N );

  return 0;
}

//error: swapping logic is backwards
//uhhh this one works too ig
void selection_sort_1( double            array[],
                       std::size_t const capacity ) {
  for ( std::size_t k{ capacity - 1 }; k > 0; --k ) {
    std::size_t max_index{ find_max( array, k ) };

    if ( array[max_index] > array[k] ) {
      std::swap( array[max_index], array[k] );
    }
  }
}

//the last line does nothing since array[max_index] == array[k]
void selection_sort_2( double            array[],
                       std::size_t const capacity ) {
  for ( std::size_t k{ capacity - 1 }; k > 0; --k ) {
    std::size_t max_index{ find_max( array, k ) };

    if ( array[max_index] > array[k] ) {
      array[max_index] = array[k];
      array[k] = array[max_index];
    }
  }
}

//just doing way too much lowkey
//BUT IT WORKS??
void selection_sort_3( double            array[],
                       std::size_t const capacity ) {
  for ( std::size_t k{ 0 }; k < capacity; ++k ) {
    std::size_t index{ k };

    for ( std::size_t idx{ k + 1 }; idx < capacity; ++idx ) {
      if ( array[idx] < array[index] ) {
        index = idx;
      }
    }

    double tmp{ array[index] };
    array[index] = array[k];
    array[k]     = tmp;
  }
}

//idx is always less than capacity so there is an infinite loop
void selection_sort_4( double            array[],
                       std::size_t const capacity ) {
  for ( std::size_t k{ capacity - 1 }; k > 0; --k ) {
    std::size_t index{ 0 };

    for ( std::size_t idx{ k }; idx < capacity; ++idx ) {
      if ( array[idx] > array[k] ) {
        index = idx;
      } 
    }

    if ( array[index] > array[k] ) {
      std::swap( array[index], array[k] );
    }
  }
}

//i think this one works>???
//it does but it changes the type to be int instead of double :///////// trolling
void selection_sort_5( double            array[],
                       std::size_t const capacity ) {
  for ( std::size_t k{ capacity - 1 }; k > 0; --k ) {
    std::size_t max_index{ find_max( array, k ) };

    if ( array[max_index] > array[k] ) {
      int tmp{ array[max_index] };
      array[max_index] = array[k];
      array[k] = tmp;
    }
  }
}

std::size_t find_max( double      const array[],
                      std::size_t const capacity ) {
  std::size_t max_index{ 0 };

  for ( std::size_t k{ 1 }; k < capacity; ++k ) {
    if ( array[k] > array[max_index] ) {
      max_index = k;
    }
  }

  return max_index;
}

void copy_array( double      const source[],
                 double            destination[],
                 std::size_t const capacity ) {
  for ( std::size_t k{ 0 }; k < capacity; ++k ) {
    destination[k] = source[k];
  }
}

void print_array( double      const array[],
                  std::size_t const capacity ) {
  if ( capacity > 0 ) {
    std::cout << array[0];

    for ( std::size_t k{ 1 }; k < capacity; ++k ) {
      std::cout << ", " << array[k];
    }
  }
  
  std::cout << std::endl;
}