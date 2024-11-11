/**
 * @file 12_subarray_with_k_different.cpp
 * @author Nirmalya Dhara
 * @brief count the total number of subarrays with k different integers
 * @date 2024-11-12
 */
#include <iostream>
#include <unordered_set>
#include <unordered_map>

/**
 * Counts the number of subarrays with at most k distinct elements.
 *
 * This function uses a sliding window approach with two pointers to efficiently
 * find all subarrays within the given array that contain at most k distinct elements.
 * It maintains a frequency map to track the count of each element within the current
 * window. The window is adjusted by moving the start pointer when the number of distinct
 * elements exceeds k, ensuring that the subarray condition is met.
 *
 * @param nums An array of integers.
 * @param n The size of the array.
 * @param k The maximum number of distinct elements allowed in a subarray.
 * @return The total number of subarrays with at most k distinct elements.
 */
int count_subarray_with_max_k_dist_ele(int nums[], int n, int k)
{
    std::unordered_map<int, int> map;
    int start = 0, end = 0;
    int res = 0;
    while (end < n)
    {
        map[nums[end]]++;
        while (map.size() > k)
        {
            map[nums[start]]--;
            if (map[nums[start]] == 0)
                map.erase(nums[start]);
            start++;
        }
        res += end - start + 1;
        end++;
    }

    return res;
}

/**
 * Counts the number of subarrays with exactly k distinct numbers.
 *
 * This function calculates the number of subarrays within the given array
 * `nums` that contain exactly `k` distinct integers. It utilizes a more
 * efficient approach by leveraging the helper function
 * `count_subarray_with_max_k_dist_ele` to compute the difference between
 * subarrays with at most `k` distinct elements and subarrays with at most
 * `k-1` distinct elements.
 *
 * @param nums An array of integers.
 * @param n The size of the array `nums`.
 * @param k The number of distinct integers required in the subarrays.
 * @return The count of subarrays with exactly `k` distinct integers.
 */
int count_subarray_with_k_distinct_num(int nums[], int n, int k)
{
    /* //?> Brute Force Approach:= Time Complexity: O(N*N) and Space Complexity: O(k)
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        std::unordered_set<int> set;
        for (int j = i; j < n; j++)
        {
            set.insert(nums[j]);
            if (set.size() == k)
                res++;
            else if (set.size() > k)
                break;
        }
    }
    return res; */

    // ?> Better Approach:= Time Complexity: O(N) and Space Complexity: O(N)
    return count_subarray_with_max_k_dist_ele(nums, n, k) - count_subarray_with_max_k_dist_ele(nums, n, k - 1);
}

int main(int argc, char const *argv[])
{
    int nums[] = {2, 1, 1, 1, 3, 4, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    std::cout << count_subarray_with_k_distinct_num(nums, n, k) << std::endl;
    return 0;
}
