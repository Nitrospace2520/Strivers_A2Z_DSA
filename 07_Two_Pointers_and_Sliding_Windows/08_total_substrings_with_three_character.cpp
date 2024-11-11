/**
 * @file 08_total_substrings_with_three_character.cpp
 * @author Nirmalya Dhara
 * @brief find the total number of substrings with three characters (like: 'a', 'b', 'c')
 * @date 2024-10-23
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

int total_substr_with_three_chars(const std::string &str)
{
    /* //?> Brute-Force Approach =>  Time: O(N * N)
    int res = 0;
    for (int i = 0; i < str.size(); i++)
    {
        bool foundA = false, foundB = false, foundC = false;
        for (int j = i; j < str.size(); j++)
        {
            if (str[j] == 'a')
                foundA = true;
            else if (str[j] == 'b')
                foundB = true;
            else if (str[j] == 'c')
                foundC = true;

            if (foundA && foundB && foundC)
            {
                // res++;
                res += str.size() - j;
                break;
            }
        }
    }
    return res; */

    /* //?> Better Approach => Time: O(2N), Space: O(1)
    std::unordered_map<char, int> map;
    int start = 0, end = 0;
    int res = 0;
    while (end < str.size())
    {
        map[str[end]]++;
        while (map.size() == 3 && start < end)
        {
            map[str[start]] -= 1;
            if (map[str[start]] == 0)
                map.erase(str[start]);
            res += str.size() - end;
            start++;
        }
        end++;
    }
    return res; */

    //?> Optimal Approach => Time: O(N), Space: O(1)
    int res = 0;
    int *lastSeen = new int[3];
    std::fill(lastSeen, lastSeen + 3, -1); // lastSeen arrays all elements are initilised with -1

    for (int i = 0; i < str.size(); i++)
    {
        lastSeen[str[i] - 'a'] = i;
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            res = res + (1 + std::min(lastSeen[0], std::min(lastSeen[1], lastSeen[2])));
    }

    delete[] lastSeen;
    return res;
}
int main(int argc, char const *argv[])
{
    std::string str = "bbacba";

    std::cout << total_substr_with_three_chars(str);
    return 0;
}
