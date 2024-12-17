/**
 * @file 09_union_of_two_sorted_arrays.cpp
 * @author Nirmalya Dhara
 * @brief Union of two sorted Arrays
 * @date 2023-12-25
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Prints all elements of a vector array separated by spaces
 *
 * @param arr Reference to vector of integers to be printed
 *
 * Prints each element of the input vector followed by a space,
 * and adds a newline character at the end.
 */
void print_arr(vector<int> &arr)
{
    for (auto &&i : arr)
        cout << i << " ";
    cout << "\n";
}

/**
 * @brief Find the union of two sorted arrays
 *
 * @param arr1 Reference to the first sorted array
 * @param arr2 Reference to the second sorted array
 *
 * This function finds the union of two sorted arrays and prints the union array.
 * Time Complexity: O(N1 + N2), where N1 is the size of the first array and N2 is the size of the second array
 * Space Complexity: O(N1 + N2)
 */
void union_of_two_sorted_arrays(const vector<int> &arr1, const vector<int> &arr2)
{
    int n = arr1.size() + arr2.size();
    vector<int> union_arr;
    /* // ! BruteForce Approach:- T.C: O(NlogN), S.C: O(N) where N = no. of unique elements
    unordered_set<int> set;
    for (int i = 0; i < arr1.size(); i++)
    {
        if (set.find(arr1[i]) == set.end())
            union_arr.push_back(arr1[i]);
        set.insert(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        if (set.find(arr2[i]) == set.end())
            union_arr.push_back(arr2[i]);
        set.insert(arr2[i]);
    }
    sort(union_arr.begin(), union_arr.end());
    /// ! BruteForce Approach:- T.C: O(N1logN + N2logN), S.C: O(N) where N1 => arr1.size(), N2 => arr2.size(), N => no. of unique element
    set<int> st;
    for (int i = 0; i < arr1.size(); i++)
        st.insert(arr1[i]);
    for (int i = 0; i < arr2.size(); i++)
        st.insert(arr2[i]);
    for (auto &&i : st)
        union_arr.push_back(i); */

    // ! Optimal Approach:- T.C: O(N1 + N2), S.C: O(N1 + N2) where N1 => arr1.size(), N2 => arr2.size()
    int arr1Idx = 0, arr2Idx = 0;
    while (arr1Idx < arr1.size() || arr2Idx < arr2.size())
    {
        if (arr2Idx >= arr2.size() || arr1[arr1Idx] <= arr2[arr2Idx])
        {
            if (union_arr.size() == 0 || union_arr.back() != arr1[arr1Idx])
                union_arr.push_back(arr1[arr1Idx]);
            arr1Idx++;
        }
        else if (arr1Idx >= arr1.size() || arr1[arr1Idx] > arr2[arr2Idx])
        {
            if (union_arr.size() == 0 || union_arr.back() != arr2[arr2Idx])
                union_arr.push_back(arr2[arr2Idx]);
            arr2Idx++;
        }
    }

    print_arr(union_arr);
}
int main()
{
    vector<int> arr1 = {1, 3, 5, 5, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 11, 12, 12, 13, 14, 15, 16, 16, 17, 18, 18, 18, 18};
    vector<int> arr2 = {2, 2, 4, 5, 6, 7, 7, 15};
    union_of_two_sorted_arrays(arr1, arr2);
    return 0;
}