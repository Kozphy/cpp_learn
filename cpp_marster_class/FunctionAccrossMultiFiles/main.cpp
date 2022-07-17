#include <iostream>
#include "compare.h" // Preprocessor


int main() {
    int maximum = max(134, 56);
    std::cout  << "max : " << maximum << std::endl;

    int minimum = min(134, 56);
    std::cout  << "min : " << minimum << std::endl;
    return 0;
}

