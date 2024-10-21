/**
 * @file 02_size_of_max_contiguous_subarray_with_sum.cpp
 * @author Nirmalya Dhara
 * @brief find the size of the maximum contiguous subarray with a given sum.
 * @date 2024-09-21
 */

#include <bits/stdc++.h>

/**
 * Function to find the maximum length of a contiguous subarray with a given sum in an integer array.
 * Uses an optimized approach with O(N) time complexity.
 *
 * @param arr[] The input integer array
 * @param n The size of the input array
 * @param sum The target sum to find in the subarray
 * @return The maximum length of the contiguous subarray with the given sum
 */
int maxSubArraySum(int arr[], int n, int sum)
{
    /* //* Brute Force Approach => Time: O(N*N)
    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum_subarr = 0;
        for (int j = i; j < n; j++)
        {
            sum_subarr += arr[j];
            if (sum == sum_subarr)
                max_len = std::max(max_len, j - i + 1);
        }
    }
    return max_len; */

    /* //* Better approach => Time: O(2N)
    int start = 0, end = 0;
    int curr_sum = 0;
    int max_len = 0;

    while (end < n)
    {
        curr_sum += arr[end];

        while (start <= end && curr_sum > sum)
        {
            curr_sum -= arr[start];
            start++;
        }

        if (curr_sum == sum)
            max_len = std::max(max_len, end - start + 1);
        end++;
    }

    return max_len; */

    //* Optimized approach => Time: O(N)
    int start = 0, end = 0;
    int curr_sum = 0;
    int max_len = 0;

    while (end < n)
    {
        curr_sum += arr[end];

        if (curr_sum == sum)
            max_len = std::max(max_len, end - start + 1);
        else if (curr_sum > sum)
        {
            curr_sum -= arr[start];
            start++;
        }

        end++;
    }

    return max_len;
}

int main()
{
    int arr[] = {1, 4, 0, 44, 0, 5, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;

    std::cout << maxSubArraySum(arr, n, sum) << std::endl;
    return 0;
}