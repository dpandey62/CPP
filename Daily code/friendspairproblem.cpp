// Friends Pairing Problems
// Find the number of ways in which n friends can remain single or can be paired up with each other.
#include <iostream>
using namespace std;
int friendsPairing(int n)
{
    if (n <= 2)
        return n; // Base cases: 1 way for 1 friend, 2 ways for 2 friends
    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}
int main()
{
    int n;
    cout << "Enter the number of friends: ";
    cin >> n;
    cout << "Number of ways to pair " << n << " friends: " << friendsPairing(n) << endl;
    return 0;
}