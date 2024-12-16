#include <iostream>
#include <string>

// The web site https://oeis.org/ 
// stores tens of thousands sequences
//
// Create a class that allows you to
// store sequences with different
// names. You will then add a member
// function that tries to match the
// entries in an array to see if they
// appear in any of the already 
// stored sequences.

// For example, you could add the
// three sequences:
//  "Factorial"
//   {1, 1, 2, 6, 24, 120}
//  "Squares of natural numbers"
//   {1, 4, 9, 16, 25, 36, 49}
//  "Powers of two"
//   {1, 2, 4, 8, 16, 32, 64}
//
// Thus, if you were to search
// for {9, 16, 25}, it would print
//     Squares of natural numbers
// and if you searched for {4},
// this would print
//     Squares of natural numbers
//     Powers of two
//
// You will use a linked list to
// store the sequences.

// Implemented below is a
//            'nested class'
// Only member functions of the
// Sequences class can access or
// even create instances of this
// class.
//
// It is hinted that you add a
// member variable 'is_sorted_'
// which would be 'true' for the
// three above sequences.
//  - You could use this to 
//    speed up your searches :-)

// Class declarations
class Sequences;

// Function declarations
int main();

// Class definitions

class Sequences {
  public:
    Sequences();
    Sequences( Sequences const &orig )           = delete;
    Sequences( Sequences &&orig )                = delete;
    Sequences &operator=( Sequences const &rhs ) = delete;
    Sequences &operator=( Sequences &&rhs )      = delete;

    void add_sequence(
      std::string name,
      int         array[],
      std::size_t capacity
    );

    void match(
      int         array[],
      std::size_t capacity
    ) const;

  private:
    class Node {
      public:
        std::string name_;
        std::size_t capacity_;
        int        *entries_;
        bool        is_sorted_;
    };

    Node *p_list_head;
};

int main() {
  Sequences seqs{};
  seqs.add_sequence(
    "Factorial",
    (int[6]){1, 1, 2, 6, 24, 120},
    6
  );
  seqs.add_sequence(
    "Squares of non-negative integers",
    (int[8]){0, 1, 4, 9, 16, 25, 36, 49},
    8
  );
  seqs.add_sequence(
    "Powers of two",
    (int[8]){1, 2, 4, 8, 16, 32, 64, 128},
    8
  );

  // This should print out
  //    Squares of non-negative integers
  seqs.match( (int[3]){ 4, 9, 16}, 3 );
  // This should print out
  //    Squares of non-negative integers
  //    Powers of two
  seqs.match( (int[1]){ 16 }, 1 );

  return 0;
}

Sequences::Sequences():
p_list_head{ nullptr } {
  // Empty constructor
}

void Sequences::add_sequence(
  std::string name,
  int         array[],
  std::size_t capacity
) {
  
}

void Sequences::match(
  int         array[],
  std::size_t capacity
) const {
  // Your implementation here
}
