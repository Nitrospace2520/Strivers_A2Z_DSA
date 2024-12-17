// TODO: Remove Duplicate inplace from a sorted array:-
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Prints all elements of an integer vector to console
 *
 * This function takes a vector of integers and prints each element
 * separated by spaces, followed by a newline character.
 *
 * @param arr Reference to the vector of integers to be printed
 */
void printArray(vector<int> &arr)
{
    for (auto &&i : arr)
        cout << i << " ";
    cout << endl;
}

/**
 * @brief Removes duplicate elements from a sorted array in-place
 *
 * This function implements two approaches to remove duplicates:
 * 1. Brute Force - Using unordered_set (commented out)
 * 2. Optimal - Using two pointer technique
 *
 * The optimal approach maintains two pointers:
 * - start: points to last unique element
 * - end: scans through array looking for next unique element
 * When a new unique element is found, it is placed at start+1
 *
 * Time Complexity: O(n) where n is size of input array
 * Space Complexity: O(1)
 *
 * @param arr Reference to vector of integers (must be sorted)
 * @return void Modifies array in-place and prints result
 */
void removeDuplicate(vector<int> &arr)
{
    /* //! Brute Force Approach
    unordered_set<int> st;
    int start = 0;
    for (auto i = 0; i < arr.size(); i++)
    {
        if (st.find(arr[i]) == st.end())
        {
            arr[start++] = arr[i];
        }
        st.insert(arr[i]);
    } */

    //! Optimal Approach (Two Pointer)
    int start = 0, end = 1;
    while (end < arr.size())
    {
        if (arr[start] == arr[end])
            end++;
        else
            arr[++start] = arr[end];
    }
    printArray(arr);
}

int main()
{
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 6, 6, 7};
    removeDuplicate(arr);
    return 0;
}