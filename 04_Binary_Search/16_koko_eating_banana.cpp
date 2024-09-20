/**
 * @file 16_koko_eating_banana.cpp
 * @author Nirmalya Dhara
 * @brief koko eating banana problem:= problem is to find the minimum integer value of k such that koko can eat all the bananas within H hours.
 * @date 2024-05-30
 */

#include <bits/stdc++.h>

/**
 * @brief Calculate the total hours required to eat all the bananas based on the given array of banana bunches and the eating speed.
 *
 * This function calculates the total hours required for Koko to eat all the bananas in the given array of banana bunches,
 * considering the eating speed 'k'. If the number of bananas in a bunch is perfectly divisible by 'k', Koko takes
 * 'nums[i] / k' hours to eat that bunch; otherwise, Koko takes 'nums[i] / k + 1' hours to eat the remaining bananas.
 *
 * @param nums An array of integers representing the number of bananas in each bunch.
 * @param n The size of the array 'nums'.
 * @param k The eating speed of Koko.
 * @return The total hours required for Koko to eat all the bananas in the array.
 */
int count_hours(int nums[], int n, int k)
{
    int hours = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % k == 0)
            hours += nums[i] / k;
        else
            hours += nums[i] / k + 1;
    }
    return hours;
}

/**
 * @brief Find the minimum number of bananas Koko can eat within a given total hours using binary search approach.
 *
 * This function calculates the minimum number of bananas that Koko can eat within a given total hours by performing a binary search on the eating speed.
 * It iterates through the possible eating speeds to find the maximum speed at which Koko can eat all the bananas within the total hours.
 *
 * @param nums An array of integers representing the number of bananas in each bunch.
 * @param n The size of the array 'nums'.
 * @param total_hours The total hours within which Koko needs to eat all the bananas.
 * @return The minimum eating speed at which Koko can eat all the bananas within the given total hours.
 */
int find_minimum_eaten_banana(int nums[], int n, int total_hours)
{
    /* //?> Brute Force Approach: Time complexity: O(Max_Element * N), Space complexity: O(1)
    int min_banana = 1;
    int max_banana = *std::max_element(nums, nums + n);
    while (min_banana <= max_banana)
    {
        int hours = count_hours(nums, n, min_banana);
        if (hours > total_hours)
            min_banana += 1;
        else
            break;
    }
    return min_banana; */

    //?> Binary Search Approach: Time complexity: O(log(max_element) * N), Space complexity: O(1)
    int start = 1, end = *std::max_element(nums, nums + n);
    int ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int hours = count_hours(nums, n, mid);
        if (hours <= total_hours)
        {
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
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

    int total_hours;
    std::cout << "Enter the total hours: ";
    std::cin >> total_hours;

    std::cout << "Minimum number of banana Koko can eat is : " << find_minimum_eaten_banana(nums, n, total_hours) << std::endl;
    return 0;
}
