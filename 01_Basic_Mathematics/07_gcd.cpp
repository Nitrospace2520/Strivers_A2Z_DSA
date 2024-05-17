/**
 * @file 07_gcd.cpp
 * @author Nirmalya Dhara
 * @brief Calculate the Greatest Common Divisor (GCD) of two numbers
 * @date 2024-04-01
 */
#include <bits/stdc++.h>

/**
 * Calculates the greatest common divisor (GCD) of two numbers using the Euclidean algorithm.
 *
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The GCD of num1 and num2.
 *
 * @note This function assumes that both num1 and num2 are non-negative integers.
 * @note The GCD is the largest positive integer that divides both num1 and num2 without leaving a remainder.
 * @note The function uses recursion to repeatedly calculate the remainder of num1 divided by num2 until num2 becomes 0.
 * @note The time complexity of this function is O(log(min(num1, num2))).
 */
int find_gcd(int num1, int num2)
{
    /* //? Brute force approach: Check all numbers from 1 to min(num1, num2) and return the largest number that divides both num1 and num2. Time complexity: O(min(num1, num2))
    int gcd = std::min(num1, num2);
    while (gcd > 0)
    {
        if (num1 % gcd == 0 && num2 % gcd == 0)
        {
            return gcd;
        }
        gcd--;
    }
    return 1; */

    //? Optimal Approach: Euclidean algorithm: Calculate the remainder of num1 divided by num2. Then set num1 = num2 and num2 = remainder. Repeat this process until num2 becomes 0. which is much faster than the brute force approach. This is a recursive implementation of the Euclidean algorithm. Time complexity: O(log(min(num1, num2)))
    if (num2 == 0)
    {
        return num1;
    }
    return find_gcd(num2, num1 % num2);
}
int main()
{
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    int gcd = find_gcd(num1, num2);
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd << std::endl;
    return 0;
}