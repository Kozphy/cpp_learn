#include <iostream>

int main() {
    // Declaring and using references
    int int_value{45};
    double double_value{33.65};

    int& reference_to_int_value_1{int_value}; // Assign throught init
    int& reference_to_int_value_2 = int_value; //Assign throught assignment
    double& reference_to_double_value_1 {double_value};

    // You have to declare and init in one statement
    // int& some_reference; // Error

    std::cout << "int_value: " << int_value << std::endl;
    std::cout << "double_value: " << double_value << std::endl;
    std::cout << "reference_to_int_value_1: " << reference_to_int_value_1 << std::endl;
    std::cout << "reference_to_int_value_2: " << reference_to_int_value_2 << std::endl;
    std::cout << "reference_to_double_value_1: " << reference_to_double_value_1 << std::endl;
    std::cout << "&int_value: " << &int_value << std::endl;
    std::cout << "&double_value: " << &double_value << std::endl;
    std::cout << "&reference_to_int_value_1: " << &reference_to_int_value_1 << std::endl;
    std::cout << "&reference_to_int_value_2: " << &reference_to_int_value_2 << std::endl;
    std::cout << "&reference_to_double_value_1: " << &reference_to_double_value_1 << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(int&): " << sizeof(int&) << std::endl;
    std::cout << "sizeof(reference_to_int_value_1): " << sizeof(reference_to_int_value_1) << std::endl;

    // Modify data directly: changes reflect even in references
    std::cout << std::endl;
    std::cout << "Modifying data directly: " << std::endl;
    double_value = 9.99;

    // Print out after modifiecation of double_value
    std::cout << "int_value: " << int_value << std::endl;
    std::cout << "double_value: " << double_value << std::endl;
    std::cout << "reference_to_int_value_1: " << reference_to_int_value_1 << std::endl;
    std::cout << "reference_to_int_value_2: " << reference_to_int_value_2 << std::endl;
    std::cout << "reference_to_double_value_1: " << reference_to_double_value_1 << std::endl;
    std::cout << "&int_value: " << &int_value << std::endl;
    std::cout << "&double_value: " << &double_value << std::endl;
    std::cout << "&reference_to_int_value_1: " << &reference_to_int_value_1 << std::endl;
    std::cout << "&reference_to_int_value_2: " << &reference_to_int_value_2 << std::endl;
    std::cout << "&reference_to_double_value_1: " << &reference_to_double_value_1 << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(int&): " << sizeof(int&) << std::endl;
    std::cout << "sizeof(reference_to_int_value_1): " << sizeof(reference_to_int_value_1) << std::endl;
    
    // Declaration pointer and reference
    std::cout << std::endl;
    double double_value1 {12.34};

    double &ref_double_value1{double_value1};

    double  *p_double_value1{&double_value1};

    std::cout << "double_value1: " << double_value1 << std::endl;
    std::cout << "ref_double_value1: " << ref_double_value1 << std::endl;
    std::cout << "p_double_value1: " << p_double_value1 << std::endl;
    std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;

    // Writing pointers and reference 
    std::cout << std::endl;
    std::cout << "writing through pointer: " << std::endl;

    *p_double_value1 = 15.44;

    std::cout << "double_value1: " << double_value1 << std::endl;
    std::cout << "ref_double_value1: " << ref_double_value1 <<std::endl;
    std::cout << "p_double_value1: " << p_double_value1 << std::endl;
    std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;

    std::cout << std::endl;
    std::cout << "writing through reference: " << std::endl;

    ref_double_value1  = 18.44;

    std::cout << "double_value1: " << double_value1 << std::endl;
    std::cout << "ref_double_value1: " << ref_double_value1 <<std::endl;
    std::cout << "p_double_value1: " << p_double_value1 << std::endl;
    std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;

    // Can't make a reference refer to something else
    std:: cout << std::endl;
    double double_value2{12.34};
    double &ref_double_value2 {double_value2};
    double other_double_value{100.23};
    
    // it doesn't make ref_double_value2 reference to other_double_value
    // It merely changes the value referenced by ref_double_value2 to 100.23
    ref_double_value2 = other_double_value;
    std::cout << "double_value2: " << double_value2 << std::endl;
    std::cout << "&ref_double_value2: " << ref_double_value2 <<std::endl;
    std::cout << "other_double_value: " << other_double_value << std::endl;

    // If you change ref_double_value2 now, other_double_value stays the same
    // proving that ref_double_value2 is not referencing other_double_value
    ref_double_value2 = 333.33;
    std::cout << "double_value2: " << double_value2 << std::endl;
    std::cout << "&ref_double_value2: " << ref_double_value2 <<std::endl;
    std::cout << "other_double_value: " << other_double_value << std::endl;

    // A pointer can point somewhere else
    std::cout << std::endl;
    std::cout << "A pointer can point somewhere else: " << std::endl;

    p_double_value1 = &other_double_value;
    std::cout << "double_value1: " << double_value1 << std::endl;
    std::cout << "ref_double_value1: " << ref_double_value1 << std::endl;
    std::cout << "p_double_value1: " << p_double_value1 << std::endl;
    std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;
    std::cout << "other_double_value: " << other_double_value << std::endl;

    std::cout << std::endl;
    std::cout << "Changing the now pointed to value: " << std::endl;

    *p_double_value1 = 555.66;

    std::cout << "double_value1: " << double_value1 << std::endl;
    std::cout << "ref_double_value1: " << ref_double_value1 << std::endl;
    std::cout << "p_double_value1: " << p_double_value1 << std::endl;
    std::cout << "*p_double_value1: " << *p_double_value1 << std::endl;
    std::cout << "other_double_value: " << other_double_value << std::endl;

    // References are somewhat like const pointers
    // References behave like constant pointers, but they have
    // a much friendlier syntax as they don't require dereferencing
    // to read and write through referenced data.
    std::cout<< std::endl;
    double *const const_p_double_value {&double_value};
    // const_p_double_value = &other_double_value; //Error
    std::cout << "*const_p_double_value: "<< *const_p_double_value << std::endl;
    *const_p_double_value = other_double_value;
    std::cout << "*const_p_double_value: "<< *const_p_double_value << std::endl;

    // Non const reference
    std::cout << std::endl;
    std::cout << "Non const reference: " << std::endl;
    int age{27};
    int &ref_age{age};

    std::cout << "age: " << age << std::endl;
    std::cout << "ref_age: " << ref_age << std::endl;

    // Can modify original variable through reference
    std::cout << std::endl;
    std::cout << "Modify original variable through reference: " << std::endl;

    ref_age++;

    std::cout << "age: " << age << std::endl;
    std::cout << "ref_age: " << ref_age << std::endl;

    // const reference
    std::cout << std::endl;
    std::cout << "Const reference: "<< std::endl;
    age = 30;
    const int &const_ref_age{age};

    std::cout <<"age: " << age << std::endl;
    std::cout << "const_ref_age: " << const_ref_age << std::endl;

    // Try to modify throught const reference
    // const_ref_age = 31; //Error

    // Duplicate const reference behavior with pointers
    // Can achieve the same thing as const ref with pointer: const pointer to const data
    // Remember that a reference by default is just like a const pointer. All we need
    // to do is make the const pointer point to const data
    const int* const const_ptr_to_const_age{&age};
    // *const_ptr_to_const_age =32; //Error
    return 0;
}