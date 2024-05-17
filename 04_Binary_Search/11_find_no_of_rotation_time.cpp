/**
 * @file 11_find_no_of_rotation_time.cpp
 * @author Nirmalya Dhara
 * @brief find out how many times an sorted array is rotated
 * @date 2024-05-02
 */
#include <bits/stdc++.h>

/**
 * @brief Find the index of the smallest element in a rotated sorted array.
 *
 * This function takes an array of integers and its size as input and returns the index of the smallest element in the array.
 * The array is assumed to be sorted in ascending order and then rotated.
 *
 * @param nums An array of integers.
 * @param n The size of the array.
 * @return The index of the smallest element in the array.
 */
int find_smallest_index_in_rotatedarray(int nums[], int n)
{
    int smallest = INT_MAX;
    int smallest_idx = n;
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);
        if (nums[start] <= nums[end])
        {
            smallest = std::min(smallest, nums[start]);
            smallest_idx = smallest == nums[start] ? start : smallest_idx;
            break;
        }
        if (nums[start] <= nums[mid])
        {
            smallest = std::min(smallest, nums[start]);
            smallest_idx = smallest == nums[start] ? start : smallest_idx;
            start = mid + 1;
        }
        else
        {
            smallest = std::min(smallest, nums[mid]);
            smallest_idx = smallest == nums[mid] ? mid : smallest_idx;
            end = mid - 1;
        }
    }
    return smallest_idx;
}

/**
 * @brief Find the number of times a sorted array is rotated.
 *
 * This function takes an array of integers and its size as input and returns the number of times the array is rotated.
 * The array is assumed to be sorted in ascending order and then rotated.
 *
 * @param nums An array of integers.
 * @param n The size of the array.
 * @return The number of times the array is rotated.
 */
int find_no_of_times_array_rotated(int nums[], int n)
{
    /* //? Brute Force Approach: (by using linear search) Time Complexity: O(N), Space Complexity: O(1)
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] < nums[i - 1] && i < n - 1 && nums[i] < nums[i + 1])
            return i;
    }
    return 0; */

    //? Optimal Approach: (by using binary search) Time Complexity: O(logN), Space Complexity: O(1)
    int smallest_idx = find_smallest_index_in_rotatedarray(nums, n);
    return smallest_idx;
}

int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int nums[n];
    std::cout << "Enter the elements of the rotated sorted array: ";
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    std::cout << "No of times the array has been rotated : " << find_no_of_times_array_rotated(nums, n) << std::endl;
    return 0;
}
