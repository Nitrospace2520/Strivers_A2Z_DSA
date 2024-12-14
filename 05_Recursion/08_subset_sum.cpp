/**
 * @file 08_subset_sum.cpp
 * @author Nirmalya Dhara
 * @brief print sum of all subsets of a given set of numbers incresing order
 * @date 2024-12-14
 */
#include <bits/stdc++.h>

/**
 * @brief Generates all possible subset sums of a given set of numbers.
 *
 * This function recursively generates all possible subset sums of the given set of numbers
 * and stores them in the provided vector.
 *
 * @param nums The input vector containing the set of numbers.
 * @param n The size of the input vector.
 * @param idx The current index in the input vector.
 * @param sum The current sum of the subset being generated.
 * @param subsetsum The vector to store all the subset sums.
 */
void generate_subset_sum(const std::vector<int> &nums, int n, int idx, int sum, std::vector<int> &subsetsum)
{
    if (idx == n)
    {
        subsetsum.push_back(sum);
        return;
    }

    generate_subset_sum(nums, n, idx + 1, sum + nums[idx], subsetsum);
    generate_subset_sum(nums, n, idx + 1, sum, subsetsum);
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {3, 2, 5};
    int n = nums.size();
    std::vector<int> subsetsum;

    generate_subset_sum(nums, n, 0, 0, subsetsum);

    std::sort(subsetsum.begin(), subsetsum.end());
    for (auto i : subsetsum)
        std::cout << i << " ";

    return 0;
}
