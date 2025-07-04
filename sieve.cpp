//// Function to find all prime numbers up to a given limit using the Sieve of Eratosthenes
#include <iostream>

using namespace std;

void primeSieve(int n)
{
    int prime[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1; // Mark multiples of i as non-prime
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " "; // Print the prime number
        }
    }
    cout << endl; // New line after printing all prime numbers
}
// Main function to test the sieve function
int main()
{
    int n;
    cout << "Enter the limit up to which you want to find prime numbers: ";
    cin >> n;      // Input the limit
    primeSieve(n); // Call the sieve function
    return 0;      // Exit the program
}
