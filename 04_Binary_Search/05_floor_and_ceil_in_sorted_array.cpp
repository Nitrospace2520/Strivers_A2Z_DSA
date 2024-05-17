/**
 * @file 05_floor_and_ceil_in_sorted_array.cpp
 * @author Nirmalya Dhara
 * @brief find the floor and ceil element of a target element in a sorted array
 * @date 2024-04-19
 */
#include <bits/stdc++.h>

/**
 * @brief Find the floor element of a target element in a sorted array.
 *
 * This function takes in a sorted array 'nums' of size 'n' and a target element 'target'.
 * It returns the largest element in the array that is less than or equal to the target element.
 * If there is no such element, it returns -1.
 *
 * @param nums The sorted array of integers.
 * @param n The size of the array.
 * @param target The target element to find the floor for.
 * @return The floor element of the target element in the array.
 */
int findFloor(int nums[], int n, int target)
{
    int res = -1;
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] <= target)
        {
            res = nums[mid];
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return res;
}

/**
 * @brief Find the ceil element of a target element in a sorted array.
 *
 * This function takes in a sorted array 'nums' of size 'n' and a target element 'target'.
 * It returns the smallest element in the array that is greater than or equal to the target element.
 * If there is no such element, it returns -1.
 *
 * @param nums The sorted array of integers.
 * @param n The size of the array.
 * @param target The target element to find the ceil for.
 * @return The ceil element of the target element in the array.
 */
int findCeil(int nums[], int n, int target)
{
    // NOTE: Exactly same as finding lower bound:-
    int ceilIndex = std::lower_bound(nums, nums + n, target) - nums;
    return ceilIndex >= n ? -1 : nums[ceilIndex];
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

    int floorElement = findFloor(nums, n, target);
    int ceilElement = findCeil(nums, n, target);
    std::cout << "Floor Element : " << floorElement << "\n";
    std::cout << "Ceil Element : " << ceilElement << "\n";

    return 0;
}