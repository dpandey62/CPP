// Prime Factorization using Sieve

#include <iostream>
#include <vector>
using namespace std;

void primefactor(int n)
{
    vector<int> spf(n + 1); // dynamic allocation

    // Step 1: Initialize spf[i] = i
    for (int i = 2; i <= n; i++)
    {
        spf[i] = i;
    }

    // Step 2: Sieve to fill smallest prime factor for every number
    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        { // i is prime
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    // Step 3: Factorize the number using spf
    cout << "Prime factors: ";
    while (n != 1)
    {
        cout << spf[n] << " ";
        n /= spf[n];
    }
    cout << endl;
}

// main function to test the prime factorization function
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    primefactor(n);
    return 0;
}
