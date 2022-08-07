#include <iostream>
#include <string>

int main() {
    // Declaring std::string variables
    std::string full_name; // Empty string
    std::string planet {"Earth. Where the sky is blue."}; // init with string literal.
    std::string prefered_planet{planet}; // init with other existing string
    std::string message{"Hello there", 5}; // init with part of a string literal. Contains hello.

    std::string weird_messsage(4, 'e'); // init with multiple copies of a char contains eeee
    std::string greeting{"Hello world"};
    std::string saying_hello{greeting, 6, 5}; // init with part of an existing std::string
                                            // starting at index 6, taking 5 characters.
                                            // Will contain world.
    std::cout << "full_name: " << full_name << std::endl;
    std::cout << "planet: " << planet << std::endl;
    std::cout << "prefered_planet: " << prefered_planet << std::endl;
    std::cout << "message: " << message << std::endl;
    std::cout << "weird_message: " << weird_messsage << std::endl;
    std::cout << "greeting: " << greeting << std::endl;
    std::cout << "saying_hello: " << saying_hello << std::endl;

    return 0;
}