/**
 * @file 06_combination_sum.cpp
 * @author Nirmalya Dhara
 * @brief
 * @date 2024-11-14
 */

#include <bits/stdc++.h>

/**
 * Helper function to recursively explore all possible combinations of numbers from the input array.
 *
 * This function is called recursively to explore all possible combinations of numbers from the input array
 * that sum up to the target value. The function stores the valid combinations in a result vector.
 *
 * @param nums An array of integers from which combinations are formed.
 * @param n The size of the input array.
 * @param target The target sum for the combinations.
 * @param idx The current index of the input array.
 * @param store A vector to store the current combination.
 * @param res A vector to store all valid combinations.
 */
void helper_function(int nums[], int n, int target, int idx, std::vector<int> &store, std::vector<std::vector<int>> &res)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        res.push_back(store);
        return;
    }
    if (idx >= n)
        return;

    if (nums[idx] <= target)
    {
        store.push_back(nums[idx]);
        helper_function(nums, n, target - nums[idx], idx, store, res);
        store.pop_back();
    }
    helper_function(nums, n, target, idx + 1, store, res);
}

/**
 * Helper function to recursively explore all possible combinations of numbers from the input array.
 *
 * This function is called recursively to explore all possible combinations of numbers from the input array
 * that sum up to the target value. The function stores the valid combinations in a result vector.
 *
 * @param nums An array of integers from which combinations are formed.
 * @param n The size of the input array.
 * @param target The target sum for the combinations.
 * @param idx The current index of the input array.
 * @param store A vector to store the current combination.
 * @param set A vector to store all valid combinations.
 */
void helper_function2(int nums[], int n, int target, int idx, std::vector<int> &store, std::vector<std::vector<int>> &set)
{
    if (target == 0)
    {
        set.push_back(store);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (nums[i] > target)
            break;

        store.push_back(nums[i]);
        helper_function2(nums, n, target - nums[i], i, store, set);
        store.pop_back();
    }
}

/**
 * Computes all unique combinations of numbers from the input array that sum up to the target value.
 *
 * This function utilizes a helper function to recursively explore all possible combinations
 * and stores the valid combinations in a result vector. The results are then printed to the console.
 *
 * @param nums An array of integers from which combinations are formed.
 * @param n The size of the input array.
 * @param target The target sum for the combinations.
 */
void combination_sum(int nums[], int n, int target)
{
    std::vector<std::vector<int>> res;
    std::vector<int> store;
    int idx = 0;

    helper_function(nums, n, target, idx, store, res);
    // helper_function2(nums, n, target, idx, store, res);

    for (auto row : res)
    {
        for (auto col : row)
            std::cout << col << " ";
        std::cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    int nums[] = {2, 3, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 7;

    combination_sum(nums, n, target);

    return 0;
}
