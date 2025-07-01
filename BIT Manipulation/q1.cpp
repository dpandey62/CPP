// write a program to check if a number is a power of 2 or not

#include <iostream>
using namespace std;
bool isPowerOf2(int n)
{
    // A number is a power of 2 if it is greater than 0 and
    // the bitwise AND of the number and its predecessor is 0.
    return (n > 0) && ((n & (n - 1)) == 0);
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOf2(n))
        cout << n << " is a power of 2." << endl;
    else
        cout << n << " is not a power of 2." << endl;

    return 0;
}