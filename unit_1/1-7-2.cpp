#include <iostream>

// Function declarations
int main();

// Function definitions
int main() {
  // Integer division calculates the quotient and
  // remainder, and discards the remainder.
  // This can be interpreted as 'rounding' to zero.
  //  - For example, 9.0/4.0 =  2.25 so  9/4 = 2
  //                -9.0/4.0 = -2.25 so -9/4 = -2
  //
  // Thus, if |m| < |n|, then m/n = 0

  std::cout << "Integer division" << std::endl;
  std::cout << "-9/4 = " << (-9/4) << std::endl;
  std::cout << "-8/4 = " << (-8/4) << std::endl;
  std::cout << "-7/4 = " << (-7/4) << std::endl;
  std::cout << "-6/4 = " << (-6/4) << std::endl;
  std::cout << "-5/4 = " << (-5/4) << std::endl;
  std::cout << "-4/4 = " << (-4/4) << std::endl;
  std::cout << "-3/4 = " << (-3/4) << std::endl;
  std::cout << "-2/4 = " << (-2/4) << std::endl;
  std::cout << "-1/4 = " << (-1/4) << std::endl;
  std::cout << " 0/4 = " << ( 0/4) << std::endl;
  std::cout << " 1/4 = " << ( 1/4) << std::endl;
  std::cout << " 2/4 = " << ( 2/4) << std::endl;
  std::cout << " 3/4 = " << ( 3/4) << std::endl;
  std::cout << " 4/4 = " << ( 4/4) << std::endl;
  std::cout << " 5/4 = " << ( 5/4) << std::endl;
  std::cout << " 6/4 = " << ( 6/4) << std::endl;
  std::cout << " 7/4 = " << ( 7/4) << std::endl;
  std::cout << " 8/4 = " << ( 8/4) << std::endl;
  std::cout << " 9/4 = " << ( 9/4) << std::endl;
  std::cout << std::endl;


  // For positive integers 'm' and 'n', m%n calculates
  // the remainder when performing long division.
  //       m           m%n
  // Thus --- = m/n + -----.
  //       n            n
  //
  // For example,
  //      17              17%5         2
  //     ---- = (17/5) + ------ = 3 + ---
  //       5                5          5
  //
  //  Alternatively, m = (m/n)*n + m%n, so
  //
  //     17 = (17/5)*5 + 2

  std::cout << "n = (n/5)*5 + (n%5)" << std::endl;
  std::cout << "14 = " << (14/5) << "*5 + " << (14%5)
            << " = " << ((14/5)*5 + (14%5)) << std::endl;
  std::cout << "15 = " << (15/5) << "*5 + " << (15%5)
            << " = " << ((15/5)*5 + (15%5)) << std::endl;
  std::cout << "16 = " << (16/5) << "*5 + " << (16%5)
            << " = " << ((16/5)*5 + (16%5)) << std::endl;
  std::cout << "17 = " << (17/5) << "*5 + " << (17%5)
            << " = " << ((17/5)*5 + (17%5)) << std::endl;
  std::cout << "18 = " << (18/5) << "*5 + " << (18%5)
            << " = " << ((18/5)*5 + (18%5)) << std::endl;
  std::cout << "19 = " << (19/5) << "*5 + " << (19%5)
            << " = " << ((19/5)*5 + (19%5)) << std::endl;
  std::cout << "20 = " << (20/5) << "*5 + " << (20%5)
            << " = " << ((20/5)*5 + (20%5)) << std::endl;
  std::cout << "21 = " << (21/5) << "*5 + " << (21%5)
            << " = " << ((21/5)*5 + (21%5)) << std::endl;
  std::cout << std::endl;

  std::cout << "For this to hold for negative 'n',"
            <<std::endl;
  std::cout << "  temainder must be zero or negative"
            << std::endl;

  std::cout << "-n = (-n/5)*5 + (-n%5)" << std::endl;
  std::cout << "-14 = " << (-14/5) << "*5 + " << (-14%5)
            << " = " << ((-14/5)*5 + (-14%5)) << std::endl;
  std::cout << "-15 = " << (-15/5) << "*5 + " << (-15%5)
            << " = " << ((-15/5)*5 + (-15%5)) << std::endl;
  std::cout << "-16 = " << (-16/5) << "*5 + " << (-16%5)
            << " = " << ((-16/5)*5 + (-16%5)) << std::endl;
  std::cout << "-17 = " << (-17/5) << "*5 + " << (-17%5)
            << " = " << ((-17/5)*5 + (-17%5)) << std::endl;
  std::cout << "-18 = " << (-18/5) << "*5 + " << (-18%5)
            << " = " << ((-18/5)*5 + (-18%5)) << std::endl;
  std::cout << "-19 = " << (-19/5) << "*5 + " << (-19%5)
            << " = " << ((-19/5)*5 + (-19%5)) << std::endl;
  std::cout << "-20 = " << (-20/5) << "*5 + " << (-20%5)
            << " = " << ((-20/5)*5 + (-20%5)) << std::endl;
  std::cout << "-21 = " << (-21/5) << "*5 + " << (-21%5)
            << " = " << ((-21/5)*5 + (-21%5)) << std::endl;
  std::cout << std::endl;

  // Here we show that the integer remainder m%n for
  // positive integers is between 0 and n - 1,
  // while for m negative, the reaminder is between
  // -(n - 1) = 1 - n and 0.
  std::cout << "Integer remainder" << std::endl;
  std::cout << "-9%4 = " << (-9%4) << std::endl;
  std::cout << "-8%4 = " << (-8%4) << std::endl;
  std::cout << "-7%4 = " << (-7%4) << std::endl;
  std::cout << "-6%4 = " << (-6%4) << std::endl;
  std::cout << "-5%4 = " << (-5%4) << std::endl;
  std::cout << "-4%4 = " << (-4%4) << std::endl;
  std::cout << "-3%4 = " << (-3%4) << std::endl;
  std::cout << "-2%4 = " << (-2%4) << std::endl;
  std::cout << "-1%4 = " << (-1%4) << std::endl;
  std::cout << " 0%4 = " << ( 0%4) << std::endl;
  std::cout << " 1%4 = " << ( 1%4) << std::endl;
  std::cout << " 2%4 = " << ( 2%4) << std::endl;
  std::cout << " 3%4 = " << ( 3%4) << std::endl;
  std::cout << " 4%4 = " << ( 4%4) << std::endl;
  std::cout << " 5%4 = " << ( 5%4) << std::endl;
  std::cout << " 6%4 = " << ( 6%4) << std::endl;
  std::cout << " 7%4 = " << ( 7%4) << std::endl;
  std::cout << " 8%4 = " << ( 8%4) << std::endl;
  std::cout << " 9%4 = " << ( 9%4) << std::endl;
  std::cout << std::endl;

  return 0;
}