/**
 * @file 17_minimum_no_days_to_make_m_bouquets.cpp
 * @author Nirmalya Dhara
 * @brief find the minimum number of days to make m bouquets with n flowers of different days
 * @date 2024-05-30
 */

#include <bits/stdc++.h>

int find_peak_element(int nums[], int n)
{
}
int main()
{
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    int nums[n];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    std::cout << "The peak element in the array is: " << find_peak_element(nums, n) << std::endl;
    return 0;
}
