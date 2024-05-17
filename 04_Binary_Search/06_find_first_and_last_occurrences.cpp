/**
 * @file 06_find_first_and_last_occurrences.cpp
 * @author Nirmalya Dhara
 * @brief find first and last occurrences of an element in a sorted array
 * @date 2024-04-20
 */
#include <bits/stdc++.h>

/**
 * @brief Find the first occurrence of a target element in a sorted array.
 *
 * This function uses binary search to find the first occurrence of the target element in the given sorted array.
 *
 * @param nums The sorted array of integers.
 * @param n The size of the array.
 * @param target The element to be found.
 * @return The index of the first occurrence of the target element, or -1 if the element is not found.
 *
 * @note The array must be sorted in non-decreasing order for this function to work correctly.
 * @note The time complexity of this function is O(logN), where N is the size of the array.
 * @note The space complexity of this function is O(1).
 */
int findFirstOccurrence(int nums[], int n, int target)
{
    //?> Optimal Approach:(by using Binary Search) Time Complexity: O(logN), Space Complexity: O(1)
    /* //$ Method: 01
    int lb = std::lower_bound(nums, nums + n, target) - nums;
    return (lb < n && nums[lb] == target) ? lb : -1; */

    //$ Method: 02
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            if (mid == 0 || nums[mid - 1] != target)
                return mid;
            end = mid - 1;
        }
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

/**
 * @brief Find the last occurrence of a target element in a sorted array.
 *
 * This function uses binary search to find the last occurrence of the target element in the given sorted array.
 *
 * @param nums The sorted array of integers.
 * @param n The size of the array.
 * @param target The element to be found.
 * @return The index of the last occurrence of the target element, or -1 if the element is not found.
 *
 * @note The array must be sorted in non-decreasing order for this function to work correctly.
 * @note The time complexity of this function is O(logN), where N is the size of the array.
 * @note The space complexity of this function is O(1).
 */
int findLastOccurrence(int nums[], int n, int target)
{
    //?> Optimal Approach:(by using Binary Search) Time Complexity: O(logN), Space Complexity: O(1)
    /* //$ Method: 01
    int lb = std::lower_bound(nums, nums + n, target) - nums;
    if (lb == n || nums[lb] != target)
        return -1;
    int hb = std::upper_bound(nums, nums + n, target) - nums;
    return hb - 1; */

    //$ Method: 02
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            if (mid == n - 1 || nums[mid + 1] != target)
                return mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
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

    int firstOccurrence = findFirstOccurrence(nums, n, target);
    int lastOccurrence = findLastOccurrence(nums, n, target);
    std::cout << "The element found first at index : " << firstOccurrence << "\n";
    std::cout << "The element found last at index : " << lastOccurrence << "\n";
    return 0;
}