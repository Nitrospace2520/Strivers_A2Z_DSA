/**
 * @file 08_search_in_rotated_sorted_array.cpp
 * @author Nirmalya Dhara
 * @brief search in a rotated sorted array
 * @date 2024-04-20
 */

#include <bits/stdc++.h>

/**
 * @brief Search for a target element in a rotated sorted array.
 *
 * This function uses the binary search algorithm to find the target element in a rotated sorted array.
 * The time complexity of this algorithm is O(log N), where N is the size of the array.
 * The space complexity is O(1).
 *
 * @param nums The rotated sorted array.
 * @param n The size of the array.
 * @param target The element to search for.
 * @return The index of the target element if found, -1 otherwise.
 */
int searchInRotatedSortedArr(int nums[], int n, int target)
{
    /* //?> Brute Force Approach: (by using Linear Search), Time Complexity: O(N), Space Complexity: O(1)
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1; */

    //?> Optimal Approach: (by using binary Search), Time Complexity: O(N), Space Complexity: O(1)
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[start] <= nums[mid]) //* if the left part is sorted
        {
            if (nums[start] <= target && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else //* if the right part is sorted
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

    int idx = searchInRotatedSortedArr(nums, n, target);
    if (idx != -1)
        std::cout << "The element is found at index : " << idx << std::endl;
    else
        std::cout << "The element is not found\n";
    return 0;
}