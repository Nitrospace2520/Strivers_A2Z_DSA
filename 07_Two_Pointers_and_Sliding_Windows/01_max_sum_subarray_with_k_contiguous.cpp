/**
 * @file 01_max_sum_subarray_with_k_contiguous.cpp
 * @author Nirmalya Dhara
 * @brief find the maximum sum of any contiguous subarray of size ‘k’.
 * @date 2024-09-21
 */

#include <iostream>

/**
 * Calculate the maximum sum of a subarray of length 'k' within an array.
 *
 * @param arr The input array
 * @param n The size of the input array
 * @param k The length of the subarray
 * @return The maximum sum of a subarray of length 'k'
 */
int max_sum_subarray(int arr[], int n, int k)
{
    /* //? Naive Approach:= Time: O(K * (N - K)) & Space: O(1)
    int res = 0;

    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
            sum += arr[i + j];

        res = std::max(res, sum);
    }
    return res; */

    //? Optimal Approach:= Time: O(N) and Space: O(1)
    int max_sum = 0;
    int window_sum = 0;
    for (int i = 0; i < k; i++)
        window_sum += arr[i];

    max_sum = window_sum;
    for (int i = k; i < n; i++)
    {
        window_sum = window_sum - arr[i - k] + arr[i];
        max_sum = std::max(max_sum, window_sum);
    }
    // return max_sum;
}

int main()
{
    int arr[] = {2, 1, 25, -1, -3, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int result = max_sum_subarray(arr, n, k);
    std::cout << "Maximum sum of a subarray of size " << k << " is " << result << std::endl;

    return 0;
}