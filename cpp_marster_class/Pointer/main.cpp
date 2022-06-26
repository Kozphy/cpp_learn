#include <iostream>

int main() {
    // Declaring Pointers
    int * p_number {}; //can only store an address of a variable of type int

    double * p_fractional_number{};

    // Explicitely init to nullptr
    int * p_number1{nullptr};
    int * p_fractional_number1 {nullptr};

    // All pointer variables have the same size
    std::cout << "Size of number pointer : " << sizeof(p_number) << ", size of int : " << sizeof(int) << std::endl;
    std::cout << "Size of fractional_number pointer : " << sizeof(p_fractional_number) << ", size of double : " << sizeof(double) << std::endl;
    std::cout << "Size of number1 pointer : " << sizeof(p_number1) << ", size of int : " << sizeof(int) << std::endl;
    std::cout << "Size of fractional_number1 pointer : " << sizeof(p_fractional_number1) << ", size of double : " << sizeof(double) << std::endl;

    std::cout << std::endl;
    // Assigning data to pointer variables
    int int_var{43};
    int *p_int{&int_var}; // The address of operator (&);

    std::cout << "Int var :"  << int_var << std::endl;
    std::cout << "p_int (Address in memory) : " << p_int << std::endl;

    // You can also change the address stored in a pointer any time
    int int_var1{65};

    int_var1 = 126;

    p_int = &int_var1; // Assign a different address to the pointer
    std::cout << "p_int (with different address) : "  << p_int << std::endl;

    return 0;
}

