/**
 * @file 13_find_peak_element.cpp
 * @author Nirmalya Dhara
 * @brief find the peak element in an array
 * @date 2024-05-27
 */

#include <bits/stdc++.h>

/**
 * Find the peak element in an array using binary search approach.
 *
 * @param nums An array of integers.
 * @param n The size of the array.
 * @return The peak element in the array, or -1 if no peak element is found.
 */
int find_peak_element(int nums[], int n)
{
    /* //? Brute force approach: Time Complexity: O(n) and Space Complexity: O(1)
    if (n == 1)
        return nums[0];
    else if (nums[0] > nums[1])
        return nums[0];
    else if (nums[n - 1] > nums[n - 2])
        return nums[n - 1];

    for (int i = 1; i < n - 1; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            return nums[i];
    }
    return -1; */

    //? Binary Search approach: Time Complexity: O(log(n)) and Space Complexity: O(1)
    if (n == 1)
        return nums[0];
    else if (nums[0] > nums[1])
        return nums[0];
    else if (nums[n - 1] > nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return nums[mid];
        else if (nums[mid] < nums[mid - 1])
            high = mid - 1;
        else
            low = mid + 1;
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

    std::cout << "The peak element in the array is: " << find_peak_element(nums, n) << std::endl;
    return 0;
}
