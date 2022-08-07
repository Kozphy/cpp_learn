#include <iostream>

int main() {
    // Declare and set lambda function
    auto func = [](){
        std::cout << "lambda"<< std::endl;
    };
    func();

    // directly call
    [](){
        std::cout<< "lambda directly call"<< std::endl;
    }();

    // lambda takes parameters
    [](double a, double b){
        std::cout << "a + b: "<< (a + b)<< std::endl;
    }(12.1, 5.7);

    // lambda function that return something
    auto result = [](double a, double b){
        return (a + b);
    }(12.1, 5.7);
    std::cout << "result: " << result << std::endl;

   // Specify return type explicitly 
   auto result1 = [](double a, double b) -> double {
    return (a + b);
   }(12.1, 5.7);
   std::cout << "result: " << result << std::endl;

    // Capture lists
    double a{10};
    double b{20};
    auto funcs = [a,b](){
        std::cout << "a + b: " << a + b << std::endl;
    };
    funcs();

    // Capture by value: what we have in lambda function is a copy
    int c{42};

    auto func2 = [c](){
        std::cout << "Inner value: " << c << std::endl;
    };
    for(size_t i{}; i < 5; ++i){
        std::cout << "Outer value: "<< c<< std::endl;
        func2();
        ++c;
    }

    // Capturing by reference: Working on the original outside value
    std::cout << std::endl;
    int c1{42};

    auto func3 = [&c1](){
        std::cout << "Inner value: " << c1 << std::endl;
    };

    for(size_t i{}; i< 5; ++i){
        std::cout << "Outer value: " << c1<< std::endl;
        func3();
        ++c1;
    }

    // Captureing everything by value
    std::cout << std::endl;
    int c2{42};
    auto func4 = [=](){
        std::cout << "Inner value: " << c2 << std::endl;
    };
    for(size_t i{}; i<5; ++i){
        std::cout << "Outer value: " << c2 << std::endl;
        func4();
        ++c2;
    }

    // Captureing everything by reference
    std::cout << std::endl;
    int c3{42};
    auto func5 = [&](){
        std::cout << "Inner value: " << c3 << std::endl;
    };
    for(size_t i{}; i< 5; ++i){
        std::cout << "Outer value: " << c3 << std::endl;
        func5();
        ++c3;
    }
    return 0;
}