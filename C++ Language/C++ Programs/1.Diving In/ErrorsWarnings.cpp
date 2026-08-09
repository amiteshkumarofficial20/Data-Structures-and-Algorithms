#include <iostream>

int main()
{

    // Compile time error
    std::cout << "Hello Word!" << std::endl

        // Run time error
        int value = 7 / 3;
    std::cout << "value : " << value << std::endl;

    23 / 0; /// warning division by 0
    return 0;
}