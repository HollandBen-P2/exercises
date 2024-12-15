#include <iostream>
#include <cstddef>

// The following function prints an array, and
// if that array is the nullptr, then nothing
// should be printed.

// Function declarations
int main();
void print_array( double array[], std::size_t capacity );

// Function definitions
int main() {
  double data1[3]{
    4.55, 8.23, 1.23
  };

  double *data2{ new double[10]{
    27,  0,  1, 13, 25, 18, 16,  4, 28, 30
  } };

  print_array( data1, 3 );
  print_array( data2, 10 );

  return 0;
}

// This should print an array in the form
//     {1, 2, 3, 4}
// including, possibly, {}.

void print_array( double array[], std::size_t capacity ) {
  std::cout << "{";

  std::cout << array[0];

  for ( std::size_t k{ 1 }; k < capacity; ++k ) {
    std::cout << ", " << array[k];
  }

  std::cout << "}" << std::endl;
}







































// Hints: What happens if the capacity is zero?
//        What happens if the array is nullptr?
// What should the output be if the array is nullptr?