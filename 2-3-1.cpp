#include <iostream>
#include <cmath>

// Function declarations
int main();
void initialize_array( double array[], std::size_t capacity, double value );

// Function definitions
int main() {
  double *a_data{ new double[10] };

  initialize_array( a_data, 10, 3.14 );

  delete a_data;
  a_data = nullptr;

  // initialize_array( a_data, 10, 3.14 );

  return 0;
}

// Set all the entries in the array to the value
void initialize_array( double array[], std::size_t capacity, double value ) {
  if ( array == nullptr ) {
    array[0] = 0.0;
  } else {
    for ( std::size_t k{ 0 }; k <= capacity; ++k ) {
      array[k] = value;
    }
  }
}















































// There are three errors:
//  First, you cannot index an array that
//  is the null pointer.
//
//  Second, the for loop should have a
//  condition k < capacity.
//
//  Third, you must use delete[] a_data;
//  when deallocating an array.
//   - You should infer this from the
//     warning from the compiler.