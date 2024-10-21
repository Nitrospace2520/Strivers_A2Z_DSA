/**
 * @file 04_longest_substring_without_repeatation.cpp
 * @author Nirmalya Dhara
 * @brief find the length of the longest substring without repeating characters in a given string
 * @date 2024-10-21
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

/**
 * Finds the length of the longest substring without repeating characters in the given string.
 * Uses an optimal approach with O(n) time complexity and O(256) space complexity.
 *
 * @param s The input string
 * @return The length of the longest substring without repeating characters
 */
int longest_substring_without_repeatation(std::string &s)
{
    /* // * Bruteforce approach: O(n^3) time, O(1) space
    int max_length = 0;
    for (int i = 0; i < s.size(); i++)
    {
        std::string temp = "";
        for (int j = i; j < s.size(); j++)
        {
            if (temp.find(s[j]) != std::string::npos)
                break;
            temp += s[j];
        }
        max_length = std::max(max_length, (int)temp.size());
    }
    return max_length; */

    /* // * Better approach: O(n^2) time, O(n) space
    int max_length = 0;
    for (int i = 0; i < s.size(); i++)
    {
        std::unordered_set<char> count;
        for (int j = i; j < s.size(); j++)
        {
            if (count.find(s[j]) != count.end())
                break;
            count.insert(s[j]);
        }
        max_length = std::max(max_length, (int)count.size());
    }
    return max_length; */

    // * Optimal approach: O(n) time, O(256) space
    /* // ? Method - 01: By using a hashmap to store the index of the last occurrence of each character
    std::unordered_map<char, int> count;
    int max_length = 0, start = 0;

    for (int end = 0; end < s.size(); end++)
    {
        if (count.find(s[end]) != count.end())
            start = std::max(start, count[s[end]] + 1);
        count[s[end]] = end;
        max_length = std::max(max_length, end - start + 1);
    }
    return max_length; */
    // ? Method - 02: By using a vector to store the index of the last occurrence of each character
    std::vector<int> count(256, -1);
    int max_length = 0, start = 0;

    for (int end = 0; end < s.size(); end++)
    {
        if (count[s[end]] != -1)
            start = std::max(start, count[s[end]] + 1);
        count[s[end]] = end;
        max_length = std::max(max_length, end - start + 1);
    }
    return max_length;
}
int main(int argc, char const *argv[])
{
    std::string s = "cadbzabcd";

    std::cout << longest_substring_without_repeatation(s) << std::endl;
    return 0;
}
