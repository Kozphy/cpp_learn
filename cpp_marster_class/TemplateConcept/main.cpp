#include <iostream>

// An alternative to static asserts and type traits
template <typename T>
void print_number(T n){
    static_assert(std::is_integral<T>::value, "Must pass in an integral aurgument");
    std::cout << "n : " << n << std::endl;
}

// Syntax1
template <typename T>
requires std::integral<T>
T add(T a, T b){
    return a + b;
}

// Syntax1 using type traits
template <typename T>
requires std::is_integral_v<T> // Using a type trait
T add2(T a, T b) {
    return a + b;
}

// Syntax2
template <std::integral T>
T add3 (T a, T b){
    return a + b;
}

// Syntax3
auto add4 (std::integral auto a, std::integral auto b){
    return a + b;
}

// Syntax4
template <typename T>
T add5(T a, T b) requires std::integral<T>{
    return a + b;
}

int main() {
    char a_0{10} ;
    char a_1{20};

    auto result_a = add(a_0, a_1);
    std::cout << "result_a: " << static_cast<int>(result_a) << std::endl;

    int b_0{11};
    int b_1{5};
    auto result_b = add(b_0,b_1);
    std::cout << "result_b: " << result_b << std::endl;

    double c_0 {11.1};
    double c_1 {1.9};
    // auto result_c = add(c_0, c_1); // Error std::integral concept not satisfied.
    return 0;
}