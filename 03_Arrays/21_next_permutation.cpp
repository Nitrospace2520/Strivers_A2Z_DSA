/**
 * @file 21_next_permutation.cpp
 * @author Nirmalya Dhara
 * @brief find the next permutation of a given sequence of numbers
 * @date 2024-09-16
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Find the next permutation of a given sequence of numbers.
 *
 * @param nums An array of numbers
 * @param n The number of elements in the nums array
 * @return nums The next permutation of the given sequence of numbers
 */
std::vector<int> next_permutation(int nums[], int n)
{
    /* //*> Bruteforce approach (Time complexity: O(n!)) // Incomplete
    std::vector<int> res;
    std::string s;
    for (int i = 0; i < n; i++)
    {
        res.push_back(nums[i]);
        s += std::to_string(nums[i]);
    }

    std::string str = "";
    std::sort(res.begin(), res.end());
    for (int i = 0; i < n; i++)
        str += std::to_string(res[i]);

    if (str == s)
    {
        std::reverse(res.begin(), res.end());
        return res;
    } */

    /* //*> Better approach (Time complexity: O(n * n!))
    std::next_permutation(nums, nums + n);
    return std::vector<int>(nums, nums + n); */

    //*> Optimal approach (Time complexity: O(n))
}

int main()
{
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);
    std::vector<int> res = next_permutation(nums, n);
    for (int i = 0; i < n; i++)
        std::cout << res[i] << " ";
    return 0;
}
