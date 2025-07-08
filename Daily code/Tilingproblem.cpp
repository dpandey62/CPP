// Tiling problem in recursion

#include <iostream>
using namespace std;
int tiling(int n)
{
    if (n <= 2)
        return n;                         // Base cases: 1 way for 1 tile, 2 ways for 2 tiles
    return tiling(n - 1) + tiling(n - 2); // Recursive case
}
int main()
{
    int n;
    cout << "Enter the number of tiles: ";
    cin >> n;
    cout << "Number of ways to tile a 2x" << n << " rectangle: " << tiling(n) << endl;
    return 0;
}