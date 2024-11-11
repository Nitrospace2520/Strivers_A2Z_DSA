/**
 * @file 06_fruits_into_baskets.cpp
 * @author Nirmalya Dhara
 * @brief Fruits into two Baskets:= In a row of trees, the i-th tree produces fruit with type tree[i]. You start at any tree of your choice, then repeatedly perform the following steps: Add one piece of fruit from this tree to your baskets. If you cannot, stop. Move to the next tree to the right of the current tree. If there is no tree to the right, stop. Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop. You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each. What is the total amount of fruit you can collect? Return the total amount of fruit you can collect.
 * @date 2024-10-23
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>

/**
 * Calculate the length of the longest subarray with at most two distinct elements in the input array.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 *
 * @param trees An array of integers representing tree types
 * @param n The number of elements in the array
 * @return The length of the longest subarray with at most two distinct elements
 */
int totalFruit(int trees[], int n)
{
    /* //? Brute-Froce Approach:=> Time complexity: O(N*N), Space: O(1)
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // int fruit1 = -1, fruit2 = -1; //* OR
        std::unordered_set<int> set;

        for (int j = i; j < n; j++)
        {
            // if (fruit1 == -1)
            //     fruit1 = trees[j];
            // else if (fruit2 == -1)
            //     fruit2 = trees[j];
            // else if (!(fruit1 == trees[j] || fruit2 == trees[j]))
            //     break;
            // * OR
            set.insert(trees[j]);
            if (set.size() > 2)
                break;

            res = std::max(res, (j - i + 1));
        }
    }
    return res; */

    /* //? Better Approach:=> Time Complexity: O(2N), Space: O(1)
    int max_length = 0;
    int left = 0, right = 0;
    std::unordered_map<int, int> map;

    while (right < n)
    {
        map[trees[right]]++;
        while (map.size() > 2)
        {
            // std::cout << "For " << trees[right] << ", " << trees[left] << " -> " << map[trees[left]] << std::endl;
            map[trees[left]] -= 1;
            if (map[trees[left]] == 0)
                map.erase(trees[left]);
            left++;
        }
        max_length = std::max(max_length, (right - left + 1));
        right++;
    }
    return max_length; */

    //? Optimal Approach:=> Time Complexity: O(N), Space: O(1);
    int max_length = 0;
    int left = 0, right = 0;
    std::unordered_map<int, int> map;

    while (right < n)
    {
        map[trees[right]]++;
        if (map.size() > 2)
        {
            map[trees[left]]--;
            if (map[trees[left]] == 0)
                map.erase(trees[left]);
            left++;
        }
        max_length = std::max(max_length, (right - left + 1));
        right++;
    }
    return max_length;
}
int main(int argc, char const *argv[])
{
    int nums[] = {3, 3, 1, 1, 2, 1, 1, 2, 3, 3, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    std::cout << "Total amount of fruit you can collect: " << totalFruit(nums, n) << std::endl;
    return 0;
}
