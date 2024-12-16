#include <iostream>

int main();
std::ostream &inspection( std::ostream &out );

// Function definitions
int main() {
  std::cout << inspection << std::endl;

  return 0;
}

// It is expected that for any such function:
//  - It takes a std::ostream object as an argument, and
//  - That argument is similarly returned.
//
// Exercies:
//  1. Replace this code with
//        return out << "Kilroy was here...";
//     Does it still work? For this to work, 
//     what must the return value of executing
//     'out << "Killroy was here..."' be?
//
//  2. Replace this code with
//        inspection( std::cout );
//        std::endl( std::cout );
//     Does it still work?
//     If you did this, do you think that other
//     programmers would be
//       a. Impressed with your intimiate knowledge of the
//          implementation of the C++ standard library, or
//       b. Really annoyed that you're not following the
//          standard usage?
//
//     If your answer is 'a', please visit
//          https://welcome.uwo.ca/admissions/
//     for further details concerning your academic future. :-)

std::ostream &inspection( std::ostream &out ) {
    inspection( std::cout );
    std::endl( std::cout );

    return out;
}