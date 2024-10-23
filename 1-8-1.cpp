/***********************************
 * Write a function that indicates
 * if a number passed by a user
 * is either odd or even.
 *
 * Be careful about negative 
 * numbers.
 ***********************************/

#include <iostream>

// Function declarations
int main();

// Function definitions
int main() {
  int n{};
  std::cout << "Enter an integer: ";
  std::cin  >> n;

if (n%2 == 0) {
  std::cout << n << " is even." << std::endl;
} else {
    std::cout << n << " is odd." << std::endl;
}
  return 0;
}

































// You will be using the % or remainder operator.
// What happens if n is negative and you calculate n%2?






































// If n is even, then n%2 is always equal to 0.
// If n is odd, then
//      n%2 ==  1 if n > 0
//      n%2 == -1 if n < 0
// Thus, it makes sense to test for evenness.














































// Here is one solution

/*
int main() {
  int n{};
  std::cout << "Enter an integer: ";
  std::cin  >> n;

  if ( n%2 == 0 ) {
    std::cout << n << " is even." << std::endl;
  } else {
    std::cout << n << " is odd." << std::endl;
  }
  
  return 0;
}
*/