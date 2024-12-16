#include <iostream>
#include <set>

// Function declarations
int main();

// Function definitions
int main() {
  // A set containing 'int'
  std::set<int> data{};

  // 100 random integers
  int random[100]{
    26,	61,	15,	 2,	86,
     1,	32,	37,	91,	73,
    97,	 5,	 9,	20,	56,
    70,	89,	18,	99,	24,
    64,	79,	77,	37,	50,
    76,	65,	49,	 7,	94,
     4,	 1,	86,	 8,	60,
    19,	99,	63,	38,	94,
    76,	49,	62,	37,	85,
    28,	 4,	21,	 8,	39,
    61,	 6,	79,	 6,	 1,
    91,	84,	44,	39,	39,
    68,	28,	86,	92,	86,
     3,	56,	64,	14,	42,
    32,	59,	38,	50,	28,
    92,	52,	84,	64,	90,
    82,	44,	78,	39,	24,
     0,	94,	46,	49,	75,
    32,	19,	 3,	46,	71,
     0,	59,	29,	47,	16
  };

  for ( std::size_t k{0}; k < 100; ++k ) {
    data.insert( random[k] );
  }

  std::cout << "The size of 'data' is "
            << data.size() << std::endl;

  int delete_count{0};

  for ( int k{3}; k < 100; k += 13 ) {
    std::cout << "Erasing " << k << " which has count "
              << data.count( k ) << std::endl;
    delete_count += data.erase( k );
  }

  std::cout << delete_count << " entries were deleted"
            << std::endl;

  std::cout << "The size of 'data' is now "
            << data.size() << std::endl;

  for ( std::set<int>::iterator itr{ data.begin() };
        itr != data.end(); ++itr ) {
    std::cout << *itr << " ";
  }

  return 0;
}