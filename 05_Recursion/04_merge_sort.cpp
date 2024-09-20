/**
 * @file 04_merge_sort.cpp
 * @author Nirmalya Dhara
 * @brief merge sort algorithm
 * @date 2024-09-20
 */
#include <iostream>

/**
 * Merge two subarrays of nums[] into a single sorted subarray.
 *
 * @param nums The array to be sorted
 * @param start The starting index of the first subarray
 * @param mid The ending index of the first subarray and the starting index of the second subarray
 * @param end The ending index of the second subarray
 */
void merge(int nums[], int start, int mid, int end)
{
    /* //* Approach: 01 (Time complexity: O(n), Space complexity: O(n))
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int temp1[n1], temp2[n2];

    for (int i = 0; i < n1; i++)
        temp1[i] = nums[start + i];
    for (int i = 0; i < n2; i++)
        temp2[i] = nums[mid + 1 + i];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (temp1[i] <= temp2[j])
            nums[k++] = temp1[i++];
        else
            nums[k++] = temp2[j++];
    }
    while (i < n1)
        nums[k++] = temp1[i++];
    while (j < n2)
        nums[k++] = temp2[j++]; */

    //* Approach: 02 (Time complexity: O(n), Space complexity: O(n))
    int n = end - start + 1;
    int temp[n];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= end)
        temp[k++] = nums[j++];

    for (int i = 0; i < n; i++)
        nums[start + i] = temp[i];
}

/**
 * Perform merge sort on the given array within the specified range.
 *
 * Time complexity: O(nlogn), Space complexity: O(n)
 *
 * @param nums The array to be sorted
 * @param start The starting index of the range to be sorted
 * @param end The ending index of the range to be sorted
 */
void merge_sort(int nums[], int start, int end)
{
    // Time complexity: O(nlogn), Space complexity: O(n)
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);

    merge(nums, start, mid, end);
}

int main()
{
    int arr[] = {2, 4, 1, 6, 9, 8, 5, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}