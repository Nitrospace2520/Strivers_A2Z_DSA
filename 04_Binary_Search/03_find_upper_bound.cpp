/**
 * @file 03_find_upper_bound.cpp
 * @author Nirmalya Dhara
 * @brief find the upper bound of a given target. arr[idx] > target
 * @date 2024-04-19
 */
#include <bits/stdc++.h>

/**
 * @brief Find the upper bound of a given target in an array.
 *
 * This function takes an array of integers, the size of the array, and a target value as input.
 * It returns the index of the first element in the array that is greater than the target.
 * If no such element exists, it returns the size of the array.
 *
 * @param nums The array of integers.
 * @param n The size of the array.
 * @param target The target value.
 * @return The index of the first element greater than the target, or the size of the array if no such element exists.
 */
int upperBound(int nums[], int n, int target)
{
    /* //? Brute Force Approach: (using linear search) Time Complexity: O(N), Space Complexity: O(1)
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > target)
            return i;
    }
    return n; */

    /* //? Optimal Approach: (using binary search) Time Complexity: O(logN), Space Complexity: O(1)
    int resIdx = n;
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] > target)
        {
            resIdx = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return resIdx; */

    //? Approach: (by using C++ STL)
    return std::upper_bound(nums, nums + n, target) - nums;
}
int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int nums[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    int target;
    std::cout << "Enter the element you want to find : ";
    std::cin >> target;

    int index = upperBound(nums, n, target);
    std::cout << "The upper bound is at index : " << index << "\n";

    return 0;
}