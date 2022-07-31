#ifndef DOG_H
#define DOG_H

#include <string>
using namespace std;

class Dog
{
    public:
        Dog();
        Dog(string name_param, string breed_param, int age_param);
        ~Dog(); // Destructor declared
        // Can also declare and implement in here : syntax commented out below: 
        /*
        ~Dog()
        {
            delete dog_age;
            cout << "Dog destructor called for " << dog_name << endl;
        }
        */
       void print_info();
    //    void set_name(string_view name_param);
    //    Dog *set_name(const string &dog_name);
    //    Dog *set_dog_breed(const string &breed);
    //    Dog *set_dog_age(int age);
       Dog &set_name(const string &dog_name);
       Dog &set_dog_breed(const string &breed);
       Dog &set_dog_age(int age);
   private:
    string dog_name;
    string dog_breed;
    int* dog_age;
};

#endif