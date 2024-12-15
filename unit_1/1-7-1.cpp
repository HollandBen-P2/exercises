#include <iostream>

// Function declarations
int main();

// Function definitions
int main() {
  double x{};
  std::cout << "Enter a value of x: ";
  std::cin >> x;

  //                                2
  // This evaluates the polynomial x  - 2x + 1 with
  // the currently assigned value of 'x', which will
  // be whatever value the user enters.
  double y{ x*x - 2.0*x + 1.0 };

  std::cout << " 2"                  << std::endl;
  std::cout << "x  - 2x + 1 = " << y << std::endl;

  // Now that 'y' has been declared and initialized,
  // if you want to give 'y' a new value, you must
  // use the assignment operator.

  // Try writing some code here to evaluate the
  //                3       2
  // polynomial 2.5x  - 4.7x  + 2.3x + 1.4
  // If you give 'x' the value of 1.5, this should
  // print out the value 2.7125.

  double z{2.5*x*x*x - 4.7*x*x + 2.3*x + 1.4};

  std::cout << "z = " << z <<std::endl;

  y = x*x - 2.0*x + 1.0;
  std::cout << y << std::endl;

  // What happens if you accidentally use ^ for 
  // exponentiation? Uncomment this to see.

//   y = x^2 - 2.0*x + 1.0;
//   std::cout << y << std::endl;

  return 0;
}