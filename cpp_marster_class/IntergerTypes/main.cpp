#include <iostream>

int main(){
    // variable braced initialization
    // Variable may contain random garbage value . WARNING
    int elephant_count;

    int lion_count{}; // Initializes to zero

    int dog_count{10}; //Initializes to 10

    int cat_count{15};

    // Can use expression as initializer
    int domesticated_animals {dog_count + cat_count};
    std::cout << domesticated_animals << std::endl;

    // Won't compile, the expression in the braces uses undeclared variables
    // int bad_initialization {doesnt_exist1 + doesnt_exist2};

    // 2.9 is of type doulbe, with a wider range than int.ERROR OR WARNING.
    // int narrowing_conversion {2.9};

    // functional variabe init
    int apple_count(5);

    int orange_count(10);

    int fruit_count (apple_count + orange_count);
    std::cout << fruit_count << std::endl;
    // int bad_initialization (doesnt_exist3 + doesnt_exist4);

    // info lost. less safe than braced initializers
    int narrowing_conversion_functional(2.9);
    std::cout << "narrowing_conversion_functional" << narrowing_conversion_functional << std::endl;
    return 0;
}