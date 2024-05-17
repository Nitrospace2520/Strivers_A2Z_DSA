/**
 * @file 10_min_in_rotated_sorted_array.cpp
 * @author Nirmalya Dhara
 * @brief find the minimum element in a rotated sorted array
 * @date 2024-04-30
 */

#include <bits/stdc++.h>

/**
 * @brief Find the minimum element in a rotated sorted array.
 *
 * This function takes an array of integers and its size as input and returns the minimum element in the array.
 * The array is assumed to be rotated and sorted in ascending order.
 *
 * @param nums The array of integers.
 * @param n The size of the array.
 * @return The minimum element in the array.
 *
 * @note The function uses binary search algorithm to find the minimum element.
 * The time complexity of the function is O(logN), where N is the size of the array.
 * The space complexity of the function is O(1).
 */
int find_minimum_in_sorted_array(int nums[], int n)
{
    /* //? Brute force Approach: (using Linear Search) Time Complexity: O(N), Space Complexity: O(1)
    int smallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (smallest > nums[i])
            smallest = nums[i];
    }
    return smallest; */

    //? Optimal Approach: (using Binary Search) Time Complexity: O(logN), Space Complexity: O(1)
    int left = 0, right = n - 1;
    int smallest = INT_MAX;
    while (left <= right)
    {
        if (nums[left] <= nums[right])
            return std::min(smallest, nums[left]);

        int mid = left + ((right - left) >> 2);
        // if ((mid == 0 || (mid > 0 && nums[mid - 1] >= nums[mid])) && (mid == n - 1 || (mid < n - 1 && nums[mid] <= nums[mid + 1])))
        //     return nums[mid];
        if (nums[left] <= nums[mid])
        {
            smallest = std::min(smallest, nums[left]);
            left = mid + 1;
        }
        else
        {
            smallest = std::min(smallest, nums[mid]);
            right = mid - 1;
        }
    }
    return smallest;
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

    std::cout << "Smallest element is : " << find_minimum_in_sorted_array(nums, n) << std::endl;
    return 0;
}