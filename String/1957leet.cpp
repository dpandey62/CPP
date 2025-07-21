// Delets Characters from a String

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans = "";
        int count = 1; // count of same letters

        ans += s[0]; // first char is always added

        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                count++; // same as previous
            }
            else
            {
                count = 1; // reset for new char
            }

            if (count < 3)
            { // only add if not 3 in a row
                ans += s[i];
            }
        }
        return ans;
    }
};
// MAIN FUNCTION
int main()
{
    Solution sol;
    string s = "leeetcode";
    string result = sol.makeFancyString(s);
    cout << "Resulting string: " << result << endl; // Output: "leetcode"
    return 0;
}
