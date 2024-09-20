/**
 * @file 15_two_sum.cpp
 * @author Nirmalya Dhara
 * @brief find the if the given sum is sum of two elements of an array or not if yes find the indexs if not the return {-1, -1}
 * @date 2024-02-09
 */

#include <bits/stdc++.h>

std::vector<std::pair<int, int>> two_sum(std::vector<int> &nums, int &target)
{
    /* //? Brute-Force Approach: Time: O(N*N), Space: O(1)
    std::vector<std::pair<int, int>> ans;
    bool flag = false;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back({i, j});
                flag = true;
            }
        }
    }
    if (flag)
        return ans;
    return std::vector<std::pair<int, int>>{{-1, -1}}; */

    /* //? Optimal Approach: Time: O(N*N) {worst for unordered_map}, Space: O(N)
    std::vector<std::pair<int, int>> ans;
    bool flag = false;
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int rem = (target - nums[i]);
        if (map.find(rem) != map.end())
        {
            ans.push_back({map[rem], i});
            flag = true;
        }
        map[nums[i]] = i;
    }
    if (flag)
        return ans;
    return std::vector<std::pair<int, int>>{{-1, -1}}; */

    //? Better Approach: Time: O(NlogN), Space: O(N) [Two Pointer Approach]
    std::vector<std::pair<int, int>> ans;
    bool flag = false;
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
        map[nums[i]] = i;

    std::sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        if (nums[left] + nums[right] == target)
        {
            int idx1 = map[nums[left]], idx2 = map[nums[right]];
            int min = std::min(idx1, idx2);
            int max = std::max(idx1, idx2);
            ans.push_back({min, max});
            flag = true;
            left++;
        }
        else if (nums[left] + nums[right] > target)
            right = right - 1;
        else
            left++;
    }
    if (flag)
        return ans;
    else
        std::vector<std::pair<int, int>>{{-1, -1}};
}

int main()
{
    std::vector<int> nums{3, 6, 5, 8, 11};
    int target = 14;
    std::vector<std::pair<int, int>> ans = two_sum(nums, target);
    for (auto it : ans)
        if (it.first != -1)
            std::cout << it.first << "  " << it.second << "\n";

    return 0;
}