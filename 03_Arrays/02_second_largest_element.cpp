#include <bits/stdc++.h>

using namespace std;
int find_second_largest_element(vector<int> &arr)
{
    //! BruteForce Approach
    sort(arr.begin(), arr.end());
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i + 1] != arr[i])
        {
            return arr[i];
        }
    }
    return -1;

    /* //! Optimal Approach
    int largest_ele = arr[0];
    int second_largest = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
    {
        if (largest_ele < arr[i])
        {
            second_largest = largest_ele;
            largest_ele = arr[i];
        }
        else if (largest_ele != arr[i] && second_largest < arr[i])
        {
            second_largest = arr[i];
        }
    }
    return second_largest; */
}
int main()
{
    vector<int> arr = {10, 2, 5, 98, 7, 9, 25, 98, 98};
    cout << find_second_largest_element(arr);
    return 0;
}