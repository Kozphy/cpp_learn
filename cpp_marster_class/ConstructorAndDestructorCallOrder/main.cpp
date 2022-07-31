#include <iostream>
#include <string>
#include "cylinder.h"
#include "dog.h"

using namespace std;



int main() {
    Dog dog1("Fluffy1", "Shepherd", 2); // Constructor
    dog1.print_info();
    dog1.set_dog_name("Brob");
    dog1.print_info();

    Dog dog2("Kork2", "Shepherd", 2); 
    Dog dog3("Polyi3", "Shepherd", 2);
    Dog dog4("Adina4", "Shepherd", 2); 

    cout << "Done!" << endl;
    // Destructor


    return 0;
}