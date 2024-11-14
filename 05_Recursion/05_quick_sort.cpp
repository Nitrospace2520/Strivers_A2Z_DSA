/**
 * @file 05_quick_sort.cpp
 * @author Nirmalya Dhara
 * @brief sort an array using quick sort algorithm
 * @date 2024-09-20
 */
#include <iostream>

/**
 * Partition the array based on the last element as the pivot.
 *
 * @param nums[] The array to be partitioned
 * @param start The starting index of the array
 * @param end The ending index of the array
 * @return The index of the pivot element after partitioning
 */
int partition01(int nums[], int start, int end)
{
    //* select the last element as pivot element (Lamuto Paritition)
    int pivot = nums[end];
    int pIndex = start - 1;
    for (int i = start; i < end; i++)
    {
        if (nums[i] <= pivot)
        {
            pIndex++;
            std::swap(nums[i], nums[pIndex]);
        }
    }
    pIndex++;
    std::swap(nums[pIndex], nums[end]);
    return pIndex;
}

/**
 * Partition the array using the first element as the pivot.
 *
 * @param nums: An array of integers to be partitioned
 * @param start: The starting index of the array
 * @param end: The ending index of the array
 * @return: The index of the pivot element after partitioning
 */
int partition02(int nums[], int start, int end)
{
    //* select the first element as pivot element (Hoare's Paritition)
    int pivot = nums[start];
    int pIndex = end + 1;
    for (int i = end; i > start; i--)
    {
        if (nums[i] >= pivot)
        {
            pIndex--;
            std::swap(nums[i], nums[pIndex]);
        }
    }
    pIndex--;
    std::swap(nums[pIndex], nums[start]);
    return pIndex;
}

/**
 * Recursively sorts an array of integers using the quicksort algorithm.
 *
 * @param nums: An array of integers to be sorted
 * @param start: The starting index of the subarray to be sorted
 * @param end: The ending index of the subarray to be sorted
 */
void quick_sort(int nums[], int start, int end)
{
    //* Time complexity: O(nlogn) in average case, O(n^2) in worst case
    if (start > end)
        return;

    // int pivot_idx = partition01(nums, start, end);
    int pivot_idx = partition02(nums, start, end);
    quick_sort(nums, start, pivot_idx - 1);
    quick_sort(nums, pivot_idx + 1, end);
}
int main()
{
    int nums[] = {2, 5, 1, 6, 3, 4, 9, 7, 8};
    int n = sizeof(nums) / sizeof(nums[0]);

    quick_sort(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;

    return 0;
}