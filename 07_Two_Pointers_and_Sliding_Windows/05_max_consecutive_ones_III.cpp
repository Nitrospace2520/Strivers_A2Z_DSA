/**
 * @file 05_max_consecutive_ones_III.cpp
 * @author Nirmalya Dhara
 * @brief find the maximum number of consecutive 1s in this array if you can flip at most k 0s.
 * @date 2024-10-21
 */

#include <bits/stdc++.h>

/**
 * Find the maximum number of consecutive ones in an array with at most 'k' zeros that can be flipped.
 *
 * @param arr[] An array of integers containing 0s and 1s
 * @param n The size of the array
 * @param k The maximum number of zeros that can be flipped
 * @return The length of the longest subarray with consecutive ones
 */
int find_max_consecutive_ones(int arr[], int n, int k)
{
    /* // * Brute force approach => Time complexity: O(n^2)
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count_zeros = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                count_zeros++;

            if (count_zeros > k)
                break;
            else
                res = std::max(res, (j - i + 1));
        }
    }
    return res; */

    /* // * Better approach => Time complexity: O(2N)
    int res = 0, count_zeros = 0, left = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count_zeros++;
        while (count_zeros > k && left <= i)
        {
            if (arr[left] == 0)
                count_zeros--;
            left++;
        }
        res = std::max(res, (i - left + 1));
    }
    return res; */

    // * Optimal Approach => Time Complexity: O(N)
    int res = 0, count_zeros = 0, left = 0;
    for (int right = 0; right < n; right++)
    {
        if (arr[right] == 0)
            count_zeros++;

        if (count_zeros > k)
        {
            if (arr[left] == 0)
                count_zeros--;
            left++;
        }

        if (count_zeros <= k)
            res = std::max(res, (right - left + 1));
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    std::cout << "Max no. of consecutive ones: " << find_max_consecutive_ones(arr, n, k) << std::endl;

    return 0;
}
