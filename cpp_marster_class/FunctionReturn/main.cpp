#include <iostream>
#include <string>

// Return from Funtion (default is by value)
int sum(int a, int b){
    int result = a + b;
    std::cout << "In: &result(int): " << &result << std::endl;
    return result;
}

// Compiler optimizations to return by reference
// Compiler will auto return by reference to avoid unnecessary copies if the size of parameter is too big.
std::string add_strings(std::string str1, std::string str2){
    std::string result = str1 + str2;
    std::cout << "In : &result(std::string) : " << &result << std::endl;
    return result;
}

int main() {
    int a {34};
    int b {16};
    int result = sum(a, b);
    std::cout << "Out: &result(int): " << &result << std::endl;
    std::cout << "sum: " << result << std::endl;
    std::cout << std::endl;

    std::string inp_string1 ("Hello");
    std::string inp_string2 {" World!"};
    std::string str_result = add_strings(inp_string1,inp_string2);
    std::cout << "Out: &result(std::string): " << &str_result << std::endl;
    std::cout << "str_result: " << str_result << std::endl;
    return 0;
}