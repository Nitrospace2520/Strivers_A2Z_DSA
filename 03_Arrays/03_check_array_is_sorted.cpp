#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Checks if a vector of integers is sorted in non-decreasing order
 *
 * This function iterates through the array once and checks if each element
 * is greater than or equal to its previous element.
 * Time Complexity: O(n) where n is the size of input vector
 * Space Complexity: O(1)
 *
 * @param arr Reference to the vector of integers to check
 * @return true if the array is sorted in non-decreasing order
 * @return false if the array is not sorted in non-decreasing order
 */
bool is_sorted(vector<int> &arr)
{
    //! Optimal Approach
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    cout << (is_sorted(arr) ? "true" : "false") << endl;
    return 0;
}