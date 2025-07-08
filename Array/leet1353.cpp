#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};

    // Sort events by their start day
    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> minHeap;

    int day = 0, index = 0, n = events.size(), result = 0;

    while (!minHeap.empty() || index < n)
    {
        if (minHeap.empty())
        {
            day = events[index][0];
        }

        // Push all events that can start on or before today
        while (index < n && events[index][0] <= day)
        {
            minHeap.push(events[index][1]);
            index++;
        }

        if (!minHeap.empty())
        {
            minHeap.pop(); // Attend the event that ends earliest
            result++;
            day++;
        }

        // Remove all events that are already expired
        while (!minHeap.empty() && minHeap.top() < day)
        {
            minHeap.pop();
        }
    }

    cout << "Maximum number of events that can be attended: " << result << endl;

    return 0;
}
