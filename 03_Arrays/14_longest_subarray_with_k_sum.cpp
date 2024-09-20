/**
 * @file 14_longest_subarray_with_k_sum.cpp
 * @author Nirmalya Dhara
 * @brief find the length of the longest subarray of an array whose sum = k
 * @date 2024-01-09
 */
#include <bits/stdc++.h>

int longest_subarray_with_k_sum(std::vector<int> &array, int &k)
{
    /* // ! Brute-Force Approach: T.C: O(N*N), S.C: O(1)
    int res = 0;
    for (int i = 0; i < array.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < array.size(); j++)
        {
            sum += array[j];
            if (sum == k)
                res = std::max(res, j - i + 1);
            else if (sum > k)
                break;
        }
    }
    return res; */

    /* // ! Better Approach: T.C: O(N), S.C: O(N) // NOTE: it will work for both positive & negative numbers.
    std::unordered_map<int, int> map;
    int sum = 0, length = 0;
    for (int i = 0; i < array.size(); i++)
    {
        sum += array[i];
        if (sum == k)
            length = std::max(length, i + 1);
        auto it = map.find((sum - k)); // finding the remaining
        if (it != map.end())
            length = std::max(length, (i - it->second));
        else
            map.insert({sum, i});
    }
    return length; */

    // ! Optimal Solution: T.C: O(), S.C: // NOTE: it will only work for zeros and positive numbers.
    /* int start = 0, end = 0, resLen = 0, sum = 0; //! ERROR
    while (end < array.size())
    {
        if (sum == k)
        {
            resLen = std::max(resLen, (end - start));
            end++;
            sum += array[end];
        }
        else if (sum > k)
        {
            sum -= array[start];
            start++;
        }
        else
        {
            sum += array[end];
            end++;
        }
    }
    return resLen; */
    int start = 0, end = 0, resLen = 0, sum = array[0];
    while (end < array.size())
    {
        while (start <= end && sum > k)
        {
            sum -= array[start];
            start++;
        }
        if (sum == k)
        {
            resLen = std::max(resLen, (end - start + 1));
        }
        end++;
        if (end < array.size())
            sum += array[end];
    }
    return resLen;
}

int main()
{
    std::vector<int> array{2, 0, 1, 0, 5};
    int k = 3;
    std::cout << longest_subarray_with_k_sum(array, k);
    return 0;
}