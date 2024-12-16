#include <iostream>

/******************************************************
 * Please read 4.8 Increment-only counters with 
 * operator overloading first.
 *
 * One issue with the current design is that the
 * compiler automaticaly defines a:
 *    copy constructor
 *    move constructor
 *    assignment operator
 *    move operator
 *
 * Now, it is possible to, for example, change the
 * value of one of these increment-only counters
 * by assigning it the value of another such instance
 * of this class.
 *
 * To keep this from happening, you should look at
 * the code below first and note that the value of
 * the local variable 'b' is changed after assignment.
 *
 * By setting the declarations of each of these to
 * 'delete', they are no longer defined, and the 
 * code in main returns an error.
 ******************************************************/

// Class declarations
class Increment_only_counter;

// Function declarations
int main();

// Class definitions
class Increment_only_counter {
  public:
    Increment_only_counter();

    /*
    // Copy constructor
    Increment_only_counter(
      Increment_only_counter const &counter
    ) = delete;
    
    // Move constructor
    Increment_only_counter(
      Increment_only_counter &&counter
    ) = delete;
    
    // Assignment operator
    Increment_only_counter &operator=(
      Increment_only_counter const &rhs
    ) = delete;
    
    // Move operator
    Increment_only_counter &operator=(
      Increment_only_counter &&rhs
    ) = delete;
    */

    unsigned int operator++();
    unsigned int operator++( int );
    unsigned int operator*() const;

  private:
    unsigned int counter_;
};

// Function definitions
int main() {
  Increment_only_counter a{};

  for ( int k{ 0 }; k < 20; ++k ) {
    ++a;
  }

  // Here, '*a' calls operator* on the instance 'a'.
  std::cout << *a << std::endl;

  Increment_only_counter b{};

  std::cout << *b << std::endl;
  // By default, assignment copies over all the data from 'a'
  // to 'b', even if this is not what you want.
  //  - To turn this off, it is necessary to 'delete' the
  //    default copy and move constructors and the
  //    assignment and move operators.
  b = a; 
  std::cout << *b << std::endl;

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