#include "person.h"
// double weight {};
int Person::person_count = 8;

// Constructor
Person::Person(const std::string &names_param, int age_param)
    : full_name{names_param}, age{age_param}{
        ++person_count;
    }

double add(double a, double b) {
    return a + b;
}

struct Point
{
    double m_x;
    double m_y;
};

