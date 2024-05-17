/**
 * @file 16_find_xor_upto_n.cpp
 * @author Nirmalya Dhara
 * @brief find the xor of numbers from 1 to n where n is the given range
 * @date 2024-04-18
 */

#include <bits/stdc++.h>

/**
 * @brief Find the XOR of numbers from 1 to n.
 *
 * This function takes an integer n as input and returns the XOR of all numbers from 1 to n.
 *
 * @param n The range of numbers.
 * @return The XOR of numbers from 1 to n.
 *
 * @note The function uses an optimal approach to calculate the XOR.
 *       The time complexity of the function is O(1) and the space complexity is O(1).
 *       The function uses the following formula to calculate the XOR:
 *       - If n % 4 == 0, the XOR is n.
 *       - If n % 4 == 1, the XOR is 1.
 *       - If n % 4 == 2, the XOR is n + 1.
 *       - If n % 4 == 3, the XOR is 0.
 */
int findXor(int n)
{
    /* // ? Brute Force Approach: Time:O(N), Space: O(1)
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = res ^ i;
    return res; */

    // ? Optimal Approach: Time: O(1) and Space: O(1)
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}
int main()
{
    int n;
    std::cout << "Enter the range: ";
    std::cin >> n;

    std::cout << "The xor from 1 to n will be : " << findXor(n) << std::endl;
    return 0;
}
/* NOTE:-

1 -> 1
2 -> 3
3 -> 0
4 -> 4

5 -> 1
6 -> 7
7 -> 0
8 -> 8

9 -> 1
10 -> 11
11 -> 0
12 -> 12

and so on ...
*/