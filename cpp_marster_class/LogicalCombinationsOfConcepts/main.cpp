#include <iostream>
#include <concepts>

// Combining concepts
template <typename T>
concept TinyType = requires(T t){
    sizeof(T) <= 4; // Simple requirement
    requires sizeof(T) <=4; // Newsted requirement
};

template <typename T>
// requires std::integral<T> || std::floating_point<T>
requires std::integral<T> && TinyType<T>
T add(T a, T b) {
    return a + b;
}

// T func(T t) requires std::integral<T> && TinyType<T>
// T func(T t) requires std::integral<T> &&
// requires (T t) {
//     sizeof(T) <=4;
//     requires sizeof(T) <= 4;
// };


int main() {
    int x {4};
    int y {6};
    std::string a{"6"};
    std::string b{"4"};
    auto result = add(x, y);
    std::cout << "result: " << result << std::endl;
    std::cout << "sizeof(result): " << sizeof(result) << std::endl;
    return 0;
}