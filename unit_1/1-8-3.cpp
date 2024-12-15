#include <iostream>

// If you are a Canadian, your first objection
// may be the fact that the title uses the
// word 'kilometer' and not 'kilometre'. In the
// world of engineering, however, you must always
// consider a global audience, and you must 
// always communicate in such a way as to 
// minimize the possiblity of confusion or
// misunderstanding. While most persons born into
// a community where English is a first language,
// going between 'color' and 'colour' is trivial,
// and just annoying; however, for someone for
// whom English is a second language, it is always
// easier to use the simpler American spellings.
//
// For the record, this author always cringes when
// this author is forced to used an American 
// spelling, but uses it never-the-less.
//
// On the other hand, there are good arguments 
// supporting the fact that non-phonetic spellings
// of words is exclusionary and elitist. However,
// this is an introductory programming class, so
// we'll let you investigate this further, if you
// so choose.

// Okay, onto the problem:
//    Query the user for an integer number 
//    of meters and then round that to the
//    closest kilometer. The number of meters
//    should be non-negative (positive or 0),
//    otherwise, return 0. 
//
//    You will note that integer division 
//    always rounds down. You should round
//    to the closest kilometer with the 
//    following rule:
//       If the distance to the closest
//       kilometer is exactly 500 m, then
//       if the number of kilometers is
//       even, then use that distance;
//       otherwise, the number of kilometers
//       is odd, so round up.
// 
//    Print out the number of kilometers after
//    rounding.
//
// You may have heard the expression:
//    "Even, leave it; odd, raise it."

// Function declarations
int main();

// Function definitions
int main() {

    int meters{};

  std::cout << "enter number of meters: ";
  std::cin >> meters;

    int kilometers{meters/1000};
    //500 meters check:
    if (meters%1000 == 500) {
        //if the km are even, do nothing
        if (kilometers%2 == 0) {
            ;
        //if jm are odd, add one (round up)
        } else {
            ++kilometers;
        }
    } else if (meters%1000 > 500) {
        ++kilometers;
    }

    std::cout << "km: " << kilometers <<std::endl;

  return 0;
}
































































// Here is one solution:

/*
int main() {
  int distance_m{};
  std::cout << "Enter a distance in meters: ";
  std::cin  >> distance_m;

  if ( distance_m < 0 ) {
    return 0;
  }

  int distance_km{ distance_m/1000 };

  // Determine the remainder
  int remainder_m{ distance_m%1000 };
  
  if ( remainder_m > 500 ) {
    // If the remainder is is greater
    // than 500 m, then round up the
    // the next highest number of 
    // kilometers.
    ++distance_km;
  } else if ( remainder_m == 500 ) {
    // If the remainder is exactly 500 m,
    // then round up if the distance in 
    // km is odd, and round down if it
    // is even.
    if ( distance_km%2 == 1 ) {
      ++distance_km;
    }
  }

  std::cout << "The distance is "
            << distance_km << " km"
            << std::endl;

  return 0;
}
*/