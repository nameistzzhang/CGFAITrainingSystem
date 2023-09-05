# include <iostream>
# include "./Lib/add.h"
# include "./Lib/minus.h"

int main () {
    std::cout << add(1, 2) << "\n";
    std::cout << minus(3, 2) << "\n";
    std::cout << add(5, 6) << "\n";
    std::cout << minus(8, 15) << "\n";
}