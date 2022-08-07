#include <iostream>

int main() {
    int max{};

    int a{35};
    int b{20};

    max = (a > b) ? a : b;

    // Types must match or be convertible
    // max = (a > b) ? a : "b"; // Error
    std::cout << "max : " << max << std::endl;

    std::cout << std::endl;
    std::cout << "speed" << std::endl;

    // Ternary Initiallization
    bool fast = false;
    int speed { fast ? 300 : 150};
    std::cout << "The speed is : " << speed << std::endl;

    return 0;
}