/**
 * @file 12_single_element_in_sorted_array.cpp
 * @author Nirmalya Dhara
 * @brief Find the single element in a sorted array where every element appears twice except for one.
 * @date 2024-05-25
 */

#include <bits/stdc++.h>

int find_single_element_in_sorted_array(int nums[], int n)
{
    /* //? Brute force approach: Time Complexity: O(n) and Space Complexity: O(1)
    if (n == 1)
        return nums[0];
    else if (nums[0] != nums[1])
        return nums[0];
    else if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    for (int i = 0; i < n; i += 2)
    {
        if (nums[i] != nums[i + 1])
            return nums[i];
    } */

    //? Optimized approach: Time Complexity: O(log(n)) and Space Complexity: O(1)
    if (n == 1)
        return nums[0];
    else if (nums[0] != nums[1])
        return nums[0];
    else if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int start = 1, end = n - 2;
    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);

        if ((nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]))
            return nums[mid];
        else if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            start = mid + 1;
        else
            end = mid - 1;
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

    std::cout << "The single element in the array is: " << find_single_element_in_sorted_array(nums, n) << std::endl;
    return 0;
}
