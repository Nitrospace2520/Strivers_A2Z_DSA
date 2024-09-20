#include <bits/stdc++.h>

using namespace std;
int find_second_smallest_element(vector<int> &arr)
{
    /* //! BruteForce Approach
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] != arr[i])
        {
            return arr[i];
        }
    }
    return INT_MAX; */

    //! Optimal Approach
    int smallest_ele = arr[0];
    int second_smallest = INT_MAX;
    for (int i = 1; i < arr.size(); i++)
    {
        if (smallest_ele > arr[i])
        {
            second_smallest = smallest_ele;
            smallest_ele = arr[i];
        }
        else if (smallest_ele != arr[i] && second_smallest > arr[i])
        {
            second_smallest = arr[i];
        }
    }
    return second_smallest;
}
int main()
{
    vector<int> arr = {10, 2, 5, 2, 2, 98, 7, 9, 25, 98, 98};
    cout << find_second_smallest_element(arr);
    return 0;
}