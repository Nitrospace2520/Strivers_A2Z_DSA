/**
 * @file 07_count_total_occurrences.cpp
 * @author Nirmalya Dhara
 * @brief count the total number of occurrences of an element in a sorted array
 * @date 2024-04-20
 */
#include <bits/stdc++.h>

/**
 * @brief Find the first occurrence of an element in a sorted array.
 *
 * This function uses the binary search approach to find the first occurrence of the target element in the given sorted array.
 * It returns the index of the first occurrence if found, otherwise returns -1.
 *
 * @param nums The sorted array of integers.
 * @param n The size of the array.
 * @param target The element to find the first occurrence of.
 * @return The index of the first occurrence of the target element in the array. Returns -1 if the element is not found.
 *
 * @note The array must be sorted in non-decreasing order for accurate results.
 * @note The time complexity of this function is O(logN), where N is the size of the array.
 * @note The space complexity of this function is O(1).
 */
int findFirstOccurrences(int nums[], int n, int target)
{
    int lb = std::lower_bound(nums, nums + n, target) - nums;
    if (lb < n && nums[lb] == target)
        return lb;
    return -1;
}

/**
 * @brief Find the last occurrence of an element in a sorted array.
 *
 * This function uses the binary search approach to find the first occurrence of the target element in the given sorted array.
 * It then uses the upper_bound function to find the index of the element just after the last occurrence of the target element.
 * The last occurrence index is obtained by subtracting 1 from the upper_bound index.
 * If the target element is not found, -1 is returned.
 *
 * @param nums The sorted array of integers.
 * @param n The size of the array.
 * @param target The element to find the last occurrence of.
 * @return The index of the last occurrence of the target element in the array. Returns -1 if the element is not found.
 *
 * @note The array must be sorted in non-decreasing order for accurate results.
 * @note The time complexity of this function is O(logN), where N is the size of the array.
 * @note The space complexity of this function is O(1).
 */
int findLastOccurrences(int nums[], int n, int target)
{
    int ub = std::upper_bound(nums, nums + n, target) - nums;
    return ub - 1;
}

/**
 * @brief Find the total number of occurrences of an element in a sorted array.
 *
 * This function uses the binary search approach to find the first and last occurrences of the target element in the given sorted array.
 * It then calculates the total number of occurrences by subtracting the first index from the last index and adding 1.
 *
 * @param nums The sorted array of integers.
 * @param n The size of the array.
 * @param target The element to find the occurrences of.
 * @return The total number of occurrences of the target element in the array. Returns -1 if the element is not found.
 *
 * @note The array must be sorted in non-decreasing order for accurate results.
 * @note The time complexity of this function is O(logN), where N is the size of the array.
 * @note The space complexity of this function is O(1).
 */
int findTotalOccurrences(int nums[], int n, int target)
{
    /* //?> Brute Force Approach: (by using Linear Search) Time Complexity: O(N), Space Complexity: O(1)
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            res++;
    }
    return res; */

    //?> Optimal Approach: (by using Binary Search) Time Complexity: O(logN), Space Complexity: O(1)
    int firstIndex = findFirstOccurrences(nums, n, target);
    if (firstIndex == -1)
        return 0;
    int lastIndex = findLastOccurrences(nums, n, target);
    return (lastIndex - firstIndex) + 1;
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

    int totalOccurrences = findTotalOccurrences(nums, n, target);
    std::cout << "The element " << target << " total occurrs: " << totalOccurrences << std::endl;
    return 0;
}