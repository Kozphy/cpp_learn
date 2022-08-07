#include <iostream>

int main()
{
    // One byte in memory : 2^8 = 256 diff values (0~255)
    std::cout << "sizeof(char) is " << sizeof(char) << std::endl;
    std::cout << std::endl;

    char value = 65; // ASCII character code for 'A'
    std::cout << "value : " << value << std::endl; // A
    std::cout << "value(int) : " << static_cast<int>(value) << std::endl; // 65
    return 0;
}
