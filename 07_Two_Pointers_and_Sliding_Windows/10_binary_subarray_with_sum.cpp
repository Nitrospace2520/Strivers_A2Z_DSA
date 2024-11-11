/**
 * @file 10_binary_subarray_with_sum.cpp
 * @author Nirmalya Dhara
 * @brief find the number of subarray with a given sum in binary array
 * @date 2024-11-12
 */
#include <iostream>
#include <unordered_map>

/**
 * Calculates the number of subarrays with a sum less than or equal to the target.
 *
 * This function iterates over a binary array and uses a sliding window approach
 * to find all subarrays whose sum is less than or equal to the given target.
 *
 * @param binary An array of binary integers (0s and 1s).
 * @param n The size of the binary array.
 * @param target The target sum for the subarrays.
 * @return The count of subarrays with a sum less than or equal to the target.
 */
int find_less_than_goal(int binary[], int n, int target)
{
    if (target < 0)
        return 0;

    int start = 0, end = 0;
    int sum = 0, res = 0;

    while (end < n)
    {
        sum += binary[end];
        while (sum > target)
        {
            sum -= binary[start];
            start++;
        }
        res += (end - start + 1);
        end++;
    }
    return res;
}

/**
 * Calculates the total number of subarrays within a binary array that sum up to a given target.
 *
 * This function uses an optimal approach with a time complexity of O(N) and a space complexity of O(1).
 * It leverages the helper function `find_less_than_goal` to determine the count of subarrays with sums
 * less than or equal to the target and the target minus one, and returns their difference.
 *
 * @param binary An array of binary integers (0s and 1s).
 * @param n The size of the binary array.
 * @param target The target sum for the subarrays.
 * @return The total number of subarrays whose sum equals the target.
 */
int find_total_binary_subarray_with_sum(int binary[], int n, int target)
{
    /* //?> Better Approach:= Time complexity: O(N) and Space Complexity: O(N)
    std::unordered_map<int, int> map;
    int total_subarray = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += binary[i];
        if (sum == target)
            total_subarray++;

        int rem = sum - target;
        if (map.find(rem) != map.end())
            total_subarray += map[rem];

        map[sum]++;
    }

    return total_subarray; */

    //?> Optimal Approach:= Time Complexity: O(N) and Space Complexity: O(1)
    return (find_less_than_goal(binary, n, target) - find_less_than_goal(binary, n, target - 1));
}

int main(int argc, char const *argv[])
{
    int binary_arr[] = {1, 0, 1, 0, 1, 0};
    int n = sizeof(binary_arr) / sizeof(binary_arr[0]);
    int target = 2;

    std::cout << find_total_binary_subarray_with_sum(binary_arr, n, target) << std::endl;
    return 0;
}
