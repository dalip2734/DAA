#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    string id;
    int deadline;
    int profit;
};
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}
void JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
        slot[i] = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << arr[result[i]].id <<" ";
            sum = sum + arr[result[i]].profit;
        }
    }
    cout << endl
         << "Profit = " << sum;
}

int main()
{
    Job arr[] = {{"T1", 4, 70}, {"T2", 2, 60}, {"T3", 4, 50}, {"T4", 1, 30}, {"T5", 4, 20}, {"T6", 6, 10}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs : \n";
    JobScheduling(arr, n);
    return 0;
}