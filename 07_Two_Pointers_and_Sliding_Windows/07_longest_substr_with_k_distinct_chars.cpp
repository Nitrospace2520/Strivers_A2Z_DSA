/**
 * @file 07_longest_substr_with_k_distinct_chars.cpp
 * @author Nirmalya Dhara
 * @brief find the length of the longest substring with at most k distinct characters.
 * @date 2024-10-23
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

/**
 * Find the length of the longest subarray with at most k distinct characters in a given string.
 *
 * Time complexity:
 * - Optimal Approach: O(N), where N is the length of the input string.
 *
 * Space complexity:
 * - Optimal Approach: O(K), where K is the maximum number of distinct characters allowed.
 *
 * @param str The input string
 * @param k The maximum number of distinct characters allowed
 * @return The length of the longest subarray with at most k distinct characters
 */
int find_longest_subarray_with_k_distinct_characters(const std::string &str, int k)
{
    /* //? Brute-Force Approach => Time: O(N*N), Space: O(K)
    int longest_length = 0;
    for (int i = 0; i < str.size(); i++)
    {
        std::unordered_set<char> set;
        for (int j = i; j < str.size(); j++)
        {
            set.insert(str[j]);
            if (set.size() > k)
                break;
            longest_length = std::max(longest_length, (j - i + 1));
        }
    }
    return longest_length; */

    /* //? Better Approach => Time: O(2N), Space: O(K)
    int longest_length = 0;
    int left = 0, right = 0;
    std::unordered_map<char, int> map;

    while (right < str.length())
    {
        map[str[right]]++;
        while (map.size() > k)
        {
            map[str[left]]--;
            if (map[str[left]] == 0)
                map.erase(str[left]);
            left++;
        }
        longest_length = std::max(longest_length, (right - left + 1));
        right++;
    }
    return longest_length; */

    //? Optimal Approach => Time: O(N), Space: O(K)
    int res = 0;
    int left = 0, right = 0;
    std::unordered_map<char, int> map;
    while (right < str.length())
    {
        map[str[right]]++;
        if (map.size() > k)
        {
            map[str[left]]--;
            if (map[str[left]] == 0)
                map.erase(str[left]);
            left++;
        }
        res = std::max(res, (right - left + 1));
        right++;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    std::string str = "aaabbdcdcdcdc";
    int distict_chars = 2;

    std::cout << find_longest_subarray_with_k_distinct_characters(str, distict_chars);
    return 0;
}
