#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the largest element in a given vector of integers
 *
 * This function takes a vector of integers and returns the maximum element.
 * It uses a single pass approach by maintaining a running maximum.
 * Time Complexity: O(n) where n is the size of vector
 * Space Complexity: O(1)
 *
 * @param arr Reference to the vector of integers to search through
 * @return int Returns the largest element found in the vector
 */
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