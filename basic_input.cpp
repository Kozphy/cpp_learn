#include <iostream>
#include <string>

int main()
{
    using std::cout;
    typedef std::string string_std;
    string_std m("hello");
    string_std m2("world");
    cout << m << m2 << std::endl;
    return 0;
}