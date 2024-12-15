#include <iostream>

// The price for a microcontroller is $12.75 if the
// customer purchases fewer than 10.
// If the customer purchases between 10 and 99,
//    the price is $10.15.
// If the customer purchases 100 or more,
//    the price is $9.75
//
// Write a program to query how many microcontrollers
// are being sold and calculate a cost. You will 
// do this by calculating the cost in cents, not 
// dollars, but you will then print out the 
// result in dollars and cents.
//
// If the amount sold is negative, just return 0.

// Function declarations
int main();

// Function definitions
int main() {

    unsigned int n{};
    unsigned int price{};
    unsigned int dollars{}, cents{};

    std::cout << "how many microcontrollers are bought? " << std::endl;
    std::cin >> n;

    if (n < 10) {
        price = 1275*n;
    } else if (n >= 10 && n < 100) {
        price = 1015*n;
    } else {
        price = 975*n;
    }

    dollars = price/100;
    
    std::cout << "the price is $" << dollars << ".";

    //add a zero if there are 0 cents
    cents = price %100;
    if (cents == 0) {
        std::cout << "0";
    }

    std::cout << cents << std::endl;

  return 0;
}
 










































































// Here is one solution:
/*
int main() {
  int amount_sold{};
  std::cout << "Enter the number of microcontrollers sold: ";
  std::cin  >> amount_sold;

  if ( amount_sold < 0 ) {
    return 0;
  }
  
  int cost{};

  if ( amount_sold < 10 ) {
    cost = 1275*amount_sold;
  } else if ( amount_sold < 100 ) {
    cost = 1015*amount_sold;
  } else {
    cost =  975*amount_sold;
  }

  std::cout << "The cost is " << (cost/100) << ".";

  cost %= 100;

  if ( cost == 0 ) {
    std::cout << "00" << std::endl;
  } else if ( cost < 10 ) {
    std::cout << "0" << cost << std::endl;
  } else {
    std::cout << cost << std::endl;
  }

  return 0;
}
*/