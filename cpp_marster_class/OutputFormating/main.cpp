#include <iostream>
#include <iomanip>

int main() {
    // std:: flush : flushes the output buffer to its final destination.
    std::cout << "This is a nice message..." << std::endl << std::flush;
    // After this std::flush, we're sure that at this line, the message has been sent 
    // to the stream. This may be important in some applications.

    std::cout << std::endl;

    int col_width{14};
    
    std::cout << std::setw(col_width) << "Lastname" << std::setw(col_width) << "Firstname" << std::setw(col_width) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel" << std::setw(col_width) << "Carr"<< std::setw(col_width) << "20" << std::endl;

    // right justified
    std::cout << std::endl;
    std::cout << "Right justified table(default) : " << std::endl;

    int col_width2 = 20;
    
    std::cout << std::right;
    std::cout << std::setw(col_width2) << "Lastname" << std::setw(col_width2) << "Firstname" << std::setw(col_width2) << "Age" << std::endl;
    std::cout << std::setw(col_width2) << "Daniel" << std::setw(col_width2) << "Carr" << std::setw(col_width2) << "20" << std::endl;

    // left justified
    std::cout << std::endl;
    std::cout << "Left justified table : " << std::endl;

    std::cout << std::left;
    std::cout << std::setw(col_width2) << "Lastname" << std::setw(col_width2) << "Firstname" << std::setw(col_width2) << "Age" << std::endl;
    std::cout << std::setw(col_width2) << "Daniel" << std::setw(col_width2) << "Carr" << std::setw(col_width2) << "20" << std::endl;
    
    
    return 0;

}