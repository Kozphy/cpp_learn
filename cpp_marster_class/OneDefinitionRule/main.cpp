#include <iostream>
#include "person.h"
// Variable: Declaration and definition
double weight {};
double add(double a, double b);

struct Point
{
    double m_x{};
    double m_y{};
};

int main() {
    std::cout << weight << std::endl;
    double result = add(10,20);
    std::cout << "result: " << result << std::endl;
    
    Point p1;
    std::cout << "p1.x: " << p1.m_x << ", p1.y: " << p1.m_y << std::endl;

    Person p2("John Snow", 35);
    p2.print_info();
    return 0;
}

// double add(double a, double b) {
//     return a + b;
// }

