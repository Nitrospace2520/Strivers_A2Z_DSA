/**
 * @file 07_combination_sum_II.cpp
 * @author Nirmalya Dhara
 * @brief
 * @date 2024-11-14
 */

#include <bits/stdc++.h>

/**
 * @brief Helper function to find all unique combinations in an array where the sum of the numbers is equal to a target value.
 *
 * This function uses recursion and backtracking to explore all possible combinations of numbers that sum up to the target value.
 * It avoids duplicate combinations by skipping over consecutive duplicate numbers.
 *
 * @param nums Array of integers to find combinations from.
 * @param n Size of the nums array.
 * @param target The target sum for the combinations.
 * @param idx The current index in the nums array to consider for the combination.
 * @param store Vector to store the current combination of numbers.
 * @param set Set of vectors to store all unique combinations that sum up to the target.
 */
void helper_function1(int nums[], int n, int target, int idx, std::vector<int> &store, std::set<std::vector<int>> &set)
{
    if (idx == n)
    {
        if (target == 0)
            set.insert(store);
        return;
    }
    if (nums[idx] <= target)
    {
        store.push_back(nums[idx]);
        helper_function1(nums, n, target - nums[idx], idx + 1, store, set);
        store.pop_back();
    }
    helper_function1(nums, n, target, idx + 1, store, set);
}

/**
 * @brief Helper function to find all unique combinations in an array where the sum of the numbers is equal to a target value.
 *
 * This function uses recursion and backtracking to explore all possible combinations of numbers that sum up to the target value.
 * It avoids duplicate combinations by skipping over consecutive duplicate numbers.
 *
 * @param nums Array of integers to find combinations from.
 * @param n Size of the nums array.
 * @param target The target sum for the combinations.
 * @param idx The current index in the nums array to consider for the combination.
 * @param store Vector to store the current combination of numbers.
 * @param set Vector of vectors to store all unique combinations that sum up to the target.
 */
void helper_function2(int nums[], int n, int target, int idx, std::vector<int> &store, std::vector<std::vector<int>> &set)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        set.push_back(store);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        if (nums[i] > target)
            break;

        store.push_back(nums[i]);
        helper_function2(nums, n, target - nums[i], i + 1, store, set);
        store.pop_back();
    }
}

/**
 * @brief Finds all unique combinations in the array where the numbers sum up to the target.
 *
 * This function sorts the input array and then uses a helper function to find all unique combinations
 * that sum up to the given target. The results are printed to the standard output.
 *
 * @param nums The input array of integers.
 * @param n The size of the input array.
 * @param target The target sum for the combinations.
 *
 * @note The function uses a better approach with a time complexity of O(2^t * k), where t is the target
 * and k is the average length of each combination.
 */
void combination_sum_II(int nums[], int n, int target)
{
    // //?> Naive Approach: Time complexity: O(2^t * k * logN)
    // std::set<std::vector<int>> set;
    // std::vector<int> store;
    // int idx = 0;

    // std::sort(nums, nums + n);
    // helper_function1(nums, n, target, idx, store, set);

    //?> Better Approach: Time Complexity: O(2^t * k)
    std::vector<std::vector<int>> set;
    std::vector<int> store;
    int idx = 0;

    std::sort(nums, nums + n);
    helper_function2(nums, n, target, idx, store, set);

    for (auto unique : set)
    {
        for (auto ele : unique)
            std::cout << ele << " ";
        std::cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    int nums[] = {1, 1, 1, 2, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 4;

    combination_sum_II(nums, n, target);

    return 0;
}
