// write a program to cout the number of ones in the binary representation of a number

#include <iostream>
using namespace std;
int countOnes(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1; // Increment count if the last bit is 1
        n >>= 1;        // Right shift to process the next bit
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = countOnes(n);
    cout << "Number of ones in the binary representation of " << n << " is: " << result << endl;
    return 0;
}