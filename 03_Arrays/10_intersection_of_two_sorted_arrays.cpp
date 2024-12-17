/**
 * @file 10_intersection_of_two_sorted_arrays.cpp
 * @author Nirmalya Dhara
 * @brief intersection of two sorted arrays
 * @date 2023-12-25
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Prints the elements of an integer vector array to standard output
 *
 * @param arr Reference to a constant vector of integers to be printed
 *
 * Each element is printed with a space separator, and a newline is added at the end
 */
void print_arr(const vector<int> &arr)
{
    for (auto ele : arr)
        cout << ele << " ";
    cout << "\n";
}

/**
 * @brief Finds the intersection of two sorted arrays.
 *
 * This function finds common elements between two sorted arrays using two different approaches:
 * 1. Brute Force: Using nested loops with visited array (Time: O(N1*N2), Space: O(N2))
 * 2. Optimal: Using two pointers approach (Time: O(N1+N2), Space: O(N))
 *
 * Current implementation uses the optimal two-pointer approach to find intersection
 * while maintaining the sorted order of elements.
 *
 * @param arr1 First sorted array
 * @param arr2 Second sorted array
 *
 * @note The function assumes both input arrays are sorted in ascending order
 * @note The function prints the intersection elements directly using print_arr()
 *
 * @time_complexity O(N1 + N2), where N1 and N2 are sizes of input arrays
 * @space_complexity O(N), where N is the number of intersected elements
 */
void intersection_of_two_sorted_arrays(const vector<int> &arr1, const vector<int> &arr2)
{
    vector<int> intersection;
    /* // ! Brute-Force Solution: T.C: O(N1 * N2), S.C: O(N2) where N1 => arr1.size(), N2 => arr2.size()
    vector<bool> visited(arr2.size(), false);
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if (!visited[j] && arr1[i] == arr2[j])
            {
                intersection.push_back(arr1[i]);
                visited[j] = true;
                break;
            }
            else if (arr1[i] < arr2[j])
                break;
        }
    } */

    /// ! Optimal Solution: T.C: O(N1 + N2), S.C: O(N) where N1 => arr1.size(), N2 => arr2.size(), N => No of intersected elements
    /* /// $ Approach: 01
    int idx1 = 0, idx2 = 0;
    vector<bool> visited(arr2.size(), false);
    for (idx1 = 0; idx1 < arr1.size(); idx1++)
    {
        for (; idx2 < arr2.size(); idx2++)
        {
            if (arr1[idx1] == arr2[idx2])
            {
                intersection.push_back(arr1[idx1]);
                idx2++;
                break;
            }
            else if (arr1[idx1] < arr2[idx2])
                break;
        }
    } */

    /// $ Approach: 02
    int idx1 = 0, idx2 = 0;
    while (idx1 < arr1.size() && idx2 < arr2.size())
    {
        if (arr1[idx1] == arr2[idx2])
        {
            intersection.push_back(arr1[idx1]);
            idx1++;
            idx2++;
        }
        else if (arr1[idx1] < arr2[idx2])
            idx1++;
        else
            idx2++;
    }
    print_arr(intersection);
}
int main()
{
    vector<int> arr1{1, 2, 2, 3, 3, 4, 5, 7, 7};
    vector<int> arr2{2, 2, 5, 5, 6, 7, 8, 8, 8, 9};
    intersection_of_two_sorted_arrays(arr1, arr2); //* o/p: 2, 2, 5, 7
    return 0;
}