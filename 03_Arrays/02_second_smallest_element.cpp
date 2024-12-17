#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the second smallest element in a vector of integers
 *
 * Uses a single pass approach to track both smallest and second smallest elements.
 * If all elements are same or vector has only one element, returns INT_MAX.
 *
 * Time Complexity: O(n) where n is size of array
 * Space Complexity: O(1)
 *
 * @param arr Reference to vector of integers to search in
 * @return Second smallest element in array, or INT_MAX if it doesn't exist
 */
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