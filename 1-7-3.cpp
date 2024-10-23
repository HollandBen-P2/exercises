#include <iostream>

// Write a number like 52134/321 as
//  52134/321 = 162 + 132/321
// where 91/13 is written as
//  91/13 = 7 + 0/13
//
// You may assume the user is entering valid
// numerators (0, 1, 2, 3, 4, ...) and valid
// denominators (1, 2, 3, 4, ...)

// Function declarations 
int main();

// Function definitions
int main() {
  int num{};
  std::cout << "Enter a non-negative numerator: ";
  std::cin  >> num; 

  int den{};
  std::cout << "Enter a positive denominator: ";
  std::cin  >> den; 

    int whole{num/den};

    int left_num{num%den};


  std::cout << num << "/" << den << " = " << whole << " + " << left_num << "/" << den << std::endl;

  return 0;
}







































// Hint: 
//  What is 52134/321 and what is  52134%321?
















































// A solution:
/*
int main() {
  int num{};
  std::cout << "Enter a non-negative numerator: ";
  std::cin  >> num; 

  int den{};
  std::cout << "Enter a positive denominator: ";
  std::cin  >> den; 

  std::cout << num << "/" << den << " = "
            << (num/den) << " + "
            << (num%den) << "/"
            << den << std::endl;
  
  return 0;
}
*/