#include <iostream>

/******************************************************
 * Please read 4.8 Increment-only counters first.
 *
 * This implementation attempts to mimic the behavior
 * of pointers using *a, ++a and a++ for the 
 * operations of updating a counter that can only
 * be incremented by one (1).
 *
 * In the last version, we added two member functions:
 *     increment();
 *     value() const;
 *
 * The first incremented the value of counter, and
 * the second returned it.
 *
 *
 * Now, we replace those with the autoincrement
 * operators and the dereference operator.
 ******************************************************/

// Class declarations
class Increment_only_counter;

// Function declarations
int main();

// Class definitions
class Increment_only_counter {
  public:
    Increment_only_counter();

    unsigned int operator++();
    unsigned int operator++( int );
    unsigned int operator*() const;

  private:
    unsigned int counter_;
};

// Function definitions
int main() {
  Increment_only_counter a{};

  // Call the function operator*() to retrieve
  // the current value of 'a'.
  std::cout << *a << std::endl;

  for ( int k{ 17 }; k <= 1532; ++k ) {
    if ( k%17 == 0 ) {
      // Here, '++a' calls operator++()
      // on the instance 'a'.
      ++a;
    }
  }

  // Here, '*a' calls operator* on the instance 'a'.
  std::cout << "There are " << *a
            << " numbers divisible by 17 between"
            << " 17 and 1532, inclusive."
            << std::endl;

  return 0;
} 

// Member function definitions

// Constructor: set the count to zero (0)
Increment_only_counter::Increment_only_counter():
counter_{ 0 } {
  // Empty constructor
}

// This is for '++a'
// where 'a' is an instance of this class.
//
// Increment the counter and return the new value.
unsigned int Increment_only_counter::operator++() {
  ++counter_;

  return counter_;
}

// This is for 'a++'
// where 'a' is an instance of this class.
//
// Increment the counter, but return the old value.
unsigned int Increment_only_counter::operator++( int dummy ) {
  unsigned int old_counter{ counter_ };
  ++counter_;

  return old_counter;
}

// Retrieve the value of the counter.
//  - This is done using '*a' where 'a' is the identifier
//    of the instance of this class.
unsigned int Increment_only_counter::operator*() const {
  return counter_;
}