/**
 * @file 06_right_rotate_by_k_position.cpp
 * @author Nirmalya Dhara
 * @brief right rotate an array by k position
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
 * @brief Rotates all elements in the vector one position to the right.
 *
 * @details Takes last element and stores it temporarily. Shifts all other elements
 * one position right, then places the temporary element at the beginning of vector.
 * Time Complexity: O(n), where n is size of vector
 * Space Complexity: O(1)
 *
 * @param arr Reference to vector of integers to be rotated
 */
void right_rotate_by_1(vector<int> &arr)
{
    int temp = arr[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp;
}

/**
 * @brief Reverses elements in a given range of an array.
 *
 * @param arr Reference to the vector array to be modified
 * @param start Starting index of the range to reverse (inclusive)
 * @param end Ending index of the range to reverse (inclusive)
 *
 * The function reverses elements in the array from start to end position using
 * a two-pointer approach. Modification is done in-place by swapping elements.
 */
void reverse_array(vector<int> &arr, int start, int end)
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
 * @brief Rotates an array to the right by k positions
 *
 * This function implements three different approaches to rotate an array:
 * 1. Brute Force: Rotates one position at a time, k times [O(k*n) time, O(1) space]
 * 2. Better: Uses temporary array to store k elements [O(n) time, O(k) space]
 * 3. Optimal: Uses array reversal technique [O(n) time, O(1) space]
 *
 * @param arr Reference to the vector to be rotated
 * @param k Number of positions to rotate (defaults to 1)
 *
 * @note If k > array size, k is adjusted using modulo operation
 * @note The function modifies the array in-place
 *
 * Example:
 * Input: arr = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 */
void right_rotate_by_k(vector<int> &arr, int k = 1)
{
    k = k % arr.size();
    /* //! BruteForce Solution (T.C: O(K*N), S.C: O(1))
    for (int i = 0; i < k; i++)
        right_rotate_by_1(arr); */

    /* //! Better Solution (T.C: O(N), S.C: 0(K))
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
        temp[i] = arr[arr.size() - k + i];
    for (int i = arr.size() - k - 1, j = 0; i >= 0; i--, j++)
        arr[arr.size() - 1 - j] = arr[i];
    for (int i = k - 1; i >= 0; i--)
        arr[i] = temp[i]; */

    // ! Optimal Solution (T.C: O(N), S.C: O(1))
    reverse_array(arr, 0, (arr.size() - k - 1));
    reverse_array(arr, (arr.size() - k), arr.size() - 1);
    reverse_array(arr, 0, arr.size() - 1);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    right_rotate_by_k(arr, 3); // 7, 8, 9, 1, 2, 3, 4, 5, 6
    printArray(arr);
    return 0;
}