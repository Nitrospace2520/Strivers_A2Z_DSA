/**
 * @file 04_search_insert_position.cpp
 * @author Nirmalya Dhara
 * @brief you are given a sorted array 'nums' of distinct values and a target element 'target'. You need to search for the target value's index in the array
 * @date 2024-04-19
 */

#include <bits/stdc++.h>

/**
 * @brief This function searches for the index position of a target element in a sorted array.
 *
 * @param nums The sorted array of distinct values.
 * @param n The size of the array.
 * @param target The target element to search for.
 * @return The index position of the target element in the array.
 *
 * @details This function uses the binary search algorithm to find the index position of the target element in the array.
 * It has a time complexity of O(logN) and a space complexity of O(1).
 *
 * @note This function assumes that the input array is sorted in ascending order and contains distinct values.
 * If the target element is not found in the array, the function returns the index position where the element should be inserted to maintain the sorted order.
 */
int searchIndexPosition(int nums[], int n, int target)
{
    // NOTE: This is exactly same as finding lower bound
    /* //? Optimal Approach: (using binary Search) Time Complexity: O(logN), Space Complexity: O(1)
    int start = 0, end = n - 1;
    int resIdx = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= target)
        {
            resIdx = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return resIdx; */

    //? OR (by using C++ stl):
    return std::lower_bound(nums, nums + n, target) - nums;
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

    int index = searchIndexPosition(nums, n, target);
    std::cout << "The search index position : " << index << "\n";

    return 0;
}