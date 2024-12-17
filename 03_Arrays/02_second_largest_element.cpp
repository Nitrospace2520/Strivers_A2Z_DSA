#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the second largest element in a vector of integers
 *
 * Uses a single pass approach to track both largest and second largest elements.
 * If all elements are same or vector has only one element, returns INT_MIN.
 *
 * Time Complexity: O(n) where n is size of array
 * Space Complexity: O(1)
 *
 * @param arr Reference to vector of integers to search in
 * @return Second largest element in array, or INT_MIN if it doesn't exist
 */
int find_second_largest_element(vector<int> &arr)
{
    /* //! BruteForce Approach
    sort(arr.begin(), arr.end());
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i + 1] != arr[i])
        {
            return arr[i];
        }
    }
    return -1; */

    //! Optimal Approach
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
    return second_largest;
}
int main()
{
    vector<int> arr = {10, 2, 5, 98, 7, 9, 25, 98, 98};
    cout << find_second_largest_element(arr);
    return 0;
}