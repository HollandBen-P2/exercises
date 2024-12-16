#include <iostream>

// Here we will have three different namespaces, each
// containing a function with same identifier, but
// how we can call each one separately.
//
// Any references to companies in this example refer 
// specifically to the Terminator movie series, and not
// any extant company.

// com_cyberdyne
//  - The namespace for the company with a web address
//    www.cyberdyne.com
//  - This is not required, but it one way to ensure that
//    the namespace identifier will be unique.
//
// com_cyberdyne::skynet
//  - The namespace identifier for the Skynet sub-project.
//
// com_cyberdyne_skynet
//  - An alternative namespace identifier for the Skynet
//    sub-project.
//
// Exercises:
//  1. Create a namespace that is linked to you personally.
//     You could use your uWaterloo User ID, which is
//     guaranteed to be unique, so you could use either
//         ca_uwaterloo::uwuserid
//     or
//         ca_uwaterloo_uwuserid

// Function declarations
int main();

namespace com_cyberdyne {
  void f();

  namespace skynet {
    void f();
  }
}

namespace com_cyberdyne_skynet {
  void f();
}

// Function definitions
int main() {
  com_cyberdyne::f();
  com_cyberdyne::skynet::f();
  com_cyberdyne_skynet::f();

  return 0;
}

namespace com_cyberdyne {
  void f() {
    std::cout << "In com_cyberdyne" << std::endl;
  }

  namespace skynet {
    void f() {
      std::cout << "In com_cyberdyne::skynet" << std::endl;
    }
  }
}

namespace com_cyberdyne_skynet {
  void f() {
    std::cout << "In com_cyberdyne_skynet" << std::endl;
  }
}

namespace ca_uwaterloo::b9hollan {
    void f();
}