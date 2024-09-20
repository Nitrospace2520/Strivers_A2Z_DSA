/**
 * @file 12_maximum_consecutive_ones.cpp
 * @author Nirmalya Dhara
 * @brief find the maximum consecutive ones in an array
 * @date 2024-01-05
 */
#include <bits/stdc++.h>

int find_max_consecutive_ones(const std::vector<int> &arr)
{
    int res = 0, count = 0;
    for (auto ele : arr)
    {
        if (ele != 1)
        {
            res = std::max(res, count);
            count = 0;
        }
        else
            count++;
    }
    return res;
}
int main()
{
    std::vector<int> arr{1, 1, 1, 0, 1, 1, 0, 1};
    std::cout << find_max_consecutive_ones(arr);
    return 0;
}