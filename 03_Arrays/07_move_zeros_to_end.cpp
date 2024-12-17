/**
 * @file 07_move_zeros_to_end.cpp
 * @author Nirmalya Dhara
 * @brief  moves zeros to the end of an array
 * @date 2023-12-21
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Prints all elements of the array to standard output
 *
 * This function takes a vector of integers and prints each element
 * separated by a space, followed by a newline character.
 *
 * @param arr Reference to the vector of integers to be printed
 */
void print_array(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

/**
 * @brief Moves all zeros to the end of the array
 *
 * @details This function takes a vector of integers and moves all zeros
 * to the end of the array while maintaining the order of non-zero elements.
 * Time Complexity: O(n), where n is the size of the array
 * Space Complexity: O(1)
 *
 * @param arr Reference to the vector of integers to be modified
 */
void move_zeros_to_end(vector<int> &arr)
{
    /* // ! Brute-Force Approach (T.C: O(N), S.C: O(X) where X is the non-zero elements)
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
            temp.push_back(arr[i]);
        arr[i] = 0;
    }
    for (int i = 0; i < temp.size(); i++)
        arr[i] = temp[i]; */
    /* /// ! Better Approach: 1 but (the order will not followed)
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        if (arr[end] == 0)
            end--;
        if (arr[start] == 0)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        else
            start++;
    }
    /// ! Better Approach:- 2
    int start = 0, end = 1;
    while (end < arr.size())
    {
        if (arr[end] == 0)
        {
            end++;
        }
        else if (arr[start] == 0)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            end++;
        }
        else
            start++;
    }
    */
    // ! Optimal Approach:
    int zeroIdx = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            zeroIdx = i;
            break;
        }
    }
    for (int i = zeroIdx + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            std::swap(arr[i], arr[zeroIdx]);
            zeroIdx++;
        }
    }

    print_array(arr);
}

int main()
{
    vector<int> arr = {1, 0, 2, 0, 3, 0, 4, 0, 0, 0, 0, 0, 5};
    // vector<int> arr = {1, 0, 2, 3, 4, 5, 0, 0, 6, 0, 7};
    move_zeros_to_end(arr);
    return 0;
}