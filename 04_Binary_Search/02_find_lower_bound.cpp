/**
 * @file 02_find_lower_bound.cpp
 * @author Nirmalya Dhara
 * @brief find the lower bound of a search element in an array. smallest index such that arr[ind] >= n
 * @date 2024-04-18
 * @copyright Copyright (c) 2024
 */
#include <bits/stdc++.h>

/**
 * @brief Find the lower bound of a search element in an array.
 *
 * This function finds the smallest index in the array such that arr[ind] >= target.
 *
 * @param nums The array of integers.
 * @param n The size of the array.
 * @param target The element to search for.
 * @return The index of the lower bound element.
 *
 * @note The array 'nums' must be sorted in non-decreasing order.
 *
 * @see std::lower_bound
 */
int lowerBound(int nums[], int n, int target)
{
    /* // ? BRUTE FORCE APPROACH: TIME COMPLEXITY: O(N), SPACE COMPLEXITY: O(1)
    int resIdx = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            return i;
        else if (nums[i] > target)
            break;
        else
            resIdx = i;
    }
    if (nums[resIdx] < target)
        resIdx++;
    return resIdx; */

    /* // ? OPTIMAL APPROACH: TIME COMPLEXITY: O(logN), SPACE COMPLEXITY: O(1)
    int resIdx = n;
    int start = 0, end = n - 1;
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

    // ? C++ INBUILT FUNCTION:-
    auto idx = std::lower_bound(nums, nums + n, target) - nums;
    return idx;
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

    int index = lowerBound(nums, n, target);
    std::cout << "The lower bound is at index : " << index << "\n";

    return 0;
}