#include <iostream>
#include <string>
#include "cylinder.h"
#include "dog.h"

using namespace std;



int main() {
    Dog dog1("Fluffy", "Shepherd", 2); // Constructor
    dog1.print_info();
    dog1.set_dog_name("Brob");
    dog1.print_info();

    cout << "Done!" << endl;
    // Destructor


    return 0;
}