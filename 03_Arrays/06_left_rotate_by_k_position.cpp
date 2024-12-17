/**
 * @file 06_left_rotate_by_k_position.cpp
 * @author Nirmalya Dhara
 * @brief rotate an array by k position to the left
 * @date 2023-12-20
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
void printArray(vector<int> &arr)
{
    for (auto &&i : arr)
        cout << i << " ";
    cout << endl;
}

/**
 * @brief Rotates all elements in the vector one position to the left.
 *
 * @details Takes first element and stores it temporarily. Shifts all other elements
 * one position left, then places the temporary element at the end of vector.
 * Time Complexity: O(n), where n is size of vector
 * Space Complexity: O(1)
 *
 * @param arr Reference to vector of integers to be rotated
 */
void left_rotate_by_1(vector<int> &arr)
{
    int t = arr[0];
    for (int i = 1; i < arr.size(); i++)
        arr[i - 1] = arr[i];
    arr[arr.size() - 1] = t;
}

/**
 * @brief Reverses the array from start to end index
 *
 * @details Swaps elements from start to end index
 * Time Complexity: O(n), where n is size of vector
 * Space Complexity: O(1)
 *
 * @param arr Reference to vector of integers to be reversed
 * @param start Starting index of the array
 * @param end Ending index of the array
 */
void reverseArray(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * @brief Rotates all elements in the vector k positions to the left.
 *
 * @details Reverses the array from 0 to k-1, then from k to n-1, then the whole array.
 * Time Complexity: O(n), where n is size of vector
 * Space Complexity: O(1)
 *
 * @param arr Reference to vector of integers to be rotated
 * @param k Number of positions to rotate the array
 */
void left_rotate_by_k(vector<int> &arr, int k = 1)
{
    k = k % arr.size();
    /* //! Brute Force Solution (T.C : O(K*N), S.C : O(1))
    for (int i = 0; i < k; i++)
        left_rotate_by_1(arr); */

    /* //! Better Approach (T.C : O(N), S.C : O(K))
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
        temp[i] = arr[i];
    for (int i = k; i < arr.size(); i++)
        arr[i - k] = arr[i];
    for (int i = 0; i < k; i++)
        arr[i + arr.size() - k] = temp[i]; */

    //! Optimal Solution (T.C: O(N), S.C: O(1))
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, arr.size() - 1);
    reverseArray(arr, 0, arr.size() - 1);

    printArray(arr);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    left_rotate_by_k(arr, 5);
    return 0;
}