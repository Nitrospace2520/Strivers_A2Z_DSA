/**
 * @file 17_majority_element.cpp
 * @author Nirmalya Dhara
 * @brief find the majority element of an array which repeats more than N/2 times
 * @date 2024-02-09
 */
#include <bits/stdc++.h>

/**
 * @brief Finds the majority element in a vector (element appearing more than n/2 times)
 *
 * Implementation includes three approaches:
 * 1. Brute Force - O(N^2) time, O(1) space
 * 2. Hash Map - O(N) time, O(N) space
 * 3. Moore's Voting Algorithm - O(N) time, O(1) space
 *
 * Current implementation uses Moore's Voting Algorithm which:
 * - Finds a candidate majority element in first pass
 * - Verifies if candidate appears more than n/2 times in second pass
 *
 * @param nums Vector of integers to search for majority element
 * @return int Majority element if it exists, -1 otherwise
 * @note Majority element is guaranteed to exist if it appears more than n/2 times
 */
int majority_element(std::vector<int> &nums)
{
    /* //? Brute-Force Approach: Time: O(N*N), Space: O(1)
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 1;
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[i] == nums[j])
                count++;
        if (count > nums.size() / 2)
            return nums[i];
    }
    return -1; */

    /* //? Better Approach: Time: O(N), Space: O(N)
    std::unordered_map<int, int> map;
    for (auto num : nums)
        map[num]++;

    for (auto entity : map)
        if (entity.second > nums.size() / 2)
            return entity.first;
    return -1; */

    //? Optimal Approach: (Moore's Voting Algorithm) Time: O(N), Space: O(1)
    int ans = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
        {
            count--;
            if (count == 0)
            {
                ans = nums[i];
                count = 1;
            }
        }
    }
    count = 0;
    for (int i = 0; i < nums.size(); i++)
        if (ans == nums[i])
            count++;

    if (count > nums.size() / 2)
        return ans;
    return -1;
}

int main()
{
    std::vector<int> nums{2, 2, 3, 3, 2, 3, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << majority_element(nums);
    return 0;
}