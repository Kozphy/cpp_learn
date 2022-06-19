#include <iostream>

int main(){
    bool red_light {true};
    bool green_light {false};
    

    std:: cout << "sizeof(bool) : " << sizeof(bool) << std::endl;

    // Printing out a bool
    // 1 -->> true
    // 0 -->> false
    std::cout << std::endl;
    std::cout << "red_light : " << red_light << std::endl;
    std::cout << "green_light : " << green_light << std::endl;
    
    // Print out true and false
    std::cout << std::endl;
    std::cout << std::boolalpha; // Forces the output format to true/false
    std::cout << "red_light : " << red_light << std::endl;
    std::cout << "green_light : " << green_light << std::endl;
    return 0;
}
