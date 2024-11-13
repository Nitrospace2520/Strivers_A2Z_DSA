/**
 * @file 13_minimum_window_substring.cpp
 * @author Nirmalya Dhara
 * @brief minimum window substring problem using two pointers and sliding window technique where we have to find the minimum window in a string which will contain all the characters of another string.
 * @date 2024-11-12
 */
#include <bits/stdc++.h>

/**
 * Finds the minimum window substring in the given string `s` that contains all the characters of string `t`.
 *
 * This function uses an optimal sliding window approach to efficiently determine the smallest substring
 * in `s` that includes all characters from `t`, considering their frequency. It returns the length of
 * this minimum window substring and prints the substring itself.
 *
 * @param s The input string in which to find the minimum window substring.
 * @param t The string containing the characters to be included in the window.
 * @return The length of the minimum window substring containing all characters of `t`.
 */
int minimum_window_substring(std::string &s, std::string &t)
{
    /* //?> Brute Force Approach:=> Time Complexity: O(N*N), Space Complexity: O(256)
    int startIdx = -1, minLen = INT_MAX;
    for (int i = 0; i < s.size(); i++)
    {
        std::vector<int> alpha(256, 0);
        for (int j = 0; j < t.size(); j++)
            alpha[t[j]]++;
        int count = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (alpha[s[j]] > 0)
                count += 1;
            alpha[s[j]]--;
            if (count == t.size() && minLen > (j - i + 1))
            {
                minLen = j - i + 1;
                startIdx = i;
            }
        }
    }
    std::cout << s.substr(startIdx, minLen) << std::endl;
    return minLen; */

    // ?> Optimal Approach:=> Time Complexity: O(N)
    int startIdx = -1, minLen = INT_MAX;
    std::vector<int> alpha(256, 0);
    for (auto ch : t)
        alpha[ch]++;

    int left = 0, right = 0, count = 0;
    while (right < s.size())
    {
        if (alpha[s[right]] > 0)
            count += 1;
        alpha[s[right]]--;

        while (count == t.size())
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                startIdx = left;
            }

            alpha[s[left]]++;
            if (alpha[s[left]] > 0)
                count -= 1;
            left++;
        }
        right++;
    }

    std::cout << s.substr(startIdx, minLen) << std::endl;
    return minLen;
}

int main(int argc, char const *argv[])
{
    std::string s = "adocecodebanc";
    std::string t = "abc";

    std::cout << minimum_window_substring(s, t) << std::endl;

    return 0;
}
