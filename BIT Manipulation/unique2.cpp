// WRITE A PROGRAM TO FIND 2 UNIQUE NUMBERS IN AN ARRAY WHERE ALL NUMBERS EXCEPT TWO ARE PRESENT TWICE
//{2,4,6,7,4,5,6,2}

#include <iostream>
#include <vector>
using namespace std;
int setbit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}
void unique(int arr[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    int tempxor = xorsum;
    // find the rightmost set bit
    int bit = 0;
    int pos = 0;
    while (bit != 1)
    {
        bit = xorsum & 1;
        pos++;
        xorsum = xorsum >>= 1;
    }
    for (int i = 0; i < n; i++)
    {
        // Removed incomplete if statement
    }
    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setbit(arr[i], pos - 1))
        {
            newxor = newxor ^ arr[i];
        }
    }
    cout << newxor << endl;
    cout << (tempxor ^ newxor) << endl;
}

int main()
{
    int arr[] = {2, 4, 6, 7, 4, 5, 6, 2};
    // int n=sizeof(arr)/sizeof(int);
    unique(arr, 8);
    return 0;
}