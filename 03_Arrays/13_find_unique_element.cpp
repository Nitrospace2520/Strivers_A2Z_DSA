/**
 * @file 13_find_unique_element.cpp
 * @author Nirmalya Dhara
 * @brief find the unique element other than that every elements present twice in an array.
 * @date 2024-01-06
 */
#include <bits/stdc++.h>
int find_max(const std::vector<int> &nums)
{
    int largest = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (largest < nums[i])
            largest = nums[i];
    }
    return largest;
}
int find_unique_element(std::vector<int> &nums)
{
    /* // ! Brute-Force Solution T.C: O(N*N), S.C: 0(1)
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
                count++;
        }
        if (count == 1)
            return nums[i];
    }
    return -1; */

    // ! Better Solution
    /* // * Method: 01 T.C: O(NlogN), S.C: O(N) using map
    std::map<int, int> mp;
    for (auto num : nums)
        mp[num]++;
    for (auto it : mp)
        if (it.second == 1)
            return it.first;
    return -1; */
    /* // * Method: 02 T.C: O(NlogN), S.C: O(1)
    std::sort(nums.begin(), nums.end());
    int count = 1, res = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            if (count == 1)
                return nums[i - 1];
            count = 1;
        }
        else
            count++;
    }
    if (nums.size() > 2 && nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1];
    return -1; */
    /* // * Method: 03 T.C: O(N+M), S.C: O(M) where M => largest element of the array. // NOTE: Not valid if there exits negative elements in the array.
    int max_element = find_max(nums);
    std::vector<int> temp((max_element + 1), 0);
    for (int i = 0; i < nums.size(); i++)
        temp[nums[i]]++;

    for (int i = 0; i < temp.size(); i++)
        if (temp[i] == 1)
            return i; */
    /* // * Method: 04 using unordered_map T.C: O(N), S.C: O(N)
    std::unordered_map<int, int> mp;
    for (auto num : nums)
        mp[num]++;   // NOTE: worst case T.C can be O(N*N)
    for (auto it : mp)
        if (it.second == 1)
            return it.first;
    return -1; */

    // ! Optimal Solution: T.C: O(N), S.C: O(1)
    int num = 0;
    for (auto n : nums)
        num ^= n;
    return num;
}
int main()
{
    std::vector<int> nums{1, 1, 3, 2, 3, 4, 5, 5, 4, 6, 6}; // 2
    std::cout << find_unique_element(nums);
    return 0;
}