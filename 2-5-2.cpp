#include <iostream>

int main() {
  int *p_int{ new int( 42 ) };

  std::cout << " p_int = " <<   p_int  << std::endl;
  std::cout << "*p_int = " << (*p_int) << std::endl;

  std::cout << "Calling 'delete p_int'..." << std::endl;
  
  delete p_int;

  // Note that the address stored by 'p_int'
  // may or may not be the same. If it was 
  // changed, it was changed because there 
  // was a request for memory while printing
  // the string "*p_int = ", and that memory
  // was once again deallocated.
  std::cout << "*p_int = " << (*p_int) << std::endl;

  // It is necessary to set this variable
  // to 'nullptr' to prevent trying to 
  // access this memory location

  // Let's set 'std::cout' to print sixteen
  // significant digits instead of just six.
  std::cout.precision( 16 );
  double *p_pi{ new double{ 3.14159265358979323 } };

  std::cout << "We just allocated memory for 'p_pi'"
            << std::endl;
  std::cout << " p_pi  = " <<  p_pi   << std::endl;
  std::cout << "*p_pi  = " << (*p_pi)  << std::endl;

  std::cout << "*p_int = " << (*p_int) << std::endl;
  std::cout << "We will now assign the 'int' at the"
            << std::endl;
  std::cout << "address 'p_int' the value '0':"
            << std::endl;
  
  *p_int = 0;

  std::cout << "*p_int = " << (*p_int) << std::endl;
  std::cout << "*p_pi  = " << (*p_pi)  << std::endl;

  // Questions:
  //  1. What happened to the value stored
  //     at 'p_pi'
}