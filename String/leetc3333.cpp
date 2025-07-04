#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;

int countOriginals(string word, int k)
{
    vector<int> groups;
    int n = word.length();

    // Step 1: Group same consecutive letters
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && word[j] == word[i])
            j++;
        groups.push_back(j - i);
        i = j;
    }

    int maxLen = n;
    vector<int> dp(maxLen + 1, 0);
    dp[0] = 1; // One way to form original string of length 0

    // Step 2: For each group, try picking 1 to group_size letters
    for (int g : groups)
    {
        vector<int> newDp(maxLen + 1, 0);
        for (int len = 0; len <= maxLen; ++len)
        {
            if (dp[len] == 0)
                continue;
            for (int pick = 1; pick <= g; ++pick)
            {
                if (len + pick <= maxLen)
                {
                    newDp[len + pick] = (newDp[len + pick] + dp[len]) % MOD;
                }
            }
        }
        dp = newDp;
    }

    // Step 3: Add up all valid lengths ≥ k
    int ans = 0;
    for (int len = k; len <= maxLen; ++len)
    {
        ans = (ans + dp[len]) % MOD;
    }

    return ans;
}

int main()
{
    cout << countOriginals("aabbccdd", 7) << endl; // Output: 5
    cout << countOriginals("aabbccdd", 8) << endl; // Output: 1
    cout << countOriginals("aaabbb", 3) << endl;   // Output: 8
    return 0;
}
