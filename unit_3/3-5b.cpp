//problem 5: brute force searches

//#1

/* Write a function that takes a number of arguments. The first is a positive real number that
gives the volume of a knapsack. The second argument is an array of positive real numbers
representing the volume of a number of items that could be put into the knapsack. Your
goal is to determine the maximum number of objects that can be placed into the knapsack
without exceeding the volume, and to then print the indices associated with each entry
that would be placed into the knapsack. */

#include <iostream>
#include <cassert>

int main();
void container(double volume, double objects[], std::size_t capacity);

int main() {

    double objects[6]{3.6, 7.9, 10.0, 0.1, 1.0, 3.6};
    container(8.5, objects, 6);

    return 0;
}

void container(double volume, double objects[], std::size_t capacity) {
    
    for (std::size_t k{0}; k < capacity; ++k) {
        std::size_t count{};
        double current_volume{volume};
        while (current_volume - objects[k] >= 0) {
            ++count;
            current_volume -= objects[k];
        }
        std::cout << count << " of object #" << k + 1 << " can fit in the bag." << std::endl;
    }
}