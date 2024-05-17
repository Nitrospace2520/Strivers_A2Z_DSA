/**
 * @file 09_search_in_rotated_sorted_array_with_duplicates.cpp
 * @author Nirmalya Dhara
 * @brief search an element in a rotated sorted array with duplicates values
 * @date 2024-04-20
 */
#include <bits/stdc++.h>

/**
 * @brief Search for an element in a rotated sorted array with duplicate values.
 *
 * This function takes in an array of integers, the size of the array, and the target element to search for.
 * It performs a binary search on the rotated sorted array to find the index of the target element.
 * If the target element is found, the function returns the index of the element.
 * If the target element is not found, the function returns -1.
 *
 * @param nums The array of integers.
 * @param n The size of the array.
 * @param target The target element to search for.
 * @return Any index of the target element if found, -1 otherwise.
 */
int searchInRotatedSortedArrWithDuplicateValues(int nums[], int n, int target)
{
    // note: return only if is at present or not.
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[start] == nums[mid] && nums[mid] == nums[end])
        {
            start += 1;
            end -= 1;
            continue;
        }
        else if (nums[start] <= nums[mid])
        {
            if (nums[start] <= target && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
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

    int idx = searchInRotatedSortedArrWithDuplicateValues(nums, n, target);
    if (idx != -1)
        std::cout << "The element is found at index : " << idx << std::endl;
    else
        std::cout << "The element is not found\n";
    return 0;
}