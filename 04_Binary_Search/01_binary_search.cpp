/**
 * @file 01_binary_search.cpp
 * @author Nirmalya Dhara
 * @brief find the target element in an sorted array
 * @date 2024-04-18
 */

#include <bits/stdc++.h>

/**
 * @brief Perform binary search iteratively to find the target element in a sorted array.
 *
 * @param nums The sorted array to search in.
 * @param n The size of the array.
 * @param target The element to search for.
 * @return int The index of the target element if found, -1 otherwise.
 *
 * @details This function performs binary search iteratively to find the target element in a sorted array.
 * It starts with the entire array and repeatedly divides it in half until the target element is found or the search space is empty.
 * The time complexity of this function is O(logN), where N is the size of the array.
 * The space complexity is O(1) as it uses a constant amount of extra space.
 */
int binarySearchIteratively(int nums[], int n, int target)
{
    // ? Time Complexity: O(logN), Space Complexity: O(1)
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;

    /* // ? c++ inbuilt function :=
    return std::binary_search(nums, nums + n, target); // note: but it will only return true or false not the position */
}

/**
 * @brief Perform binary search recursively to find the target element in a sorted array.
 *
 * @param nums The sorted array to search in.
 * @param start The starting index of the search space.
 * @param end The ending index of the search space.
 * @param target The element to search for.
 * @return int The index of the target element if found, -1 otherwise.
 *
 * @details This function performs binary search recursively to find the target element in a sorted array.
 * It divides the search space in half and checks if the middle element is the target.
 * If the middle element is greater than the target, the search is performed on the left half of the array.
 * If the middle element is less than the target, the search is performed on the right half of the array.
 * The function continues to divide the search space until the target element is found or the search space is empty.
 * The time complexity of this function is O(logN), where N is the size of the array.
 * The space complexity is O(logN) due to the recursive calls.
 */
int binarySearchRecursively(int nums[], int start, int end, int target)
{
    // ? Time Complexity: O(logN), Space Complexity: O(logN)
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
        return mid;
    else if (nums[mid] > target)
        binarySearchRecursively(nums, start, (mid - 1), target);
    else
        binarySearchRecursively(nums, (mid + 1), end, target);
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

    int index = binarySearchIteratively(nums, n, target);
    // int index = binarySearchRecursively(nums, 0, n - 1, target);

    if (index != -1)
        std::cout << "The element is found at index : " << index << "\n";
    else
        std::cout << "The element is not found\n";
    return 0;
}