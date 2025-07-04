// FIND THE K-TH CHARACTER IN A STRING GAME II

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

char kthCharacter(long long k, vector<int> &operations)
{
    int count_ops = 0;
    long long val = k;
    while (val > 1)
    {
        int jumps = ceil(log2(val));
        val -= pow(2, jumps - 1);
        count_ops += operations[jumps - 1];
    }
    return char('a' + (count_ops % 26));
}
int main()
{
    vector<int> ops = {1, 2, 3, 4, 5, 6}; // Example operations
    cout << kthCharacter(1, ops) << endl;
    return 0;
}