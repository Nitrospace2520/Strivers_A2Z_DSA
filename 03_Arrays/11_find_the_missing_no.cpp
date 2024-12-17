/**
 * @file 11_find_the_missing_no.cpp
 * @author Nirmalya Dhara
 * @brief find the missing number in an array from 1 to N.
 * @date 2024-01-04
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the missing number in a sequence of integers from 1 to N
 *
 * Given an array containing N distinct integers in the range [1, N+1], find the missing number.
 * The array may be sorted or unsorted. Only one number is missing from the sequence.
 *
 * Multiple solution approaches:
 * 1. Brute Force: Check each number from 1 to N if present in array. O(N^2) time
 * 2. Better: Use visited array to mark present numbers. O(N) time, O(N) space
 * 3. Optimal:
 *    a) Using sum formula: N*(N+1)/2 - sum of array elements. O(N) time
 *    b) Using XOR: XOR all array elements and numbers 1 to N. O(N) time
 *
 * @param arr Vector containing N distinct integers in range [1, N+1] with one missing number
 * @return The missing number from the sequence, or -1 if no number is missing
 *
 * @note Current implementation uses XOR approach which works for both sorted/unsorted arrays
 * @time_complexity O(N) where N is the size of input array
 * @space_complexity O(1)
 */
int find_the_missing_no(const vector<int> &arr)
{
    /* // ! BruteForce Solution: T.C: O(N*N), S.C: O(1) where N => arr.size()
    for (int i = 1; i <= arr.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == i)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return i;
    }
    return -1; */

    /* // ! Better Solution: T.C: O(N), S.C: O(N);
    vector<bool> visited(arr.size() + 1, false);
    for (int i = 0; i < arr.size(); i++)
    {
        visited[arr[i]] = true;
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        if (visited[i] == false)
            return i;
    }
    return -1; */

    // ! Optimal Solution: T.C: O(N), S.C: O(1)
    /* /// $ Method: 01 (using sum of natural number)
    int N = arr.size() + 1;
    int sum = N * (N + 1) / 2;
    for (auto ele : arr)
    {
        sum -= ele;
    }
    return sum; */

    /// $ Method: 02 (using xor operation) // better for too large numbers
    /// NOTE: only work for ascending order sorted array
    // int xor1 = 0, xor2 = 0;
    // for (int i = 0; i < arr.size() - 1; i++)
    // {
    //     xor1 = xor1 ^ arr[i];
    //     xor2 = xor2 ^ (i + 1);
    // }
    // xor2 = xor2 ^ arr.size();
    // return xor1 ^ xor2;

    // ? OR work for both sorted or unsorted array:-
    int sum = 0;
    for (auto ele : arr)
        sum = sum ^ ele;
    return (sum != arr.size() + 1) ? sum : -1;
}
int main()
{
    vector<int> arr{6, 2, 3, 4, 7, 5}; // NOTE: array might not sorted
    std::cout << find_the_missing_no(arr);
    return 0;
}