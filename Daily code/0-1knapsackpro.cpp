// 0-1 Knapsack Problem
// Put n items with gives weight and value in knapsack of capacity W to get maximum value total value in knapsack.
#include <iostream>
#include <vector>
using namespace std;
int knapsack(int value[], int wt[], int n, int W)
{
    if (n == 0 || W == 0)
        return 0; // Base case: no items or capacity

    if (wt[n - 1] > W)
        return knapsack(value, wt, n - 1, W); // Item can't be included

    // Return the maximum of including or excluding the item
    return max(knapsack(value, wt, n - 1, W),
               value[n - 1] + knapsack(value, wt, n - 1, W - wt[n - 1]));
}
int main()
{
    int wt[] = {10, 20, 30};      // Weights of items
    int value[] = {100, 50, 150}; // Values of items
    int W = 50;                   // Capacity of knapsack

    cout << knapsack(value, wt, 3, W) << endl; // Output the maximum value that can be obtained

    return 0;
}