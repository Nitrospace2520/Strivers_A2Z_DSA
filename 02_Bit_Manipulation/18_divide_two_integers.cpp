/**
 * @file 18_divide_two_integers.cpp
 * @author Nirmalya Dhara
 * @brief divide two integers without using multiplication and division operators. If overflow then return INT_MAX or INT_MIN for the different cases
 * @date 2024-04-18
 */

#include <bits/stdc++.h>

/**
 * @brief Divide two integers without using multiplication and division operators.
 *        If overflow occurs, return INT_MAX or INT_MIN for different cases.
 * @param divident The dividend
 * @param divisor The divisor
 * @return The quotient of the division
 */
int getQuotient(int divident, int divisor)
{
    /* // ? Brute Force Approach: Time Complexity: O(divident), Space Complexity: O(1)
    if (divisor == 0)
        return NAN;
    int flag = false;
    if (divident < 0)
        flag = !flag;
    if (divisor < 0)
        flag = !flag;
    divident = abs(divident);
    divisor = abs(divisor);

    int sum = 0, count = 0;
    while ((sum + divisor) <= divident)
    {
        count++;
        sum += divisor;
    }
    return flag ? 0 - count : count; */

    // ? Better Approach: Time Complexity: O(logN^2), Space Complexity: O(1)
    if (divisor == 0)
        return (int)(INFINITY);

    int flag = false;
    if (divident < 0)
        flag = !flag;
    if (divisor < 0)
        flag = !flag;
    divident = abs(divident);
    divisor = abs(divisor);

    int count = 0, powOfTwo = 1;
    while (divident >= divisor)
    {
        if (divisor * (powOfTwo << 1) > divident)
        {
            count += 1;
            powOfTwo = 1;
            divident = divident - (divisor * powOfTwo);
        }
        else
            powOfTwo = powOfTwo << 1;
    }

    return flag ? (0 - count) : count;
}
int main()
{
    int divident, divisor;
    std::cout << "Enter divident and divisor: ";
    std::cin >> divident >> divisor;

    std::cout << "The quotient is : " << getQuotient(divident, divisor) << std::endl;
    return 0;
}