// Reschedul Meetings for Maximum Free Time |

// LeetCode Problem Number: 3439

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int n = startTime.size();
        vector<int> gap(n + 1);

        for (int i = 1; i < n; i++)
        {
            gap[i] = startTime[i] - endTime[i - 1];
        }
        gap[0] = startTime[0];
        //
        gap[n] = eventTime - endTime[n - 1];
        //

        // Sliding window of size k + 1
        int i = 0,
            j = k;
        int maxa = 0, sum = 0;

        for (int w = i; w <= n && w <= j; w++)
        {
            sum += gap[w];
        }
        maxa = max(maxa, sum);

        while (j < n)
        {
            sum -= gap[i++];
            sum += gap[++j];
            maxa = max(maxa, sum);
        }

        return maxa;
    }
};
int main()
{
    Solution sol;
    int eventTime = 10;
    int k = 2;
    vector<int> startTime = {0, 1, 2, 3, 4};
    vector<int> endTime = {1, 2, 3, 4, 5};

    int result = sol.maxFreeTime(eventTime, k, startTime, endTime);
    cout << "Maximum free time: " << result << endl;
    return 0;
}
