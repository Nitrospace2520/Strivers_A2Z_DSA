/**
 * @file 11_count_total_nice_subarray.cpp
 * @author Nirmalya Dhara
 * @brief find the total number of nice subarray. A nice subarray is a subarray with exactly k odd numbers.
 * @date 2024-11-12
 */
#include <iostream>
#include <unordered_map>

/**
 * Finds the number of subarrays with an odd sum less than or equal to the target.
 *
 * This function iterates through the array using a sliding window approach,
 * maintaining a count of odd numbers in the current window. It adjusts the
 * window size to ensure the sum of odd numbers does not exceed the target,
 * and counts all valid subarrays.
 *
 * @param nums An array of integers.
 * @param n The size of the array.
 * @param target The maximum allowed sum of odd numbers in a subarray.
 * @return The count of subarrays with an odd sum less than or equal to the target.
 */
int find_less_than_goal(int nums[], int n, int target)
{
    if (target < 0)
        return 0;

    int start = 0, end = 0;
    int sum = 0, res = 0;

    while (end < n)
    {
        sum += (nums[end] % 2);
        while (sum > target)
        {
            sum -= (nums[start] % 2);
            start++;
        }
        res += (end - start + 1);
        end++;
    }
    return res;
}

/**
 * Counts the total number of "nice" subarrays within the given array.
 * A "nice" subarray is defined as a contiguous subarray containing exactly k odd numbers.
 *
 * This function uses an optimal approach with a time complexity of O(N) and space complexity of O(1),
 * leveraging the helper function `find_less_than_goal` to calculate the result.
 *
 * @param nums An array of integers.
 * @param n The size of the array.
 * @param k The exact number of odd numbers required in a subarray to be considered "nice".
 * @return The total count of "nice" subarrays.
 */
int count_total_nice_subarray(int nums[], int n, int k)
{
    /* // ?>  Brute-Force Approach:= Time Complexity: O(N*N), Space Complexity: O(1)
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int odds = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[j] % 2 != 0)
                odds++;
            if (odds == k)
                res++;
            else if (odds > k)
                break;
        }
    }
    return res; */

    // ?> Optimal Approach:= Time Complexity: O(N), Space Complexity: O(1)
    // int res = 0, odds = 0;
    // int start = 0, end = 0;
    // while (end < n)
    // {
    //     if (nums[end] % 2 != 0)
    //         odds++;
    //     while (odds > k)
    //     {
    //         if (nums[start] % 2 != 0)
    //             odds--;
    //         start++;
    //     }
    //     if (odds == k)
    //         res++;
    //     end++;
    // }
    // return res;
    // *> Method: 02
    return (find_less_than_goal(nums, n, k) - find_less_than_goal(nums, n, k - 1));
}
int main(int argc, char const *argv[])
{
    int nums[] = {1, 1, 2, 1, 0, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    std::cout << count_total_nice_subarray(nums, n, k) << std::endl;
    return 0;
}
