/**
 * @file 16_sort_array_0s_1s_2s_form.cpp
 * @author Nirmalya Dhara
 * @brief sort an array 0's, 1's, 2's form
 * @date 2024-02-09
 */

#include <bits/stdc++.h>

/**
 * @brief Sorts an array containing only 0s, 1s, and 2s (Dutch National Flag problem)
 *
 * This function implements three different approaches to sort an array of 0s, 1s, and 2s:
 * 1. Brute Force: Using standard sort (O(NlogN))
 * 2. Better: Count frequencies and rewrite array (O(N))
 * 3. Optimal: Dutch National Flag algorithm using 3 pointers (O(N))
 *
 * The implemented solution uses the optimal Dutch National Flag algorithm which:
 * - Uses low pointer for placing 0s
 * - Uses mid pointer for placing 1s
 * - Uses high pointer for placing 2s
 *
 * @param nums Reference to vector containing array of 0s, 1s, and 2s to be sorted
 *
 * @time_complexity O(N) where N is the size of input array
 * @space_complexity O(1) as it sorts in-place
 */
void sort_0s_1s_2s_form(std::vector<int> &nums)
{
    /* //? Brute-Force Approach: (Sorting) Time: O(NlogN)
    std::sort(nums.begin(), nums.end()); */

    /* //? Better Approach: Time: O(N)
    int noZeros = 0, noOnes = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            noZeros++;
        else if (nums[i] == 1)
            noOnes++;
    }
    for (int i = 0; i < noZeros; i++)
        nums[i] = 0;
    for (int i = noZeros; i < noZeros + noOnes; i++)
        nums[i] = 1;
    for (int i = noZeros + noOnes; i < nums.size(); i++)
        nums[i] = 2; */

    //? Optimal Approach: (Deutch National Flag Algorithm) Time: O(N)
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    std::vector<int> nums{0, 1, 2, 2, 1, 0, 0, 2, 1, 0, 1, 0};
    sort_0s_1s_2s_form(nums);

    for (auto num : nums)
        std::cout << num << "  ";
    std::cout << "\n";

    return 0;
}