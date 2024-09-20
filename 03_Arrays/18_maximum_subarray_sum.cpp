/**
 * @file 18_maximum_subarray_sum.cpp
 * @author Nirmalya Dhra
 * @brief  find and print the maximam subarray which have the greater sum
 * @date 2024-02-09
 */

#include <bits/stdc++.h>

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