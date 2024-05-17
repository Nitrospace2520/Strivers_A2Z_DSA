/**
 * @file 13_single_number.cpp
 * @author Nirmalya Dhara
 * @brief find the single number in an array where every element appears twice except for one.
 * @date 2024-04-14
 */

#include <bits/stdc++.h>

/**
 * Finds the single number in an array.
 *
 * This function takes an array of integers and its size as input and returns the single number in the array.
 * The single number is the number that appears only once in the array, while all other numbers appear twice.
 *
 * @param arr The array of integers.
 * @param n The size of the array.
 * @return The single number in the array.
 *
 * @note The array must contain exactly one number that appears only once, while all other numbers appear twice.
 * @note The array must not be empty.
 * @note The array must not contain any negative numbers.
 *
 * @complexity The time complexity of this function is O(n), where n is the size of the array.
 *             The space complexity is O(1).
 */
int findSingleNumber(int *arr, int n)
{
    /* //? Naive Solution: Time complexity: O(n^2), Space complexity: O(1)
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            return arr[i];
    } */

    /* //? Brute Force Solution: Time complexity: O(nlogn), Space complexity: O(1)
    std::sort(arr, arr + n);
    for (int i = 0; i < n; i += 2)
    {
        if (i == n - 1 || arr[i] != arr[i + 1])
            return arr[i];
    } */

    /* //? Better Solution:- Time complexity: O(n), Space complexity: O(n)
    std::unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    for (auto i : freq)
        if (i.second == 1)
            return i.first; */

    /* //? Optimized solution using XOR: Time complexity: O(n), Space complexity: O(1)
    int single_number = 0;
    for (int i = 0; i < n; i++)
        single_number ^= arr[i];
    return single_number; */

    //? using built-in function:
    return std::accumulate(arr, arr + n, 0, std::bit_xor<int>());
}

int main()
{
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    int *arr = new int[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "The single number in the array is: " << findSingleNumber(arr, n) << std::endl;
    delete[] arr;
    return 0;
}
