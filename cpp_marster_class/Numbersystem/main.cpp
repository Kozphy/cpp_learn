#include <iostream>

int main(){
    int number = 15; // Decimal
    int number2 = 017; //Octal.
    int number3 = 0x0f; //Hexadecimal
    int number4 = 0b00001111; // Binary - C++14
    int truck_count = 20;
    std::cout << "number1 : " << number << std::endl;
    std::cout << "number2 : " << number2 << std::endl;
    std::cout << "number3 : " << number3 << std::endl;
    std::cout << "number4 : " << number4 << std::endl;
    std::cout << "sizeof int : " << sizeof(int) << std::endl;
    std::cout << "sizeof truck_count : " << sizeof(truck_count) << std::endl;
    return 0 ;
}