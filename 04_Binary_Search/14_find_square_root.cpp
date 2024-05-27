/**
 * @file 14_find_square_root.cpp
 * @author Nirmalya Dhara
 * @brief find the square root of a number without using any built-in functions
 * @date 2024-05-27
 */

#include <bits/stdc++.h>

/**
 * @brief Find the square root of a number without using any built-in functions.
 *
 * This function implements an optimal approach using Binary Search to find the square root of a given number.
 *
 * @param num The number for which the square root needs to be found.
 * @return int The square root of the given number.
 */
int find_sqrt(int num)
{
    /* //?> Brute force approach: Time Complexity: O(sqrt(N)) and Space Complexity: O(1)
    if (num == 0 || num == 1)
        return num;

    int ans = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (i * i <= num)
            ans = i;
        else
            break;
    }
    return ans; */

    //?> Optimal Approach (by using Binary Search): Time Complexity: O(log(N)) and Space Complexity: O(1)
    if (num == 0 || num == 1)
        return num;

    int low = 1, high = num / 2, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long int square = mid * mid;

        if (square == num)
            return mid;
        else if (square < num)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int n;
    std::cout << "Enter the number: ";
    std::cin >> n;

    std::cout << "The square root of " << n << " is : " << find_sqrt(n) << std::endl;
    return 0;
}
