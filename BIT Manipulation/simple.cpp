#include <iostream>

int main()
{
    int num = 12; // Binary: 00001100

    // Check if 2nd bit (0-indexed) is set
    if (num & (1 << 2))
    {
        std::cout << "2nd bit is set." << std::endl; // Output: 2nd bit is set.
    }

    // Set the 0th bit
    num = num | (1 << 0); // num becomes 13 (00001101)
    std::cout << "After setting 0th bit: " << num << std::endl;

    // Clear the 3rd bit
    num = num & ~(1 << 3); // num becomes 5 (00000101)
    std::cout << "After clearing 3rd bit: " << num << std::endl;

    return 0;
}