// find the index of the first occurrence of a substring in a string
#include <string>
#include <iostream>
using namespace std;
int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    if (m == 0)
    {
        return 0;
    }
    if (n < m)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (haystack[i] == needle[0])
        {
            if (haystack.substr(i, m) == needle)
            {
                return i;
            }
        }
    }
    return -1;
}
int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    int index = strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl; // Output: 2
    return 0;
}