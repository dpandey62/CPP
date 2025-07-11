// Add binary numbers represented as strings
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string addBinary(string a, string b)
{
    string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';

        result.push_back((sum % 2) + '0');
        carry = sum / 2;
    }

    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string a, b;
    cout << "Enter first binary number: ";
    cin >> a;
    cout << "Enter second binary number: ";
    cin >> b;

    string result = addBinary(a, b);
    cout << "Sum of binary numbers: " << result << endl;

    return 0;
}