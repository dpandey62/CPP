// Merge sorted Array

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;     // Last index of nums1's initial elements
    int j = n - 1;     // Last index of nums2
    int k = m + n - 1; // Last index of merged array

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3; // Number of initial elements in nums1
    int n = 3; // Number of elements in nums2

    merge(nums1, m, nums2, n);

    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}