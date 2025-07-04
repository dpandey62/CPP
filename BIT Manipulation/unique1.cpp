// WRITE A PROGRAM TO FIND A UNIQUE NUMBERS IN AN ARRAY WHERE ALL NUMBERS EXCEPT ONE ARE PRESENT TWICE
//{2,4,6,3,4,6,2}

#include <iostream>
using namespace std;

int unique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    return xorsum;
}
int main()
{
    int arr[] = {2, 4, 6, 3, 4, 6, 2};
    // int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The unique number in the array is: " << unique(arr, 7) << endl;
    return 0;
}