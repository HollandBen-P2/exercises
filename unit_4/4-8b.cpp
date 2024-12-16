#include <iostream>

/******************************************************
 * Suppose you have a counter in a program, but you
 * know that, by design, it should never be either
 * assigned to, nor decremented. 
 *
 * For example, you are setting up an accounting system
 * and transactions must be counted one-at-a-time for 
 * taxation purposes, and thus, there is no reason any
 * programmer should want to decrement such a count,
 * or assign to it a value other than simply 
 * incrementing it.
 *
 * To prevent users from changing the value of
 * the member variable 'counter_', it is labeled
 * as 'private:'
 *
 * NOTE: This does not provide security. It only
 *       prevents an honest programmer from making
 *       a programming mistkake.
 *
 * Looking ahead: After the next topic on operator
 *                overloading, we will see how we
 *                can change this class to use 
 *                operators and not .increment() and
 *                .value().
 ******************************************************/

// Class declarations
class Increment_only_counter;

// Function declarations
int main();

// Class definitions
class Increment_only_counter {
  public:
    Increment_only_counter();

    unsigned int increment();
    unsigned int value() const;

  private:
    unsigned int counter_;
};

// Function definitions
int main() {
  Increment_only_counter a{};

  std::cout << a.value() << std::endl;

  for ( int k{ 17 }; k <= 1532; ++k ) {
    if ( k%17 == 0 ) {
      a.increment();
    }
  }

  std::cout << "There are " << a.value()
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

// Increment the counter and return the new value
unsigned int Increment_only_counter::increment() {
  ++counter_;

  return counter_;
}

// Retrieve the value of the counter
unsigned int Increment_only_counter::value() const {
  return counter_;
}