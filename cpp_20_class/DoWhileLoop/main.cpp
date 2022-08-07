#include <iostream>

int main() {
    const unsigned int COUNT {10};
    unsigned int i {1};

    do {
        std::cout << "[" << i << "] : C++" << std::endl;
        ++i;
    }while(i < COUNT);  // Test

    return 0;
}