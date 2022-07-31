#include <iostream>
#include <string>
#include "cylinder.h"
#include "dog.h"

using namespace std;



int main() {
    Dog dog1("Fluffy1", "Shepherd", 2); // Constructor
    dog1.print_info();
    // dog1.set_dog_name("Brob");
    // dog1.print_info();
    
    // Chained calls using pointers
    // cout << endl;
    // cout << "Chained calls using pointers" << endl;
    // Dog *p_dog1 = new Dog("Millow", "Shephardl", 3);
    // p_dog1 -> print_info();
    // cout << endl;
    // cout << "after chained call: " << endl;

    // // Pointer version
    // p_dog1 -> set_name("Mirrow") -> set_dog_breed("Siwk") -> set_dog_age(10);
    // p_dog1 -> print_info();
    // delete p_dog1;

    // Chained calls using references
    cout << endl;
    cout << "chained calls using refersence" << endl;
    Dog *p_dog2 = new Dog("Milou", "shepherd", 10);
    p_dog2 -> print_info();
    cout << endl;
    cout << "after chained call: " << endl;

    // Reference version
    p_dog2 -> set_name("Diow").set_dog_breed("Wire Fox Terrier").set_dog_age(20);
    p_dog2 -> print_info();
    delete p_dog2;

    cout << "Done!" << endl;
    // Destructor


    return 0;
}