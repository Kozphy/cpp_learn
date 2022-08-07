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

void Dog::set_dog_name(string_view name_param)
{
    dog_name = name_param;
    // this -> dog_name = name_param;
}

// Release memory
Dog::~Dog(){
    delete dog_age;
    cout << "Dog destructor called for: " << dog_name << " at " << this << endl;
}


