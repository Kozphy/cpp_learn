#include <iostream>
#include <cstring>

int main() {
    // std::strlen: length of a string
    const char message1[]{"The sky is blue."};
    // Array decays into pointer when we use const char*
    const char  *message2{"The sky is blue."};
    std::cout << "message1: " << message1 << std::endl;

    // strlen ignores null character
    std::cout << "strlen(message1): " << std::strlen(message1) << std::endl;

    // Includes the null character
    std::cout << "sizeof(message1): " << sizeof(message1) << std::endl;

    // strlen still work with decayed arrays
    std::cout << "strlen(message2): " << std::strlen(message2) << std::endl;

    // Prints size of pointer
    std::cout << "sizeof(message2: " << sizeof(message2) << std::endl;

    // std::strcmp : comparing strings
    std::cout << std::endl;
    // std::strcmp - signature: int strcmp (const char *lhs, const char *rhs );
    // Returns negative value if lhs appears before rhs in lexicographical order,
    // Zero if lhs and rhs compare equal.
    // and Positive value if lhs appears after rhs in lexicographical order.
    std::cout << "std::strcmp: " << std::endl;
    const char *string_data1 {"Alabama"};
    const char *string_data2{"Blabama"};

    //Print out the comparison
    std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
    << std::strcmp(string_data1, string_data2) << std::endl;

    string_data1 = "Alabama";
    string_data2 = "Alabamb";

    //Print out the comparison
    std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
    << std::strcmp(string_data1,string_data2) << std::endl;
    string_data1 = "Alacama";
    string_data2 = "Alabama";

    return 0;
}