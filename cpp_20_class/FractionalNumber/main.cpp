#include <iostream>
#include <iomanip>

int main(){
    float number1 {1.12345678901234567890f}; // Precision: 7
    double number2 {1.12345678901234567890}; // Precision: 15
    long double number3 {1.12345678901234567890L};
    std::cout << std::setprecision(20); // Control the precision from std::cout
    std::cout << "number1: " << number1 << " sizeof(number1): " << sizeof(number1) << std::endl;
    std::cout << "number2: " << number2 << " sizeof(number2): " << sizeof(number2) << std::endl;
    std::cout << "number3: " << number3 << " sizeof(number3): " << sizeof(number3) << std::endl;

    // Float problems : The precision is usually too limited 
    // for a lot of applications
    float number4 {192400023.0f}; // narrowing conversion
    std::cout << "number4 : " << number4 << std::endl;

    std::cout << "----------------" << std::endl;

    double number5 {192400023};
    double number6 {1.92400023e8}; // multiplying by 10^8
    double number7 {1.924e8};
    double number8 {0.00000000003498};
    double number9 {3.498e-11}; // multiply by 10^-11
    std::cout << "number5 is : " << number5 << std::endl;
    std::cout << "number6 is : " << number6 << std::endl;
    std::cout << "number7 is : " << number7 << std::endl;
    std::cout << "number8 is : " << number8 << std::endl;
    std::cout << "number9 is : " << number9 << std::endl;

    std::cout << "----------------" << std::endl;
    
    double number10 {5.6};
    double number11{}; // init to 0
    double number12{};

    // Infinity
    double result { number10 / number11};

    std::cout << number10 << "/" << number11 << " yields " << result << std::endl;
    std::cout << result << " + " << number10 << " yields " << result + number10 << std::endl;

    //NaN
    result = number11 / number12;
    std::cout << number11 << "/" << number12 << " yields " << result << std::endl;
    return 0;
}