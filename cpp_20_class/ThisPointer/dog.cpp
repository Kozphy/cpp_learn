#include "dog.h"
#include <iostream>

using namespace std;

Dog::Dog(){
    dog_name = "None";
    dog_breed = "None";
    // dynamic memory allocation on heap
    dog_age = new int;
    *dog_age = 0;
}

void Dog::print_info(){
    cout << "Dog address: " << this << ", " << "dog_name is: " << dog_name << ", " <<
    "dog_breed is: " << dog_breed <<  ", " << "dog_age is: " << *dog_age << endl;
}

Dog::Dog(string name_param, string breed_param, int age_param)
{
   dog_name = name_param; 
   dog_breed = breed_param;
   dog_age = new int;
   *dog_age = age_param;
    cout << "Dog contructor called for: " << dog_name << " at " << this << endl;
}

// void Dog::set_name(string_view dog_name)
// {   
//     // Conficting name
//     // dog_name = dog_name;
//     this -> dog_name = dog_name;
// }

// Chained calls with pointers:
// Dog *Dog::set_name(const string &dog_name)
// {
//     this -> dog_name = dog_name;
//     return this; // For use in chained calls
// }

// Dog *Dog::set_dog_breed(const string &breed)
// {
//     this -> dog_breed = breed;
//     return this;
// }

// Dog *Dog::set_dog_age(const int age)
// {
//     if(this -> dog_age)
//     {
//         *(this -> dog_age) = age;
//     }
//     return this;
// }
// Chained calls with reference:
Dog &Dog::set_name(const string &dog_name)
{
    this -> dog_name = dog_name;
    return *this; // dereference
}

Dog &Dog::set_dog_breed(const string &breed)
{
    this -> dog_breed = breed;
    return *this;
}

Dog &Dog::set_dog_age(const int age)
{
    if(this -> dog_age)
    {
        *(this -> dog_age) = age;
    }
    return *this;
}
// Release memory
Dog::~Dog(){
    delete dog_age;
    cout << "Dog destructor called for: " << dog_name << " at " << this << endl;
}


