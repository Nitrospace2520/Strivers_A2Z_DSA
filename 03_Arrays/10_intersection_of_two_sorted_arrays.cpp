/**
 * @file 10_intersection_of_two_sorted_arrays.cpp
 * @author Nirmalya Dhara
 * @brief intersection of two sorted arrays
 * @date 2023-12-25
 */
#include <bits/stdc++.h>

using namespace std;
void print_arr(const vector<int> &arr)
{
    for (auto ele : arr)
        cout << ele << " ";
    cout << "\n";
}
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
    // int idx1 = 0, idx2 = 0;
    // vector<bool> visited(arr2.size(), false);
    // for (idx1 = 0; idx1 < arr1.size(); idx1++)
    // {
    //     for (; idx2 < arr2.size(); idx2++)
    //     {
    //         if (arr1[idx1] == arr2[idx2])
    //         {
    //             intersection.push_back(arr1[idx1]);
    //             idx2++;
    //             break;
    //         }
    //         else if (arr1[idx1] < arr2[idx2])
    //             break;
    //     }
    // } */

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