/**
 * @file 18_maximum_subarray_sum.cpp
 * @author Nirmalya Dhra
 * @brief  find and print the maximam subarray which have the greater sum
 * @date 2024-02-09
 */

#include <bits/stdc++.h>

/**
 * @brief Finds the maximum sum of a contiguous subarray within the given vector using Kadane's Algorithm
 *
 * This function implements three approaches:
 * 1. Brute Force - O(N^3) time complexity
 * 2. Better Approach - O(N^2) time complexity
 * 3. Optimal (Kadane's Algorithm) - O(N) time complexity
 *
 * The implemented solution uses Kadane's Algorithm which maintains a running sum
 * and resets it to 0 whenever it becomes negative, while keeping track of the maximum sum seen so far.
 *
 * @param nums Vector of integers containing the array elements
 * @return int Maximum sum of any contiguous subarray within the given array
 *
 * @example
 * vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
 * int result = maximum_subarray_sum(arr); // returns 6 (from subarray {4,-1,2,1})
 *
 * @time_complexity O(N) where N is the size of input vector
 * @space_complexity O(1) constant extra space
 */
int maximum_subarray_sum(std::vector<int> &nums)
{
    /* //? BruteForce Approach: Time: O(N^3), Space: O(1)
    int maximam = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
                sum += nums[k];
            maximam = std::max(maximam, sum);
        }
    }
    return maximam; */

    /* //? Better Approach: Time: O(N*N), Space: O(1)
    int maximam = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            maximam = std::max(maximam, sum);
        }
    }
    return maximam; */

    //? Optimal Approach: Time:O(N), Space: O(1) (Kadane's Algorithm)
    int maximum_sum = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maximum_sum = std::max(maximum_sum, sum);
        if (sum < 0)
            sum = 0;
    }
    return maximum_sum;
}

int main()
{
    std::vector<int> nums{-2, -3, 4, -1, -2, 1, 5, -3};
    int maxSum = maximum_subarray_sum(nums);
    std::cout << maxSum;
    return 0;
}