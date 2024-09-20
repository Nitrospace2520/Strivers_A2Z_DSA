#include <bits/stdc++.h>

using namespace std;
int find_largest_element(vector<int> &arr)
{
    /* //! BruteForce Approach
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1]; */

    //! Optimal Approach
    int largest_ele = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (largest_ele < arr[i])
            largest_ele = arr[i];
    }
    return largest_ele;
}
int main()
{
    vector<int> arr = {10, 2, 5, 98, 7, 9, 25};
    cout << find_largest_element(arr);
    return 0;
}