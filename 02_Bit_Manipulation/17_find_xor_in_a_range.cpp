/**
 * @file 17_find_xor_in_a_range.cpp
 * @author Nirmalya Dhara
 * @brief find the xor of number between a range
 * @date 2024-04-18
 */
#include <bits/stdc++.h>

/**
 * @brief Find the XOR of numbers up to a given number.
 *
 * This function calculates the XOR of all the numbers from 0 up to the given number 'n'.
 * It uses a mathematical approach based on the modulo operation to calculate the XOR in constant time and space complexity.
 *
 * @param n The given number.
 * @return The XOR of all the numbers from 0 up to 'n'.
 *
 * @note The function assumes that 'n' is a non-negative integer.
 * @note The function uses the modulo operation to determine the XOR value based on the remainder of 'n' divided by 4.
 *       - If 'n' is divisible by 4, the XOR value is 'n'.
 *       - If the remainder of 'n' divided by 4 is 1, the XOR value is 1.
 *       - If the remainder of 'n' divided by 4 is 2, the XOR value is 'n + 1'.
 *       - If the remainder of 'n' divided by 4 is 3, the XOR value is 0.
 *
 * @see findXorInaRange
 */
int findXorUptoN(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

/**
 * @brief Find the XOR of numbers in a given range.
 *
 * This function calculates the XOR of all the numbers in the range [left, right].
 * It uses an optimal approach based on bit manipulation to calculate the XOR in constant time and space complexity.
 *
 * @param left The left end of the range.
 * @param right The right end of the range.
 * @return The XOR of all the numbers in the range [left, right].
 *
 * @note The function assumes that left <= right.
 * @note The function assumes that the range [left, right] is inclusive.
 * @note The function uses the helper function findXorUptoN to calculate the XOR of individual numbers.
 *
 * @see findXorUptoN
 */
int findXorInaRange(int left, int right)
{
    /* // ? Brute Force Approach: Time Complexity: O(R-L), Space Complexity: O(1)
    int res = 0;
    for (int i = left; i <= right; i++)
        res = res ^ i;
    return res; */

    // ? Optimal Approach: (using bit manipulation), Time Complexity: O(1) and Space Complexity: O(1)
    return findXorUptoN(left) ^ findXorUptoN(right);
}
int main()
{
    int left, right;
    std::cout << "Enter the range [L R]:";
    std::cin >> left >> right;

    std::cout << "The xor between " << left << " and " << right << " is: " << findXorInaRange(left, right) << std::endl;
    return 0;
}