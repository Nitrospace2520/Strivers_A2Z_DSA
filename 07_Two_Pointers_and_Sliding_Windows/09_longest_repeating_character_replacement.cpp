/**
 * @file 09_longest_repeating_character_replacement.cpp
 * @author Nirmalya Dhara
 * @brief find the length of the longest substring that contains only one character and can be replaced to get the longest repeating character substring
 * @date 2024-11-11
 */

#include <iostream>
#include <string>

/**
 * Finds the length of the longest substring in which the same letter can be repeated
 * by replacing at most 'k' characters in the given string 's'.
 *
 * This function uses a sliding window approach to efficiently determine the maximum
 * length of such a substring. It maintains a count of character frequencies within
 * the current window and adjusts the window size to ensure the number of replacements
 * does not exceed 'k'.
 *
 * @param s The input string in which to find the longest repeating character replacement.
 * @param k The maximum number of character replacements allowed.
 * @return The length of the longest substring achievable by replacing at most 'k' characters.
 */
int find_longest_repeating_character_replacement(std::string &s, int k)
{
    /* // ?> Brute Force Approach:= Time Complexity: O(n^2), Space Complexity: O(1)
    int max_length = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int repeat_len = 0;
        int *count = new int[26]{0};
        for (int j = i; j < s.size(); j++)
        {
            count[s[j] - 'A']++;
            repeat_len = std::max(repeat_len, count[s[j] - 'A']);
            int replace = (j - i + 1) - repeat_len;
            if (replace <= k)
                max_length = std::max(max_length, j - i + 1);
            else
                break;
        }
        delete[] count;
    }
    return max_length; */

    /* // ?> Better Approach:= Time Complexity: O(2N * 26) -> O(N), Space Complexity: O(26) -> O(1)
    int start = 0, end = 0;
    int max_length = 0, max_freq = 0;
    int *count = new int[26]{0};
    while (end < s.size())
    {
        count[s[end] - 'A']++;
        max_freq = std::max(max_freq, count[s[end] - 'A']);
        while ((end - start + 1) - max_freq > k)
        {
            count[s[start] - 'A']--;
            max_freq = 0;
            for (int i = 0; i < 26; i++)
                max_freq = std::max(max_freq, count[i]);

            start++;
        }
        if ((end - start + 1) - max_freq <= k)
            max_length = std::max(max_length, (end - start + 1));
        end++;
    }
    return max_length; */

    // ?> Optimal Approach: Time Complexity: O(N), Space Complexity: O(1)
    int start = 0, end = 0;
    int max_length = 0, max_freq = 0;
    int *count = new int[26]{0};
    while (end < s.size())
    {
        count[s[end] - 'A']++;
        max_freq = std::max(max_freq, count[s[end] - 'A']);
        if ((end - start + 1) - max_freq > k)
        {
            count[s[start] - 'A']--;
            start++;
        }
        if ((end - start + 1) - max_freq <= k)
            max_length = std::max(max_length, (end - start + 1));
        end++;
    }
    delete[] count;
    return max_length;
}

int main(int argc, char const *argv[])
{
    std::string s = "AABABBA";
    int k = 2;

    std::cout << find_longest_repeating_character_replacement(s, k) << std::endl;
    return 0;
}
