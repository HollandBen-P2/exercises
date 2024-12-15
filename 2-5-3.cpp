#include <iostream>

int main();

// Originating author: Wardah Bilal
//
// This program has three bugs and a number of weaknesses
// in the design to help contribute to the existence of 
// some of these bugs. Find the bugs and then try to
// suggest means of correcting the errors and weaknesses.

// int main()
//
// This program queries the user for the capacity of an
// array, and then the array is printed to the screeen.
// The maximum capacity of the array, however, is capped
// to ten.

int main() {
  std::size_t capacity{};

  std::cout << "Enter the capacity of the array: ";
  std::cin >> capacity;

  int *a_seq{ new int[capacity]{} };

  if ( capacity < 10 ) {
    for ( std::size_t k{0}; k < capacity; ++k ) {
      std::cout << "Enter an integer: ";

      std::cin >> a_seq[k];
    }

    std::cout << "Sequence of numbers: ";

    std::cout << a_seq[0];

    for( std::size_t k{1}; k < capacity; ++k ) {
      std::cout << ", " << a_seq[k];
    }
    
    std::cout << std::endl;
  } else {
    std::cout << "The capacity is too large;"
              << std::endl
              << "    the capacity is being set to 10."
              << std::endl;

    capacity = 10;
    a_seq = new int[capacity]{};

    for ( std::size_t k{0}; k < capacity; ++k ) {
      std::cout << "Enter an integer: ";

      std::cin >> a_seq[k];
    }

    std::cout << "Sequence of numbers: ";

    std::cout << a_seq[0];

    for( std::size_t k{1}; k < capacity; ++k ) {
      std::cout << ", " << a_seq[k];
    }
    
    std::cout << std::endl;
  }

  delete[] a_seq;
  return 0;
}






// The first bug is easy to find:
//   If the user enters 10 as the capacity, the user
//   never-the-less gets the error message
//
//       The capacity is too large;
//           the capacity is being set to 10. 
//
// Any user using this code would be confused if they
// entered the value '10' and then got this warning.
//
// This can be easily fixed by updating the condition:
//
//         if ( size <= 10 ) {
//           // ...
//
// 
// The second bug is that in the alternative statement of the
// conditional statement 'if ( capacity < 10 ) {', when
// memory is allocated for an array of capacity 10,
// then the returned pointer overwrites the local
// variable 'a_seq'. The simple fix is to just prepend
// the statement with one that de-allocates the memory:
//
//  } else {
//    // Print warning to screen
//    capacity = 10;
//    delete[] a_seq;  // Delete memory assigned to 'a_seq'
//    a_seq = new int[capacity]{};
//
// The critical point here is to differentiate the
// statements
//    int *a_seq{ new int[capacity]{} };
//    a_seq = new int[capacity]{};
//
// The first is an initialization of the local variable
// 'a_seq' while the second is an assignment to that 
// local variable. If you are ever assigning a pointer
// a new address (be it a return value from 'new' or 
// 'new[...]' or an address assigned to a different
// pointer), you should check to ensure that either:
//
//   1. The pointer being assigned to is currently
//      assigned 'nullptr'.
//   2. There is another variable somewhere that is
//      still storing the address of the memory that
//      is being overwritten.
//   3. If this the memory currently assigned to the
//      variable is indeed no longer needed, de-allocate
//      that memory first and then assign to it.
//
// It is important to remember that calling 'delete' 
// or 'delete[]' on any a pointer that is assigned 
// 'nullptr' does nothing. It is not a bug, it will not
// crash. Thus, the following two pieces of code are
// equivalent:
//
//          delete ptr_variable;
//          ptr_variable = nullptr;
//
//          if ( ptr_variable != nullptr ) {
//            delete ptr_variable;
//            ptr_variable = nullptr;
//          }
//
//
// The third bug is the printing of the array. The code
// tries to be very clever, in that it prints a comma-
// separated list, but what happens if the capacity is
// zero? In this case, 'new[...]' will still return 
// an address, but it would be unwise to access what
// is there. Thus, we should only print the entries
// if the capacity is greater than zero:
//
//    if ( capacity > 0 ) {
//      std::cout << a_seq[0];
//
//      for( std::size_t k{1}; k < capacity; ++k ) {
//        std::cout << ", " << a_seq[k];
//      }
//    }
//
// The above code, however, is still awkward for a number
// of reasons, and instead of simply implementing this
// 'quick-and-dirty fix', how could you rearrange the
// code so that it is better? Read ahead for the
// weaknesses.
//
// Important observation for testing:
//    There are two edge cases in the above code:
//      When the capacity is zero, or the capacity is 10.
// 
//    It is always necessary to write test cases for any
//    edge case as well as for general cases. Thus, in this
//    case, it may be useful to write tests for when the
//    capacity is 0, 1, 5, 9, 10, 11, 1970
//
//    You will observe that we test both edge cases and
//    around edge cases.
//
//    You may be wondering how it is that we can test
//    input and output. 











// The first step is to try to have both memory allocation
// and de-allocation in the same block where possible
//
//    main() {
//      // Do stuff
//      // Allocate memory
//      // Do lots of other stuff
//      // Deallcate memory
//      // Finish
//      return ...;
//    }
//
// One of the reasons many real-time systems do not
// allow a return anywhere else is to ensure that 
// any allocated memory *is* clearly de-allocated.
// For example, this code would be a bug:
//
//    void function_name() {
//      int *a_data[10];
//
//      for ( std::size_t k{0}; k < 10; ++k ) {
//        std::cin >> a_data[k];
//        
//        if ( a_data[k] < 0 ) {
//          return;    // This causes a memory leak...
//        }
//      }
//
//      delete[] a_data;
//      return;
//    }
//
// Another point is that there is a magic number 10
// floating around. It would be better to have a
// constant local variable assigned this maximum, and
// to then use this constant:
//
//     std::size_t const MAX_CAPACITY{ 10 };
//
// To implement the above suggestion to keep 'new'
// and the corresponding 'delete' at the same block,
// we could more easily do the following:
//
//   if ( size <= 10 ) {
//     // Allocate the memory for the array
//     // Query the user for the 'size' values
//     // Print those values
//     // Deallocate the memory for the array
//   } else {
//     // Display the warning.
//     // Allocate the memory for the array of ten values
//     // Query the user for the ten values
//     // Print those values
//     // Deallocate the memory for the array
//   }
//
// However, you may also note that the balance of the code
// is identical. It's always a bad idea to have essentially
// the same code appear twice, for if you make a change to
// the code in one copy, in all likelihood, you'd wnat
// to make the same change to the code in the other copies.
//
//   For exmaple, the above code uses a comma-separated list.
//   A modification may require a space-separated list
//   or a tab-separated list. This would have to be modified
//   in two separate places.
//
//   More importantly, the third bug where a_seq[0] was
//   printed to the screen even if the capacity was zero
//   appeared in both blocks of the conditional statement.
//   A bug report may lead a programmer to find the first
//   bug, but that programmer may not be aware that there
//   is the same bug in the other block.
//
// Thus, it might almost be better to rewrite the code as:
//
//   int main() {
//     std::size_t MAX_CAPACITY{ 10 };
//     std::size_t capacity{};
//  
//     std::cout << "Enter the capacity of the array: ";
//     std::cin >> capacity;
//  
//     if ( capacity > MAX_CAPACITY ) {
//       std::cout << "The capacity is too large;"
//                 << std::endl
//                 << "    the capacity is being set to "
//                 << MAX_CAPACITY << "."
//                 << std::endl;
// 
//       capacity = MAX_CAPACITY;
//     }
//  
//     int *a_seq{ new int[capacity]{} };
// 
//     for ( std::size_t k{0}; k < capacity; ++k ) {
//       std::cout << "Enter an integer: ";
// 
//       std::cin >> a_seq[k];
//     }
// 
//     std::cout << "Sequence of numbers: ";
// 
//     if ( capacity > 0 ) {
//       std::cout << a_seq[0];
//  
//       for( std::size_t k{1}; k < capacity; ++k ) {
//         std::cout << ", " << a_seq[k];
//       }
//     }
//     
//     std::cout << std::endl;
// 
//     delete[] a_seq;
//    return 0;
//  }
//
// Even better, you may realize that printing the array
// has nothing to do with the program in question, and
// therefore it may not be unreasonable to factor this
// functionality out. Note now that the entire main()
// function can appear on a single screen, and what is
// happening when we call 'print_array(...)' is more-or-
// less obvious. The 'print_array(...)' function can also
// now be called from elsewhere.
//
//   int main() {
//     std::size_t MAX_CAPACITY{ 10 };
//     std::size_t capacity{};
//  
//     std::cout << "Enter the capacity of the array: ";
//     std::cin >> capacity;
//  
//     if ( capacity > MAX_CAPACITY ) {
//       std::cout << "The capacity is too large;"
//                 << std::endl
//                 << "    the capacity is being set to "
//                 << MAX_CAPACITY << "."
//                 << std::endl;
// 
//       capacity = MAX_CAPACITY;
//     }
//  
//     int *a_seq{ new int[capacity]{} };
// 
//     for ( std::size_t k{0}; k < capacity; ++k ) {
//       std::cout << "Enter an integer: ";
// 
//       std::cin >> a_seq[k];
//     }
// 
//     std::cout << "Sequence of numbers: ";
//     print_array( a_seq, capacity, ", " ); 
// 
//     delete[] a_seq;
//     return 0;
//   }
//
//   void print_array( int *array, std::size_t capacity,
//                     std::string separator ) {
//     if ( capacity > 0 ) {
//       std::cout << a_seq[0];
//  
//       for( std::size_t k{1}; k < capacity; ++k ) {
//         std::cout << separator << a_seq[k];
//       }
//     }
//     
//     std::cout << std::endl;
//   }
//
//
// Now you may ask yourself: how could this scenario 
// occur: would it not be obvious to author the code
// in the correct way in the first place? Consider the
// following scenario: One programmer authors code
// that does not have any limits for one particular
// variable. A bug report comes in that indicates an
// issue if a particular value is too large, so another
// programmer may put a cap on that. Another programmer
// may then add additional functionality and see that
// that functionality has to be performed in two
// separate locations. Instead of rewriting the code,
// if there is a time crunch for some deadline, the
// programmer may just cut-and-paste; not having the
// time to analyze the code and redesign it. After 
// all, a redesign might take much more time, including
// the authoring of running tests and perhaps authoring
// additional tests.