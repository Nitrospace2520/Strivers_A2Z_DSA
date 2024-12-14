/**
 * @file 09_subsets_II.cpp
 * @author Nirmalya Dhara
 * @brief find the subsets of a set with duplicates using recursion and backtracking
 * @date 2024-12-14
 */
#include <bits/stdc++.h>

/**
 * @brief Helper function to generate all unique subsets of a given set of numbers.
 *
 * This function uses recursion to explore all possible subsets of the input vector `nums`.
 * It ensures that only unique subsets are added to the result by using a set to store the subsets.
 *
 * @param nums The input vector of integers.
 * @param n The size of the input vector `nums`.
 * @param idx The current index in the input vector `nums` being considered.
 * @param subset The current subset being constructed.
 * @param result The set of unique subsets generated so far.
 */
void generate_subsets_II_helper1(const std::vector<int> &nums, int n, int idx, std::vector<int> &subset, std::set<std::vector<int>> &result)
{
    if (idx == n)
    {
        result.insert(subset);
        return;
    }
    subset.push_back(nums[idx]);
    generate_subsets_II_helper1(nums, n, idx + 1, subset, result);
    subset.pop_back();
    generate_subsets_II_helper1(nums, n, idx + 1, subset, result);
}

/**
 * @brief Helper function to generate all unique subsets of a given set of integers.
 *
 * This function recursively generates all unique subsets of the input vector `nums` and stores them in the `result` vector.
 * It avoids generating duplicate subsets by skipping over duplicate elements in the input vector.
 *
 * @param nums The input vector of integers, which may contain duplicates.
 * @param n The size of the input vector `nums`.
 * @param idx The current index in the input vector from which to consider elements for the current subset.
 * @param subset The current subset being constructed.
 * @param result The vector of vectors where all unique subsets will be stored.
 */
void generate_subsets_II_helper2(const std::vector<int> &nums, int n, int idx, std::vector<int> &subset, std::vector<std::vector<int>> &result)
{
    result.push_back(subset);
    for (int i = idx; i < nums.size(); i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        subset.push_back(nums[i]);
        generate_subsets_II_helper2(nums, n, i + 1, subset, result);
        subset.pop_back();
    }
}

/**
 * @brief Generates all unique subsets of a given set of numbers.
 *
 * This function sorts the input vector of numbers and then generates all unique subsets
 * using a helper function. The subsets are printed to the standard output.
 *
 * @param nums A reference to a vector of integers representing the input set of numbers.
 * @param n An integer representing the size of the input set.
 */
void generate_subsets_II(std::vector<int> &nums, int n)
{
    std::sort(nums.begin(), nums.end());
    std::vector<int> subset;

    // std::set<std::vector<int>> result;
    // generate_subsets_II_helper1(nums, n, 0, subset, result);

    std::vector<std::vector<int>> result;
    generate_subsets_II_helper2(nums, n, 0, subset, result);

    for (auto &s : result)
    {
        std::cout << "[";
        for (auto &i : s)
        {
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1, 2, 2, 1};
    int n = nums.size();
    generate_subsets_II(nums, n);

    return 0;
}
