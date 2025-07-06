// check if the array is sorted  and not sorted
// using recursion

#include <iostream>
#include <vector>
using namespace std;
bool sorted(int arr[], int n)
{
    if (n == 1)
    {
        return true; // Base case: an array of one element is sorted
    }

    bool restArray = sorted(arr + 1, n - 1);
    return (arr[0] < arr[1] && restArray);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    cout << sorted(arr, 5) << endl;

    return 0;
}
