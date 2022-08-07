#include <iostream>

int main() {
    // Declaring Pointers (not recommend point to null)
    int * p_number {}; //can only store an address of a variable of type int

    double * p_fractional_number{};

    // Explicitely init to nullptr (not recommend point to null)
    int * p_number1{nullptr};
    int * p_fractional_number1 {nullptr};

    // All pointer variables have the same size
    std::cout << "Size of number pointer : " << sizeof(p_number) << ", size of int : " << sizeof(int) << std::endl;
    std::cout << "Size of fractional_number pointer : " << sizeof(p_fractional_number) << ", size of double : " << sizeof(double) << std::endl;
    std::cout << "Size of number1 pointer : " << sizeof(p_number1) << ", size of int : " << sizeof(int) << std::endl;
    std::cout << "Size of fractional_number1 pointer : " << sizeof(p_fractional_number1) << ", size of double : " << sizeof(double) << std::endl;

    std::cout << std::endl;
    // Assigning data to pointer variables
    int int_var{43};
    int *p_int{&int_var}; // The address of operator (&);

    std::cout << "Int var :"  << int_var << std::endl;
    std::cout << "p_int (Address in memory) : " << p_int << std::endl;

    // You can also change the address stored in a pointer any time
    int int_var1{65};

    int_var1 = 126;

    p_int = &int_var1; // Assign a different address to the pointer
    std::cout << "p_int (with different address) : "  << p_int << std::endl;
    
    // Pointer only stores the type for which it was declared
    int  *p_int1(nullptr);
    double double_var{33};

    // p_int = &double_var; // Compile Error

    // Declaring Pointer to Char
		std::cout << std::endl;
    char  *p_char_var {nullptr};
    char	char_var {'A'};

    p_char_var = &char_var;

    std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;

    char char_var1 {'C'};
    p_char_var = &char_var1;
    std::cout << "The value stored in p_char_var is : " << *p_char_var << std::endl;

    // Init char pointer with string literal
    std::cout << std::endl;
    /*
        Pointer to char can also do something spcial
        You can init with a string literal : C-String
        The compiler will convert "Hello World!" string to a array of const char which will be pointed first character by p_message
        which point to that array is not const char pointer.
    */
    char	*p_message {"Hello World!"};

    std::cout << "The message is : " << p_message << std::endl;
    std::cout << "The value stored at p_message is : " << *p_message << std::endl;

    // The string literal is made up of const char. Trying to modify any of them will result in a disaster!
    // *p_message = 'B';
    // std::cout << "The message is (after modifcation of first char to B) : " << p_message << std::endl;
    
    // init char pointer of array with string literal
    char message2[] {"Hello there"};
    message2[0] = 'T';
    std::cout << "message2 : " << message2 << std::endl;

    // How we've used pointers so far
    int number2 {22};
    int  *p_number2 = &number2;

    std::cout << std::endl;
    std::cout << "Declaring pointer and assigning address : " << std::endl;
    std::cout << "number : " << number2 << std::endl;
    std::cout << "p_number : " << p_number2 << std::endl;
    std::cout << "&number : " << &number2 << std::endl;
    std::cout << "*p_number : " << *p_number2 << std::endl;

    int  *p_number3; // Uninit pointer, contains junk address (not recommend)
    int number3{12};
    p_number3 = &number3; // Make it point to a valid address
    std::cout << std::endl;
    std::cout << "Unini pointer : " << std::endl;
    std::cout << "*p_number1 : " << *p_number3 << std::endl;


    std::cout << std::endl;
    // Allocate dynamic memory through 'new'
    /*
        Init the pointer with dynamic memory. Dynamically allocate
        memory at run time and make a pointer point to it
    */

    int *p_number4{nullptr};
    p_number4 = new int; /*
                            Dynamically allocate space for single int on the heap
                            This memory belongs to our program from now on. The system
                            can't use it for anything else, until we return it.
                            After this line executes, we will have valid memory location
                            allocated. The size of the allocated memory will be such that it can
                            store the type pointed to by the pointer
                        */
    *p_number4 = 77;
    std::cout << "Dynamically allocating memory : " << std::endl;
    std::cout << "*p_number4 : " << *p_number4 << std::endl;

    // releasing and resetting dynamic memory
    delete p_number4;
    p_number4 = nullptr;

    std::cout << std::endl;
    // Init with 'new' upon pointer declartion
    /*
        It is also possible to init the pointer with valid
        adress up on declaration. Not with nullptr
    */
   int *p_number5{new int}; // Memory contains junk value
   int *p_number6{new int (22)}; // use direct inti
   int *p_number7{new int { 23 }}; // use uniform init
   std::cout << "Init with valid memory address at declaration : " << std::endl;
   std::cout << "p_number5 : " << p_number5 << std::endl;
   std::cout << "*p_number5 : " << *p_number5 << std::endl; // Junk value

   std::cout << "p_number 6 : " << p_number6 << std::endl;
   std::cout << "*p_number6 : " << *p_number6 << std::endl;

   std::cout << "p_number7 : " << p_number7 << std::endl;
   std::cout << "*p_number7 : " << *p_number7 << std::endl;

   // Remember to release the memory
   delete p_number5;
   p_number5 = nullptr;

   delete p_number6;
   p_number6 = nullptr;

   delete p_number7;
   p_number7 = nullptr;

    return 0;
}

