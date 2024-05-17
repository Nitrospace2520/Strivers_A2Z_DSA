/**
 * @file 09_is_power_of_two.cpp
 * @author Nirmalya Dhara
 * @brief check if a number is power of two or not
 * @date 2024-04-14
 */
#include <bits/stdc++.h>

/**
 * Check if a given number is a power of two.
 *
 * @param n The number to be checked.
 * @return True if the number is a power of two, false otherwise.
 *
 * @note This function uses an optimized approach using bitwise operations.
 *       It checks if a number is a power of two by verifying if it has only one set bit.
 *       If n is a power of two, then n & (n-1) will be 0.
 *       The time complexity of this function is O(1).
 */
bool isPowerOfTwo(int n)
{
    /* //? Brute-force approach: O(logN)
    ///$ check if the number is power of two by dividing the number by 2 until it becomes 1
    if (n == 0)
        return false;
    while (n != 1)
    {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }
    return true; */

    /* //? Optimized approach: O(1) using math library
    return log2(n) == floor(log2(n));
     */

    //? Optimized approach: O(1) using bitwise operation
    ///$ if a number is power of two then it has only one set bit. if n is power of two then n & (n-1) will be 0
    return !(n & (n - 1));
}
int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "Number " << n << " is " << (isPowerOfTwo(n) ? "" : "not ") << "power of two." << std::endl;
    return 0;
}