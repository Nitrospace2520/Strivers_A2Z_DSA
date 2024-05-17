/**
 * @file 09_find_power_exponent.cpp
 * @author Nirmalya Dhara
 * @brief find the power of the given integer
 * @date 2024-04-02
 */

#include <bits/stdc++.h>

/**
 * Calculates the power of a number raised to an exponent.
 *
 * @param n The base number.
 * @param x The exponent value.
 * @return The result of n raised to the power of x.
 *
 * @note This function uses an optimal approach with a time complexity of O(log2(X)).
 *       It handles both positive and negative exponents.
 */
double findExponentPower(int n, int x)
{
    /* //? Brute Force Approach: Time Complexity: O(X) // X => exponent value
    double res = 1;
    for (int i = 0; i < x; i++)
    {
        res = res * n;
    }
    return res; */

    //? Optimal Approach: Time Complexity: O(log2(X))
    bool flag = x < 0 ? true : false; // if x is negative
    x = (int)std::abs(x);
    double res = 1;
    while (x > 0)
    {
        if (x & 1) // if x is even
        {
            res *= n;
            x = x - 1;
        }
        else
        {
            n *= n;
            x = x / 2;
        }
    }
    if (flag)
        res = 1.0 / res;
    return res;
}
int main()
{
    int n, x;
    std::cout << "Enter number and the exponential value : ";
    std::cin >> n >> x;

    std::cout << findExponentPower(n, x) << std::endl;
    return 0;
}