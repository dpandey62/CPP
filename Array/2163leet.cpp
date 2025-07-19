// 2163. Minimum Difference in Sums After Removal of Elements  .....

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;
        int m = nums.size();

        // ---- LEFT PART ----
        vector<long long> left(m, 0);
        priority_queue<int> maxHeap; // store largest elements
        long long sum = 0;

        for (int i = 0; i < 2 * n; i++)
        {
            sum += nums[i];
            maxHeap.push(nums[i]);

            // keep only n smallest
            if ((int)maxHeap.size() > n)
            {
                sum -= maxHeap.top();
                maxHeap.pop();
            }

            if ((int)maxHeap.size() == n)
                left[i] = sum;
        }

        // ---- RIGHT PART ----
        vector<long long> right(m, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap; // store smallest elements
        sum = 0;

        for (int i = m - 1; i >= n; i--)
        {
            sum += nums[i];
            minHeap.push(nums[i]);

            // keep only n largest
            if ((int)minHeap.size() > n)
            {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if ((int)minHeap.size() == n)
                right[i] = sum;
        }

        long long ans = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; i++)
        {
            ans = min(ans, left[i] - right[i + 1]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 2};                //  output -1
    cout << sol.minimumDifference(nums) << endl; // Example usage
    return 0;
}